#include "Application.h"


Application::Application(const std::string &title, uint32_t width, uint32_t height)
{
	m_Window = std::make_unique<Util::Window>(width, height, title);
	m_Window->SetIcon("res/Icons/CalculatorIcon.png");

	// Util::Window::HideConsole();

	Util::ImGuiInit(*m_Window);

	ImFont *openSansRegular = ImGui::GetIO().Fonts->AddFontFromFileTTF("res/fonts/OpenSans/OpenSans-Regular.ttf", 28.0f);
	m_TitleFont = ImGui::GetIO().Fonts->AddFontFromFileTTF("res/fonts/OpenSans/OpenSans-Regular.ttf", 32.0f);
	OpenSansBold = ImGui::GetIO().Fonts->AddFontFromFileTTF("res/fonts/OpenSans/OpenSans-Bold.ttf", 32.0f);
	ImGui::GetIO().FontDefault = openSansRegular;

	calculatorIcon = Util::LoadTexture("res/Icons/CalculatorIcon.png");
	settingsIcon = Util::LoadTexture("res/Icons/SettingsIcon.png");
	vectorsIcon = Util::LoadTexture("res/Icons/VectorsIcon.png");
}

Application::~Application()
{
	Util::ImGuiShutdown();
}

void Application::Run()
{
	while (m_Window->isOpen())
	{
		Util::ImGuiBeginFrame();

		m_Window->Update();
		m_Window->Clear();

		UpdateImGui();

		Util::ImGuiEndFrame();
	}
}

