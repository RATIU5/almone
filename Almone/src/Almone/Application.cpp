#include "Application.h"

#include "Almone/Event/ApplocationEvent.h"
#include "Almone/Log.h"


namespace Almone {

	Application::Application()
	{

	}

	Application::~Application()
	{

	}


	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			ALM_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			ALM_TRACE(e);
		}


		while (true);
	}

}