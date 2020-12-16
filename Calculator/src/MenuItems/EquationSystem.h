#pragma once
#include "MenuItem.h"
#include <glm/glm.hpp>
#include <array>


struct Equation
{
	float a, b, c;
	float res;

	inline operator float*() { return &a; }
};


class EquationSystem : public MenuItem
{
public:
	EquationSystem();
	~EquationSystem();
	virtual void OnContentRender() override;

private:
	std::array<Equation, 3> m_Equations;
};
