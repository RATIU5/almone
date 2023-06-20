#pragma once

#include "Core.h"
#include "Event/Event.h"

namespace Almone {

	class ALM_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined by the client
	Application* CreateApplication();

}

