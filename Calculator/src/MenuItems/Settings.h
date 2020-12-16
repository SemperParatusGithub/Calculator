#pragma once
#include "MenuItem.h"
#include "Util/TextureLoader.h"

class Settings : public MenuItem
{
public:
	Settings()
	{
		m_IconID = Util::LoadTexture("res/Icons/SettingsIcon.png");
	}	
	~Settings()
	{
	}

	virtual void OnContentRender() override
	{
		ImGui::Text("Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut");
		ImGui::Text("labore et dolore magna aliquyam erat, sed diam voluptua.At vero eos et accusam et justo duo dolores");
		ImGui::Text("et ea rebum.Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet");
	}
};
