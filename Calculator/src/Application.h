#pragma once
#include <memory>
#include <unordered_map>

#include "MenuItems/Vectors.h"

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
	void Update();

	friend int ::main(int argc, char *argv[]);

private:
	std::unique_ptr<Util::Window> m_Window;
	std::unordered_map<std::string, std::shared_ptr<MenuItem>> m_MenuItems;

	bool generalOpen = false;
	bool settingsOpen = false;
	bool vectorsOpen = false;

	bool showDemoWindow = false;
	bool consoleOpen = false;

	unsigned int calculatorIcon = 0;
	unsigned int settingsIcon = 0;
	unsigned int vectorsIcon = 0;
};
