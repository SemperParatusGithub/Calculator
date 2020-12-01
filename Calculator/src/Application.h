#pragma once
#include <memory>

#include "Util/Window.h"
#include "Util/ImGuiUtil.h"
#include "Util/TextureLoader.h"

int main(int argc, char *argv[]);

class Application
{
private:
	Application(const std::string &title, uint32_t width, uint32_t height);
	~Application();

private:
	void Run();

	void UpdateImGui();
	void DrawConsole();

	friend int ::main(int argc, char *argv[]);

private:
	std::unique_ptr<Util::Window> m_Window;

	ImFont *m_TitleFont = nullptr;
	ImFont *OpenSansBold;

	bool temp = false;

	bool windowOpen = true;
	int selected = 1;

	float vec1[3] = { 0, 0, 0 };
	float vec2[3] = { 0, 0, 0 };

	bool generalOpen = false;
	bool settingsOpen = false;
	bool vectorsOpen = false;

	bool enable_7m = false;  // default value, the button is disabled 
	float b = 1.0f; //  test whatever color you need from imgui_demo.cpp e.g.
	float c = 0.5f; // 
	int i = 3;

	bool demoWindow = false;

	unsigned int calculatorIcon = 0;
	unsigned int settingsIcon = 0;
	unsigned int vectorsIcon = 0;
};
