#include "pch.h"
#include "Application.h"
#include "layers/TriangleLayer.h"
#include "layers/TextureLayer.h"
#include "layers/ModelViewProjectionLayer.h"
#include "layers/DepthAndStencilBufferLayer.h"

using namespace Demo;

int main()
{
	Log::SetLevel(LogLevel::Trace);
	Application* application = new Application();
	application->PushLayer(new TriangleLayer());
	//application->PushLayer(new TextureLayer());
	//application->PushLayer(new ModelViewProjectionLayer());
	//application->PushLayer(new DepthAndStencilBufferLayer());
	application->Run();
	delete application;
	std::cin.get();
}