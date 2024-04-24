workspace "GitHub"
   configurations { "Debug", "Release" }

project "polynomial-equation-solver"
   kind "SharedLib"
   language "C++"
   files { "**.hpp", "**.cpp" }

   filter { "configurations:Debug" }
      defines { "PES_DEBUG" }
      symbols "On"

   filter { "configurations:Release" }
      defines { "PES_RELEASE" }
      optimize "On"