void Application::UpdateImGui()
{
	if (!windowOpen)
		m_Window->Close();

	ImGui::SetNextWindowPos(ImVec2 { m_Window->GetPosition().x, m_Window->GetPosition().y });
	ImGui::SetNextWindowSize(ImVec2 { m_Window->GetSize().x, m_Window->GetSize().y });
	ImGui::PushFont(m_TitleFont);

	bool minimized = m_Window->GetSize().x == 0 && m_Window->GetSize().y == 0;

	if (!minimized)
	{
		ImGui::Begin("Semper Calculator", &windowOpen, ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize);
		auto windowSize = ImGui::GetWindowSize();

		if (ImGui::BeginMenuBar())
		{
			if (ImGui::BeginMenu("File"))
			{
				if (ImGui::MenuItem("Open", "CTRL+O"));
				if (ImGui::MenuItem("Save", "CTRL+S"));
				if (ImGui::MenuItem("Save as", "CTRL+Shift+S"));
				if (ImGui::MenuItem("Close"))
					m_Window->Close();
				ImGui::EndMenu();
			}
			if (ImGui::BeginMenu("Settings"))
			{
				if (ImGui::MenuItem("Show DemoWindow", "", &demoWindow, true));
				ImGui::EndMenu();
			}
			if (ImGui::BeginMenu("About"))
				ImGui::EndMenu();
			if (ImGui::BeginMenu("Help"))
			{
				if (ImGui::MenuItem("Open Console", ""))
					DrawConsole();
				ImGui::EndMenu();
			}
			ImGui::EndMenuBar();
		}
		ImGui::BeginChild("VerticalMenu", ImVec2 { 58.0f, 0.0f }, false, ImGuiWindowFlags_NoScrollbar);

		ImGui::PushStyleVar(ImGuiStyleVar_FrameBorderSize, 1.0f);
		ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 50.0f);
		if (generalOpen)
		{
			ImGui::PushStyleColor(ImGuiCol_Button, ImVec4 { 0.3f, 0.305f, 0.31f, 1.0f });
			ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4 { 0.15f, 0.1505f, 0.151f, 1.0f });
			ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4 { 0.3f, 0.305f, 0.31f, 1.0f });
			if (ImGui::ImageButton((ImTextureID) calculatorIcon, { 50.0f, 50.0f }, ImVec2 { 0, 1 }, ImVec2 { 1, 0 }))
				generalOpen = false;
			
			ImGui::PopStyleColor(3);
		}
		else {
			if (ImGui::ImageButton((ImTextureID) calculatorIcon, { 50.0f, 50.0f }, ImVec2 { 0, 1 }, ImVec2 { 1, 0 }))
			{
				generalOpen = true;
				settingsOpen = false;
				vectorsOpen = false;
			}
		}
		if(settingsOpen)
		{
			ImGui::PushStyleColor(ImGuiCol_Button, ImVec4 { 0.3f, 0.305f, 0.31f, 1.0f });
			ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4 { 0.15f, 0.1505f, 0.151f, 1.0f });
			ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4 { 0.3f, 0.305f, 0.31f, 1.0f });
			if (ImGui::ImageButton((ImTextureID) settingsIcon, { 50.0f, 50.0f }, ImVec2 { 0, 1 }, ImVec2 { 1, 0 }))
				settingsOpen = false;
			
			ImGui::PopStyleColor(3);
		}
		else {
			if (ImGui::ImageButton((ImTextureID) settingsIcon, { 50.0f, 50.0f }, ImVec2 { 0, 1 }, ImVec2 { 1, 0 }))
			{
				settingsOpen = true;
				generalOpen = false;
				vectorsOpen = false;
			}
		}
		if (vectorsOpen)
		{
			ImGui::PushStyleColor(ImGuiCol_Button, ImVec4 { 0.3f, 0.305f, 0.31f, 1.0f });
			ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4 { 0.15f, 0.1505f, 0.151f, 1.0f });
			ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4 { 0.3f, 0.305f, 0.31f, 1.0f });
			if (ImGui::ImageButton((ImTextureID) vectorsIcon, { 50.0f, 50.0f }, ImVec2 { 0, 1 }, ImVec2 { 1, 0 }))
				vectorsOpen = false;

			ImGui::PopStyleColor(3);
		}
		else {
			if (ImGui::ImageButton((ImTextureID) vectorsIcon, { 50.0f, 50.0f }, ImVec2 { 0, 1 }, ImVec2 { 1, 0 }))
			{
				vectorsOpen = true;
				generalOpen = false;
				settingsOpen = false;
			}
		}

		ImGui::PopStyleVar(2);
		ImGui::EndChild();
		ImGui::SameLine();
		ImGui::BeginChild("Child", ImVec2 { 0, 0 }, true);
		if (vectorsOpen)
		{
			ImVec2 buttonSize = ImVec2 { windowSize.x / 35, 0.0f };
			
			ImGui::Text(" Vector 1: ");  ImGui::SameLine(windowSize.x / 3.5);
			ImGui::Text(" Vector 2: ");
			
			ImGui::SetNextItemWidth(windowSize.x / 4); ImGui::DragFloat("##vec11", &vec1[0], 0.1f, 0.0f, 0.0f, "%.3f"); ImGui::SameLine(windowSize.x / 4);
			ImGui::PushStyleColor(ImGuiCol_Button, ImVec4 { 0.8f, 0.1f, 0.15f, 1.0f });
			ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4 { 0.9f, 0.2f, 0.2f, 1.0f });
			ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4 { 0.8f, 0.1f, 0.15f, 1.0f });
			ImGui::PushFont(OpenSansBold);
			if (ImGui::Button("x##1", buttonSize)) vec1[0] = 0;
			ImGui::PopFont();
			ImGui::PopStyleColor(3);
			ImGui::SameLine(windowSize.x / 3.5);
			
			ImGui::SetNextItemWidth(windowSize.x / 4); ImGui::DragFloat("##vec21", &vec2[0], 0.1f, 0.0f, 0.0f, "%.3f"); ImGui::SameLine(windowSize.x / 1.867);
			ImGui::PushStyleColor(ImGuiCol_Button, ImVec4 { 0.8f, 0.1f, 0.15f, 1.0f });
			ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4 { 0.9f, 0.2f, 0.2f, 1.0f });
			ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4 { 0.8f, 0.1f, 0.15f, 1.0f });
			ImGui::PushFont(OpenSansBold);
			if (ImGui::Button("x##2", buttonSize)) vec2[0] = 0;
			ImGui::PopFont();
			ImGui::PopStyleColor(3);
			
			ImGui::SetNextItemWidth(windowSize.x / 4); ImGui::DragFloat("##vec12", &vec1[1], 0.1f, 0.0f, 0.0f, "%.3f"); ImGui::SameLine(windowSize.x / 4 );
			ImGui::PushStyleColor(ImGuiCol_Button, ImVec4 { 0.f, 0.4f, 0.05f, 1.0f });
			ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4 { 0.1f, 0.5f, 0.15f, 1.0f });
			ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4 { 0.f, 0.4f, 0.05f, 1.0f });
			ImGui::PushFont(OpenSansBold);
			if (ImGui::Button("y##1", buttonSize))  vec1[1] = 0;
			ImGui::PopFont();
			ImGui::PopStyleColor(3);
			ImGui::SameLine(windowSize.x / 3.5);
			
			ImGui::SetNextItemWidth(windowSize.x / 4); ImGui::DragFloat("##vec22", &vec2[1], 0.1f, 0.0f, 0.0f, "%.3f"); ImGui::SameLine(windowSize.x / 1.867);
			ImGui::PushStyleColor(ImGuiCol_Button, ImVec4 { 0.f, 0.4f, 0.05f, 1.0f });
			ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4 { 0.1f, 0.5f, 0.15f, 1.0f });
			ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4 { 0.f, 0.4f, 0.05f, 1.0f });
			ImGui::PushFont(OpenSansBold);
			if (ImGui::Button("y##2", buttonSize)) vec2[1] = 0;
			ImGui::PopFont();
			ImGui::PopStyleColor(3);
			
			ImGui::SetNextItemWidth(windowSize.x / 4); ImGui::DragFloat("##vec13", &vec1[2], 0.1f, 0.0f, 0.0f, "%.3f"); ImGui::SameLine(windowSize.x / 4);
			ImGui::PushStyleColor(ImGuiCol_Button, ImVec4 { 0.1f, 0.25f, 0.8f, 1.0f });
			ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4 { 0.2f, 0.35f, 0.9f, 1.0f });
			ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4 { 0.1f, 0.25f, 0.8f, 1.0f });
			ImGui::PushFont(OpenSansBold);
			if (ImGui::Button("z##1", buttonSize)) vec1[2] = 0;
			ImGui::PopFont();
			ImGui::PopStyleColor(3);
			ImGui::SameLine(windowSize.x / 3.5);
			
			ImGui::SetNextItemWidth(windowSize.x / 4); ImGui::DragFloat("##vec23", &vec2[2], 0.1f, 0.0f, 0.0f, "%.3f"); ImGui::SameLine(windowSize.x / 1.867);
			ImGui::PushStyleColor(ImGuiCol_Button, ImVec4 { 0.1f, 0.25f, 0.8f, 1.0f });
			ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4 { 0.2f, 0.35f, 0.9f, 1.0f });
			ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4 { 0.1f, 0.25f, 0.8f, 1.0f });
			ImGui::PushFont(OpenSansBold);
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
		if (generalOpen)
		{
		}
		ImGui::EndChild();

		ImGui::End();

		if(demoWindow)
			ImGui::ShowDemoWindow();
	}
	ImGui::PopFont();
}

void Application::DrawConsole()
{
}
