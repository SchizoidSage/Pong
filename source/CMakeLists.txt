target_sources(pong 
  PRIVATE
    Main.cpp
    Game.cpp
    IOManager.cpp
)

add_subdirectory(actors)
add_subdirectory(collision)
add_subdirectory(components)
add_subdirectory(rendering)