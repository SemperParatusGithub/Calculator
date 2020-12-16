#include "Application.h"
#include "Util/Time.h"
#include "MenuItems/Vectors.h"
#include "MenuItems/Settings.h"
#include "MenuItems/Converter.h"
#include "MenuItems/EquationSystem.h"


Application::Application(const std::string &title, uint32_t width, uint32_t height)
{
	m_Window = std::make_unique<Util::Window>(width, height, title);
	m_Window->SetIcon("res/Icons/CalculatorIcon.png");

	// Util::Window::HideConsole();

	Util::ImGuiInit(*m_Window);

	m_MenuBar.RegisterMenuItem<Vectors>("Vectors");
	m_Console.Log<Info>("Registering MenuItem: Vectors");

	m_MenuBar.RegisterMenuItem<Settings>("Settings");
	m_Console.Log<Info>("Registering MenuItem: Settings");

	m_MenuBar.RegisterMenuItem<Converter>("Converter");
	m_Console.Log<Info>("Registering MenuItem: Converter");	
	
	m_MenuBar.RegisterMenuItem<EquationSystem>("EquationSystem");
	m_Console.Log<Info>("Registering MenuItem: EquationSystem");
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
		Util::Time::s_FrameCount += 1;

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

		// Menubar
		ImGui::BeginChild("MenuBar", ImVec2 { 58.0f, 0.0f }, false, ImGuiWindowFlags_NoScrollbar);
		m_MenuBar.OnUpdate(m_Window->GetSize());
		m_MenuBar.OnRender();
		ImGui::EndChild();

		ImGui::SameLine();
		ImGui::BeginChild("Child", ImVec2 { 0, 0 }, true);
		m_MenuBar.OnItemContentRender();
		ImGui::EndChild();

		ImGui::End();

		if(showDemoWindow)
			ImGui::ShowDemoWindow(&showDemoWindow);
	}
	m_Console.Update(&consoleOpen);
}