#include "EquationSystem.h"


EquationSystem::EquationSystem()
{
	for (auto &e : m_Equations)
		e = { 0.0f, 0.0f, 0.0f };
}

EquationSystem::~EquationSystem()
{
}

void EquationSystem::OnContentRender()
{
	ImGui::DragFloat4("##num1", m_Equations[0], 0.0f, 10.0f);
	ImGui::DragFloat4("##num2", m_Equations[1], 0.0f, 10.0f);
	ImGui::DragFloat4("##num3", m_Equations[2], 0.0f, 10.0f);

	glm::mat3x3 system;
	glm::vec4 value;

	system[0][0] = m_Equations[0].a;
	system[1][0] = m_Equations[0].b;
	system[2][0] = m_Equations[0].c;
	value.x = m_Equations[0].res;

	system[0][1] = m_Equations[1].a;
	system[1][1] = m_Equations[1].b;
	system[2][1] = m_Equations[1].c;
	value.y = m_Equations[1].res;

	system[0][2] = m_Equations[2].a;
	system[1][2] = m_Equations[2].b;
	system[2][2] = m_Equations[2].c;
	value.z = m_Equations[2].res;

	glm::vec3 res = glm::inverse(system) * value;
	ImGui::Text("res: %.2f, %.2f, %.2f", res.x, res.y, res.z);
}
