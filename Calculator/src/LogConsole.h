#pragma once
#include <iostream>
#include <functional>
#include <utility>
#include <vector>
#include <tuple>
#include <string>
#include "Util/Time.h"
#include <imgui.h>


class LogConsole
{
public:
	// Displays everything and flushes the Buffer
	void Update(bool *open)
	{
		if (*open)
		{
			ImGui::Begin("Console", open, ImGuiWindowFlags_NoDocking);
			ImGui::SetWindowFocus();
			for (auto &buffer : m_Buffer)
				ImGui::Text(buffer.c_str());
			ImGui::SetScrollHereY(1.0f);
			ImGui::End();
		}
	}

	template<typename ... Args>
	void AddMessage(Args && ... args)
	{
		char *buffer = new char[256];
		sprintf_s(buffer, 255, std::forward<Args>(args)...);

		std::string buf(buffer);
		std::string bufferElement = "[" + Util::Time::GetTimeFormated() + "]: " + buf;

		m_Buffer.push_back(bufferElement);
	}

	void Clear() { m_Buffer.clear(); }

private:
	std::vector<std::string> m_Buffer;
};