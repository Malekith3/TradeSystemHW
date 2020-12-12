workspace "TradeSystemHW1"
	architecture "x64"
	configurations 
	{
		"Debug",
		"Release"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "TradeSystem"
	location "TradeSystem"
	kind "ConsoleApp"
	language "C++"
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")

	 files 
	 { 
	 	"%{prj.name}/source/Header/*.h",
	 	"%{prj.name}/source/CPP/*.cpp",
	 	"%{prj.name}/source/*.cpp",
	 	"%{prj.name}/source/*.h"
	 }

	 includedirs
	 {
		"TradeSystem/source"
	 }

	filter "system:windows"
	  cppdialect "C++17"
	  staticruntime "On"
	  systemversion "latest"
      defines { "_CRT_SECURE_NO_WARNINGS" }
      symbols "On"

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols  "On"
	  optimize "Off"