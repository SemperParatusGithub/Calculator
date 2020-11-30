#include "Application.h"

Application::Application(const std::string &title, uint32_t width, uint32_t height)
{
	m_Window = std::make_unique<Util::Window>(width, height, title);
	m_Window->SetIcon("CalculatorIcon.png");

	Util::Window::HideConsole();

	InitImGui();
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

void Application::InitImGui()
{
	Util::ImGuiInit(*m_Window);

	ImFont *openSansRegular = ImGui::GetIO().Fonts->AddFontFromFileTTF("res/fonts/OpenSans/OpenSans-Regular.ttf", 28.0f);
	m_TitleFont = ImGui::GetIO().Fonts->AddFontFromFileTTF("res/fonts/OpenSans/OpenSans-Regular.ttf", 32.0f);
	ImGui::GetIO().FontDefault = openSansRegular;
	ImGui::GetStyle().WindowMinSize = ImVec2 { 500.0f, 450.0f };
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

		unsigned int TestTex1 = Util::LoadTexture("CalculatorIcon.png");
		unsigned int TestTex2 = Util::LoadTexture("Test2.png");
		unsigned int TestTex3 = Util::LoadTexture("Test3.png");
		unsigned int TestTex4 = Util::LoadTexture("Test4.png");
		unsigned int TestTex5 = Util::LoadTexture("Test5.png");
		unsigned int TestTex6 = Util::LoadTexture("Test6.png");

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
				ImGui::EndMenu();
			if (ImGui::BeginMenu("About"))
				ImGui::EndMenu();
			if (ImGui::BeginMenu("Help"))
				ImGui::EndMenu();
			ImGui::EndMenuBar();
		}

		ImGui::BeginChild("VerticalMenu", ImVec2 { 73.5f, 0.0f }, true);
		ImGui::ImageButton((ImTextureID) TestTex1, { 50.0f, 50.0f }, ImVec2 { 0, 1 }, ImVec2 { 1, 0 });
		ImGui::Spacing();
		ImGui::ImageButton((ImTextureID) TestTex2, { 50.0f, 50.0f }, ImVec2 { 0, 1 }, ImVec2 { 1, 0 });
		ImGui::Spacing();
		ImGui::ImageButton((ImTextureID) TestTex3, { 50.0f, 50.0f }, ImVec2 { 0, 1 }, ImVec2 { 1, 0 });
		ImGui::Spacing();
		ImGui::ImageButton((ImTextureID) TestTex4, { 50.0f, 50.0f }, ImVec2 { 0, 1 }, ImVec2 { 1, 0 });
		ImGui::Spacing();
		ImGui::ImageButton((ImTextureID) TestTex5, { 50.0f, 50.0f }, ImVec2 { 0, 1 }, ImVec2 { 1, 0 });
		ImGui::Spacing();
		ImGui::ImageButton((ImTextureID) TestTex6, { 50.0f, 50.0f }, ImVec2 { 0, 1 }, ImVec2 { 1, 0 });
		ImGui::EndChild();
		ImGui::SameLine();
		ImGui::BeginChild("Child", ImVec2 { 0, 0 }, true);
		ImGui::EndChild();

		ImGui::End();
	}
	ImGui::PopFont();
}