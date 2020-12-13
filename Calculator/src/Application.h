#pragma once
#include <memory>
#include <unordered_map>

#include "MenuItems/MenuBar.h"

#include "Util/Window.h"
#include "Util/ImGuiUtil.h"
#include "Util/TextureLoader.h"
#include "Util/Time.h"


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
	MenuBar m_MenuBar;

	bool showDemoWindow = false;
	bool consoleOpen = false;
};
