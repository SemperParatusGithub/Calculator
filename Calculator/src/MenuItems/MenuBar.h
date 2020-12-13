#pragma once
#include "MenuItem.h"

#include <vector>
#include <functional>


class MenuBar
{
public:
	MenuBar()
	{
	}
	~MenuBar()
	{
	}

	void OnUpdate(const glm::vec2 &windowSize)
	{
		for (auto &MenuItem : m_MenuItems)
			MenuItem.second->OnUpdate(windowSize);
	}
	void OnRender()
	{
		ImGui::PushStyleVar(ImGuiStyleVar_FrameBorderSize, 1.0f);
		ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 50.0f);
		for (auto &MenuItem : m_MenuItems)
		{
			if (MenuItem.second->IsOpen())
			{
				ImGui::PushStyleColor(ImGuiCol_Button, ImVec4 { 0.3f, 0.305f, 0.31f, 1.0f });
				ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4 { 0.15f, 0.1505f, 0.151f, 1.0f });
				ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4 { 0.3f, 0.305f, 0.31f, 1.0f });

				// Close if Button is pressed again
				if (ImGui::ImageButton((ImTextureID) MenuItem.second->GetIcon(), { 50.0f, 50.0f }, ImVec2 { 0, 1 }, ImVec2 { 1, 0 }))
					MenuItem.second->Close();

				ImGui::PopStyleColor(3);
			}
			else {
				if (ImGui::ImageButton((ImTextureID) MenuItem.second->GetIcon(), { 50.0f, 50.0f }, ImVec2 { 0, 1 }, ImVec2 { 1, 0 }))
				{
					// Open Current Menu Item
					MenuItem.second->Open();

					// Close all other Menu Items
					for (auto &m : m_MenuItems)
						if (m.first != MenuItem.first)
							m.second->Close();
				}
			}
		}
		ImGui::PopStyleVar(2);
	}

	void OnItemContentRender()
	{
		for (auto &[name, item] : m_MenuItems)
			if (item->IsOpen())
				item->OnRender();
	}

	template<typename ItemType>
	void RegisterMenuItem(const std::string &name)
	{
		std::cout << "Registering Test" << name << std::endl;
		m_MenuItems.push_back(std::make_pair(name, std::make_shared<ItemType>()));
	}

private:
	std::vector<std::pair<std::string, std::shared_ptr<MenuItem>>> m_MenuItems;
};