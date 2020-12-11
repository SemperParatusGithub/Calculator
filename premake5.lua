workspace "Calculator"
	architecture "x64"
	startproject "Calculator"

	configurations { "Debug", "Release" }
	flags { "MultiProcessorCompile" }

	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "ThirdParty"
	include "Calculator/ThirdParty/GLFW"
	include "Calculator/ThirdParty/Glad"
	include "Calculator/ThirdParty/imgui"
group ""

project "Calculator"
	location "Calculator"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "On"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files { 
 		"Calculator/src/**.h",
		"Calculator/src/**.cpp"
	}
	includedirs { 
		"Calculator/src",
		"Calculator/ThirdParty/GLFW/include",
		"Calculator/ThirdParty/Glad/include",
		"Calculator/ThirdParty/imgui",
		"Calculator/ThirdParty/glm",
		"Calculator/ThirdParty/stb_image"
	}

	links { "GLFW", "Glad", "ImGui", "opengl32.lib" }
	defines { "_CRT_SECURE_NO_WARNINGS" }

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		symbols "On"
	filter "configurations:Release"
		optimize "On"