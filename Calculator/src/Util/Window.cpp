#include "Window.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <Windows.h>
#include <algorithm>

namespace Util
{
	Window::Window(uint32_t width, uint32_t height, const std::string &title) 
	{
		if (!glfwInit())
			throw std::runtime_error("Failed to initialize GLFW!");

		std::cout << "Creating GLFW window: " << title << " (" << width << ", " << height << ")" << std::endl;
		m_Window = glfwCreateWindow((int) width, (int) height, title.c_str(), nullptr, nullptr);

		if (!m_Window)
			throw std::runtime_error("Failed to create Window!");

		glfwMakeContextCurrent(m_Window);

		if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
			throw std::runtime_error("Failed to initialize Glad!");

		glfwSetWindowSizeLimits(m_Window, 800, 600, GLFW_DONT_CARE, GLFW_DONT_CARE);
	}
	Window::~Window()
	{
		glfwDestroyWindow(m_Window);
	}
	void Window::HideConsole()
	{
		HWND consoleWindow = GetConsoleWindow();
		ShowWindow(consoleWindow, 0);
	}
	void Window::SetIcon(const std::string &filepath)
	{
		GLFWimage Image[1];
		int m_BPP;
		stbi_set_flip_vertically_on_load(0);
		Image[0].pixels = stbi_load(filepath.c_str(), &Image[0].width, &Image[0].height, &m_BPP, 4);

		glfwSetWindowIcon(m_Window, 1, Image);

		if (Image[0].pixels)
			stbi_image_free(Image[0].pixels);
		else std::cout << "Failed to load Icon: " << filepath << std::endl;
	}

	bool Window::isOpen() const
	{
		return !glfwWindowShouldClose(m_Window);
	}
	void Window::Close()
	{
		glfwSetWindowShouldClose(m_Window, true);
	}
	void Window::Clear(const glm::vec4 &clearColor)
	{
		glClearColor(clearColor.r, clearColor.g, clearColor.b, clearColor.a);
		glClear(GL_COLOR_BUFFER_BIT);
	}
	void Window::Update()
	{
		glfwSwapBuffers(m_Window);
		glfwPollEvents();
	}

	glm::vec2 Window::GetPosition() const
	{
		int xPos, yPos;
		glfwGetWindowPos(m_Window, &xPos, &yPos);
		return { (float) xPos, (float) yPos };
	}
	glm::vec2 Window::GetSize() const
	{
		int xSize, ySize;
		glfwGetWindowSize(m_Window, &xSize, &ySize);
		return { (float) xSize, (float) ySize };
	}

	void Window::SetPosition(const glm::vec2 &pos)
	{
		glfwSetWindowPos(m_Window, (int) pos.x, (int) pos.y);
	}
	void Window::SetSize(const glm::vec2 &size)
	{
		glfwSetWindowSize(m_Window, (int) size.x, (int) size.y);
	}

}