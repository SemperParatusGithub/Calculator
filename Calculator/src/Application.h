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

	void InitImGui();
	void UpdateImGui();

	friend int ::main(int argc, char *argv[]);

private:
	std::unique_ptr<Util::Window> m_Window;

	ImFont *m_TitleFont = nullptr;

	bool windowOpen = true;
	int selected = 1;

	float vec1[3] = { 0, 0, 0 };
	float vec2[3] = { 0, 0, 0 };
};
