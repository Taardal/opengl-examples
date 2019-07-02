#include "pch.h"
#include "Application.h"

int main()
{
	Demo::Application* application = new Demo::Application();
	application->Run();
	delete application;
}