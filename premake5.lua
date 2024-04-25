workspace "GitHub"
   configurations { "Debug", "Release" }

project "demo"
   kind "ConsoleApp"
   language "C++"
   files { "demo.cpp" }
   includedirs { "lib/export" }

   links {"polynomial-equation-solver"}
   
project "polynomial-equation-solver"
   kind "StaticLib"
   language "C++"
   files { "lib/**.hpp", "lib/**.cpp" }
   includedirs { "lib/export", "lib/include" }
   
   filter { "configurations:Debug" }
   defines { "PES_DEBUG" }
   symbols "On"

   filter { "configurations:Release" }
   defines { "PES_RELEASE" }
   optimize "On"