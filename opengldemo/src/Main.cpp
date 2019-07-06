#include "pch.h"
#include "Application.h"
#include "Logger.h"

int main()
{
	Demo::Logger::SetGlobalLevel(Demo::LogLevel::Trace);
	Demo::Logger::GlobalInfo("Start");

	Demo::Application* application = new Demo::Application();
	application->Run();
	delete application;

	Demo::Logger::GlobalInfo("Finish");
	std::cin.get();
}