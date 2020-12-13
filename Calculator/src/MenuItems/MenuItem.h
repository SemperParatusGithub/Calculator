#pragma once
#include <iostream>
#include <glm/glm.hpp>
#include <imgui.h>


// All classes that inherit from MenuItem must set the Icon ID by loading a Texture
class MenuItem
{
public:
	MenuItem() :  m_WindowSize({100.0f, 100.0f}), m_IconID(0), m_IsOpen(false)
	{
	}
	virtual ~MenuItem() = default;

	void OnUpdate(const glm::vec2 &windowSize) { m_WindowSize = windowSize; }
	virtual void OnContentRender() = 0;

	uint32_t GetIcon() const { return m_IconID; }
	inline bool IsOpen() const { return m_IsOpen; }

	inline void Open() { m_IsOpen = true; }
	inline void Close() { m_IsOpen = false; }

protected:
	uint32_t m_IconID;
	glm::vec2 m_WindowSize;

private:
	bool m_IsOpen;
};