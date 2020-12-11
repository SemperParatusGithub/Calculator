#pragma once
#include "MenuItem.h"


class Vectors : public MenuItem
{
public:
	Vectors();
	~Vectors();

	virtual void OnRender() override;

private:
	float vec1[3] = { 0, 0, 0 };
	float vec2[3] = { 0, 0, 0 };
};
