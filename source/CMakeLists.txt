target_sources(pong 
  PRIVATE
    Main.cpp
)

add_subdirectory(collision)
add_subdirectory(components)
add_subdirectory(core)
add_subdirectory(io)
add_subdirectory(rendering)
add_subdirectory(systems)