#include "Application.h"
#include "Util/Time.h"


Application::Application(const std::string &title, uint32_t width, uint32_t height)
{
	m_Window = std::make_unique<Util::Window>(width, height, title);
	m_Window->SetIcon("res/Icons/CalculatorIcon.png");

	// Util::Window::HideConsole();

	Util::ImGuiInit(*m_Window);

	calculatorIcon = Util::LoadTexture("res/Icons/CalculatorIcon.png");
	settingsIcon = Util::LoadTexture("res/Icons/SettingsIcon.png");
	vectorsIcon = Util::LoadTexture("res/Icons/VectorsIcon.png");

	m_MenuItems["Vectors"] = std::make_shared<Vectors>();
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

		Update();

		Util::ImGuiEndFrame();
	}
}

void Application::Update()
{
	ImGui::SetNextWindowPos(ImVec2 { m_Window->GetPosition().x, m_Window->GetPosition().y });
	ImGui::SetNextWindowSize(ImVec2 { m_Window->GetSize().x, m_Window->GetSize().y });

	bool minimized = m_Window->GetSize().x == 0 && m_Window->GetSize().y == 0;

	if (!minimized)
	{
		ImGui::Begin("##MainImGuiWindow", 0, ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize);
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
				if (ImGui::MenuItem("Show DemoWindow", "", &showDemoWindow, true));
				ImGui::EndMenu();
			}
			if (ImGui::BeginMenu("Help"))
			{
				if (ImGui::MenuItem("Open Console", "", &consoleOpen, true));
				ImGui::EndMenu();
			}
			ImGui::SetCursorPos({ ImGui::GetContentRegionMax().x - 100.0f, 0.0f });
			ImGui::Text("%s", Util::Time::GetTimeFormated().c_str());
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
				settingsOpen = vectorsOpen = false;
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
				generalOpen = vectorsOpen = false;
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
				generalOpen = settingsOpen = false;
			}
		}
		ImGui::PopStyleVar(2);
		ImGui::EndChild();

		ImGui::SameLine();
		ImGui::BeginChild("Child", ImVec2 { 0, 0 }, true);
		if (vectorsOpen)
		{
			m_MenuItems["Vectors"]->OnUpdate(m_Window->GetSize());
			m_MenuItems["Vectors"]->OnRender();
		}
		else
		{
		}
		ImGui::EndChild();

		ImGui::End();

		// Temporary
		if(showDemoWindow)
			ImGui::ShowDemoWindow();
	}
}