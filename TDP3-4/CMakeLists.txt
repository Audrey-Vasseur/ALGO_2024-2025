# Ajoutez une source à l'exécutable de ce projet.

add_executable(TDP3 "partie2.cpp" "partie3-4-5.cpp")


# TODO: Ajoutez des tests et installez des cibles si nécessaire.
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET TDP2 PROPERTY CXX_STANDARD 20)
endif()