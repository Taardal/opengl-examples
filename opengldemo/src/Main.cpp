#include "pch.h"
#include "Application.h"
#include "Log.h"

int main()
{
	Demo::Log::SetLevel(Demo::LogLevel::Trace);
	Demo::Application* application = new Demo::Application();
	application->Run();
	delete application;
	std::cin.get();
}