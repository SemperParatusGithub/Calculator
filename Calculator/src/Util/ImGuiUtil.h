#pragma once

#include "Window.h"
#include <imgui.h>

namespace Util
{
	void ImGuiInit(Window &window);
	void ImGuiShutdown();

	void ImGuiBeginFrame();
	void ImGuiEndFrame();
}