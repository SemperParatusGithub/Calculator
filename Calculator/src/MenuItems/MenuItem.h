#pragma once
#include <iostream>
#include <glm/glm.hpp>
#include <imgui.h>


class MenuItem
{
public:
	MenuItem() :  m_WindowSize({100.0f, 100.0f})
	{
		m_OpenSans = ImGui::GetIO().Fonts->AddFontFromFileTTF("res/fonts/OpenSans/OpenSans-Regular.ttf", 32.0f);
		OpenSansBold = ImGui::GetIO().Fonts->AddFontFromFileTTF("res/fonts/OpenSans/OpenSans-Bold.ttf", 32.0f);
		ImGui::GetIO().FontDefault = m_OpenSans;
	}
	virtual ~MenuItem() = default;

	virtual void OnUpdate(const glm::vec2 &windowSize) { m_WindowSize = windowSize; }
	virtual void OnRender() = 0;

protected:
	ImFont *m_OpenSans = nullptr;
	ImFont *OpenSansBold = nullptr;

	glm::vec2 m_WindowSize;
};