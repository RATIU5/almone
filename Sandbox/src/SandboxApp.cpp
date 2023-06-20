
#include <Almone.h>

class Sandbox : public Almone::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}



};

Almone::Application* Almone::CreateApplication()
{
	return new Sandbox();
}