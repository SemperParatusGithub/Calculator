#pragma once
#include <iostream>
#include <glm/glm.hpp>
#include <imgui.h>


class MenuItem
{
public:
	MenuItem() :  m_WindowSize({100.0f, 100.0f}), m_IconID(0), m_IsOpen(false)
	{
	}
	virtual ~MenuItem() = default;

	virtual void OnUpdate(const glm::vec2 &windowSize) { m_WindowSize = windowSize; }
	virtual void OnRender() = 0;

	virtual uint32_t GetIcon() const { return m_IconID; }
	inline bool IsOpen() const { return m_IsOpen; }

	inline void Open() { m_IsOpen = true; }
	inline void Close() { m_IsOpen = false; }

protected:
	bool m_IsOpen;
	uint32_t m_IconID;
	glm::vec2 m_WindowSize;
};