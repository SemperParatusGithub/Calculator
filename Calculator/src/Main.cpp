#include "Application.h"

/* -------------------------------------------------------------------------*
 *  Taschenrechner Nils Schlager 3BHBG										*
 *	https://github.com/SemperParatusGithub/Taschenrechner					*
 * -------------------------------------------------------------------------*
 *  verwendete Bibliotheken		Links:										*
 * -------------------------------------------------------------------------*
 * 	 Dear ImGui					https://github.com/ocornut/imgui			*
 * 	 stb_image					https://github.com/nothings/stb				*
 * 	 GLFW						https://www.glfw.org/						*
 * 	 Glad						https://glad.dav1d.de/						*
 *   GLM						https://glm.g-truc.net/0.9.2/api/index.html	*
 * ------------------------------------------------------------------------ */


int main(int argc, char *argv[])
{
	Util::Time::StartSession("Startup");
	Application *App = new Application("Calculator", 1280, 720);
	Util::Time::EndSession();

	Util::Time::StartSession("Runtime");
	App->Run();
	Util::Time::EndSession();

	Util::Time::StartSession("Shutdown");
	delete App;
	Util::Time::EndSession();

	return EXIT_SUCCESS;
}