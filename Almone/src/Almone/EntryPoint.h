#pragma once

#ifdef ALM_PLATFORM_WINDOWS

// somewhere something returns an Almone Application
extern Almone::Application* Almone::CreateApplication();

int main(int argc, char** argv)
{
	Almone::Log::Init();

	auto app = Almone::CreateApplication();
	app->Run();
	delete app;
}

#endif