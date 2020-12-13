#include "Vectors.h"
#include "Util/TextureLoader.h"


Vectors::Vectors()
{
	m_OpenSansRegular = ImGui::GetIO().Fonts->AddFontFromFileTTF("res/fonts/OpenSans/OpenSans-Regular.ttf", 32.0f);
	m_OpenSansBold = ImGui::GetIO().Fonts->AddFontFromFileTTF("res/fonts/OpenSans/OpenSans-Bold.ttf", 32.0f);

	m_IconID = Util::LoadTexture("res/Icons/VectorsIcon.png");
}

Vectors::~Vectors()
{
}

void Vectors::OnContentRender()
{
	ImVec2 buttonSize = ImVec2 { m_WindowSize.x / 35, 0.0f };

	ImGui::Text(" Vector 1: ");  ImGui::SameLine(m_WindowSize.x / 3.5);
	ImGui::Text(" Vector 2: ");

	ImGui::SetNextItemWidth(m_WindowSize.x / 4); ImGui::DragFloat("##vec11", &vec1[0], 0.1f, 0.0f, 0.0f, "%.3f"); ImGui::SameLine(m_WindowSize.x / 4);
	ImGui::PushStyleColor(ImGuiCol_Button, ImVec4 { 0.8f, 0.1f, 0.15f, 1.0f });
	ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4 { 0.9f, 0.2f, 0.2f, 1.0f });
	ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4 { 0.8f, 0.1f, 0.15f, 1.0f });
	ImGui::PushFont(m_OpenSansBold);
	if (ImGui::Button("x##1", buttonSize)) vec1[0] = 0;
	ImGui::PopFont();
	ImGui::PopStyleColor(3);
	ImGui::SameLine(m_WindowSize.x / 3.5);

	ImGui::SetNextItemWidth(m_WindowSize.x / 4); ImGui::DragFloat("##vec21", &vec2[0], 0.1f, 0.0f, 0.0f, "%.3f"); ImGui::SameLine(m_WindowSize.x / 1.867);
	ImGui::PushStyleColor(ImGuiCol_Button, ImVec4 { 0.8f, 0.1f, 0.15f, 1.0f });
	ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4 { 0.9f, 0.2f, 0.2f, 1.0f });
	ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4 { 0.8f, 0.1f, 0.15f, 1.0f });
	ImGui::PushFont(m_OpenSansBold);
	if (ImGui::Button("x##2", buttonSize)) vec2[0] = 0;
	ImGui::PopFont();
	ImGui::PopStyleColor(3);

	ImGui::SetNextItemWidth(m_WindowSize.x / 4); ImGui::DragFloat("##vec12", &vec1[1], 0.1f, 0.0f, 0.0f, "%.3f"); ImGui::SameLine(m_WindowSize.x / 4);
	ImGui::PushStyleColor(ImGuiCol_Button, ImVec4 { 0.f, 0.4f, 0.05f, 1.0f });
	ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4 { 0.1f, 0.5f, 0.15f, 1.0f });
	ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4 { 0.f, 0.4f, 0.05f, 1.0f });
	ImGui::PushFont(m_OpenSansBold);
	if (ImGui::Button("y##1", buttonSize))  vec1[1] = 0;
	ImGui::PopFont();
	ImGui::PopStyleColor(3);
	ImGui::SameLine(m_WindowSize.x / 3.5);

	ImGui::SetNextItemWidth(m_WindowSize.x / 4); ImGui::DragFloat("##vec22", &vec2[1], 0.1f, 0.0f, 0.0f, "%.3f"); ImGui::SameLine(m_WindowSize.x / 1.867);
	ImGui::PushStyleColor(ImGuiCol_Button, ImVec4 { 0.f, 0.4f, 0.05f, 1.0f });
	ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4 { 0.1f, 0.5f, 0.15f, 1.0f });
	ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4 { 0.f, 0.4f, 0.05f, 1.0f });
	ImGui::PushFont(m_OpenSansBold);
	if (ImGui::Button("y##2", buttonSize)) vec2[1] = 0;
	ImGui::PopFont();
	ImGui::PopStyleColor(3);

	ImGui::SetNextItemWidth(m_WindowSize.x / 4); ImGui::DragFloat("##vec13", &vec1[2], 0.1f, 0.0f, 0.0f, "%.3f"); ImGui::SameLine(m_WindowSize.x / 4);
	ImGui::PushStyleColor(ImGuiCol_Button, ImVec4 { 0.1f, 0.25f, 0.8f, 1.0f });
	ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4 { 0.2f, 0.35f, 0.9f, 1.0f });
	ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4 { 0.1f, 0.25f, 0.8f, 1.0f });
	ImGui::PushFont(m_OpenSansBold);
	if (ImGui::Button("z##1", buttonSize)) vec1[2] = 0;
	ImGui::PopFont();
	ImGui::PopStyleColor(3);
	ImGui::SameLine(m_WindowSize.x / 3.5);

	ImGui::SetNextItemWidth(m_WindowSize.x / 4); ImGui::DragFloat("##vec23", &vec2[2], 0.1f, 0.0f, 0.0f, "%.3f"); ImGui::SameLine(m_WindowSize.x / 1.867);
	ImGui::PushStyleColor(ImGuiCol_Button, ImVec4 { 0.1f, 0.25f, 0.8f, 1.0f });
	ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4 { 0.2f, 0.35f, 0.9f, 1.0f });
	ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4 { 0.1f, 0.25f, 0.8f, 1.0f });
	ImGui::PushFont(m_OpenSansBold);
	if (ImGui::Button("z##2", buttonSize)) vec2[2] = 0;
	ImGui::PopFont();
	ImGui::PopStyleColor(3);

	float dotProduct = glm::dot(glm::vec3(vec1[0], vec1[1], vec1[2]), glm::vec3(vec2[0], vec2[1], vec2[2]));
	glm::vec3 crossProduct = glm::cross(glm::vec3(vec1[0], vec1[1], vec1[2]), glm::vec3(vec2[0], vec2[1], vec2[2]));
	ImGui::Spacing();
	ImGui::Text("Skalarprodukt: %.3f", dotProduct);
	ImGui::Spacing();
	ImGui::Text("Kreuzprodukt: { %.2f, %.2f, %.2f } = %.3f", crossProduct.x, crossProduct.y, crossProduct.z, glm::length(crossProduct.x));
	ImGui::Spacing();
}