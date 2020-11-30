#pragma once
#include <glm/glm.hpp>

#include <iostream>
#include <stb_image.h>

struct GLFWwindow;

namespace Util
{
	class Window
	{
	public:
		Window(uint32_t width, uint32_t height, const std::string &title);
		~Window();

		static void HideConsole();

		void SetIcon(const std::string &filepath);

		bool isOpen() const;
		void Update();
		void Close();
		void Clear(const glm::vec4 &clearColor = { 0.7f, 0.7f, 0.7f, 0.7f });

		inline GLFWwindow *GetWindow() const { return m_Window; }

		glm::vec2 GetPosition() const;
		glm::vec2 GetSize() const;

		void SetPosition(const glm::vec2 &pos);
		void SetSize(const glm::vec2 &size);

	private:
		GLFWwindow *m_Window;
	};
}
