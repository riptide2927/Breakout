include "Dependencies.lua"

workspace "Breakout"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}



outputdir = "%{cfg.buildcfg}-%{cfg.architecture}-"

project "Breakout"
	location "Breakout"
	kind "ConsoleApp"
	language "C++"

	targetdir("bin/" ..outputdir.. "%{prj.name}")
	objdir("bin-int/" ..outputdir.. "%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"src",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.GLEW}",
		"%{IncludeDir.SOIL2}",
		"%{IncludeDir.GLM}"
	}

	libdirs
	{
		"%{LibraryDir.GLFW}",
		"%{LibraryDir.GLEW}",
		"%{LibraryDir.SOIL2}"
	}

	links
	{
		"soil2-debug",
		"glfw3_mt",
		"glew32s",
		"opengl32.lib"
	}

	defines
	{
		"GLEW_STATIC"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

	filter "configurations:Debug"
		symbols "On"

	filter "configurations:Release"
		optimize "On"