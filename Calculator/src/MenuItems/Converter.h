#pragma once
#include "MenuItem.h"


class Converter : public MenuItem
{
public:
	Converter();
	~Converter();

	virtual void OnContentRender() override;

private:
	long double firstNumber, secondsNumber;
};