#include "pch.h"
#include "Application.h"
#include "Log.h"

Demo::Application::Application()
{
	Demo::Log::Init();
	LOG_INFO("Creating application!");
}

Demo::Application::~Application()
{
	LOG_INFO("Destroying application!");
}

void Demo::Application::Run()
{
	LOG_INFO("Running application!");
	std::cin.get();
}
