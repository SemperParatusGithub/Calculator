#pragma once
#include <iostream>
#include <functional>
#include <utility>
#include <vector>
#include <tuple>
#include <string>
#include "Util/Time.h"
#include <imgui.h>

enum Severity
{
	Info, Warn, Error, Critical
};

class LogConsole
{
public:
	typedef struct
	{
		Severity severity;
		std::string time;
		std::string message;
	}LogElem;

	// Displays everything and flushes the Buffer
	void Update(bool *open)
	{
		if (*open)
		{
			ImGui::Begin("Console", open, ImGuiWindowFlags_NoDocking | ImGuiWindowFlags_NoCollapse);
			ImGui::SetWindowFocus();

			for (auto &elem : m_Buffer)
			{
				std::string msg = elem.time + SeverityToString(elem.severity) + elem.message;
				ImGui::Text(msg.c_str());
				ImGui::PopStyleColor(1);
			}

			ImGui::SetScrollHereY(1.0f);
			ImGui::End();
		}
	}

	template<Severity severityType, typename ... Args>
	void Log(Args && ... args)
	{
		char *buffer = new char[256];
		sprintf_s(buffer, 255, std::forward<Args>(args)...);

		LogElem elem = {
			severityType,
			"[" + Util::Time::GetTimeFormated() + "]",
			std::string(buffer)
		};

		m_Buffer.push_back(elem);
	}

	void Clear() { m_Buffer.clear(); }

private:
	std::string SeverityToString(Severity sev)
	{
		switch (sev)
		{
			case Severity::Info:	 ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.10f, 0.80f, 0.40f, 1.00f));	return "[Info]: ";
			case Severity::Warn:	 ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.00f, 0.83f, 0.00f, 1.00f));	return "[Warn]: ";
			case Severity::Error:	 ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.00f, 0.40f, 0.40f, 1.00f));	return "[Error]: ";
			case Severity::Critical: ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.40f, 0.00f, 0.00f, 1.00f));	return "[Critical]: ";
		}
		return "";
	}

private:
	std::vector<LogElem> m_Buffer;
};