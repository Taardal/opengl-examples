#include "pch.h"
#include "Application.h"
#include "layers/TriangleLayer.h"
#include "layers/TextureLayer.h"
#include "layers/Texture3DLayer.h"
#include "layers/TexturedCubeLayer.h"

using namespace Demo;

int main()
{
	Log::SetLevel(LogLevel::Trace);
	Application* application = new Application();
	application->PushLayer(new TriangleLayer());
	//application->PushLayer(new TextureLayer());
	//application->PushLayer(new Texture3DLayer());
	//application->PushLayer(new TexturedCubeLayer());
	application->Run();
	delete application;
	std::cin.get();
}