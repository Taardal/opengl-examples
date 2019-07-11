#include "pch.h"
#include "Application.h"

using namespace Demo;

int main()
{
	Log::SetLevel(LogLevel::Trace);
	Application* application = new Application();
	application->Run();
	delete application;
	std::cin.get();
}