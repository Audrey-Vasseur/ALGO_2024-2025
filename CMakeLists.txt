# CMakeList.txt�: fichier projet CMake de niveau sup�rieur, effectuez une configuration globale
# et incluez les sous-projets ici.
#
cmake_minimum_required (VERSION 3.8)

# Activez Rechargement � chaud pour les compilateurs MSVC si cela est pris en charge.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("ALGO_2024-2025")

# Incluez les sous-projets.

add_subdirectory ("TDP2")
add_subdirectory ("TDP3-4")
add_subdirectory ("TDP5-6")
add_subdirectory ("TDP7-8")
