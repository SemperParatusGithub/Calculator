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
		ImGui::Text("Hier sind die Settings");
		ImGui::Text("Hier sind die Settings");
		ImGui::Text("Hier sind die Settings");
		ImGui::Text("Hier sind die Settings");
		ImGui::Text("Hier sind die Settings");
	}
};
