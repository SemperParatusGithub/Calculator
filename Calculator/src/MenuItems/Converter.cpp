#include "Converter.h"
#include "Util/TextureLoader.h"

Converter::Converter()
{
	m_IconID = Util::LoadTexture("res/Icons/ConvertIcon.png");
	firstNumber = 3.141592653589793238462643383279;
}

Converter::~Converter()
{
}

void Converter::OnContentRender()
{
	ImGui::Text("%.10f", firstNumber);
}