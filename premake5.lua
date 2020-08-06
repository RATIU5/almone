workspace "Almone"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}


outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Almone"
	location "Almone"
	kind "SharedLib" -- dynamic dll file
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir    ("bin-int/" .. outputdir .. "/%{prj.name}")

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"ALM_PLATFORM_WINDOWS",
			"ALM_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "ALM_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "ALM_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "ALM_DIST"
		optimize "On"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir    ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Almone/vendor/spdlog/include",
		"Almone/src"
	}

	links
	{
		"Almone"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"ALM_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "ALM_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "ALM_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "ALM_DIST"
		optimize "On"