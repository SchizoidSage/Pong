find_package(EnTT 3.12.0 CONFIG QUIET)

if(EnTT_FOUND)
  add_library(EnTT_external INTERFACE)
else()
  include(ExternalProject)
  ExternalProject_Add(EnTT_external
    GIT_REPOSITORY  https://github.com/skypjack/entt.git
    GIT_TAG         v3.12.0
    UPDATE_COMMAND  ""
    CMAKE_ARGS
      -DCMAKE_INSTALL_PREFIX=${STAGED_INSTALL_PREFIX}
      -DENTT_BUILD_TESTING=OFF
  )

  include(GNUInstallDirs)
  
  set(
    ENTT_DIR ${STAGED_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR}/EnTT/cmake
    CACHE PATH "Path to internally built EnTTConfig.cmake"
    FORCE
  )
endif()