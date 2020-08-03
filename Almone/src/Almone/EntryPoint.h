#pragma once

#ifdef ALM_PLATFORM_WINDOWS

// somewhere something returns an Almone Application
extern Almone::Application* Almone::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Almone::CreateApplication();
	app->Run();
	delete app;
}

#endif