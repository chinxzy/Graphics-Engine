project "Esm"
    kind "StaticLib"
    language "C++"
    
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "Esmath/src/**.h",
		"Esmath/src/**.cpp",
		"Esmath/Esmath.h"
    }

	includedirs
	{
		
	}
    
    filter "system:windows"
        systemversion "latest"
		cppdialect "C++17"
        staticruntime "On"
        
   filter { "system:windows", "configurations:Debug" }
        buildoptions "/MTd"
	
		