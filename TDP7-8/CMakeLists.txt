# Ajoutez une source � l'ex�cutable de ce projet.

add_executable(TDP7-8 "partie2.cpp")


# TODO: Ajoutez des tests et installez des cibles si n�cessaire.
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET TDP2 PROPERTY CXX_STANDARD 20)
endif()