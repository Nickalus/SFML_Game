Cmake_Minimum_Required(VERSION 2.8)

Project(SFML_Game)

#C++ flags
if(UNIX)
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")
endif()

#Game_Definitions
Set(Game_Definitions )

#Where to find stuff
If(UNIX)
  Set(Boost_Dir /usr/local/boost-1.55.0)
  Set(SFML_Dir /usr/local/)
Elseif(WIN32)
  Set(Boost_Dir C:/boost-1.55.0)
  Set(SFML_Dir C:/SFML-2.2.0)
Endif()

#SFML
Set(SFML_Include ${SFML_Dir}/include)

#Game_Include_Dir
Set(Game_Include_Dir ${SFML_Include})

#Libraries
#SFML
Set(SFML_Graphics ${SFML_Dir}/lib/SFML-2.2.0/libsfml-graphics.so)
Set(SFML_Window ${SFML_Dir}/lib/SFML-2.2.0/libsfml-window.so)
Set(SFML_System ${SFML_Dir}/lib/SFML-2.2.0/libsfml-system.so)

#Game_Libraries/usr/local/lib/
Set(Game_Libraries ${SFML_Graphics} ${SFML_Window} ${SFML_System})

# Sources
SET(Game_sources
    Main.cpp
    Game.cpp
    GameStateManager.cpp
    TitleState.cpp
    PlayState.cpp
    SceneNode.cpp
    SpriteNode.cpp
    TextNode.cpp
    AssetManager.cpp
    AssetMap.cpp
    DirectoryRange.cpp
   )

SET(Game_Headers
    Game.hpp
    State.hpp
    GameStateManager.hpp
    TitleState.hpp
    PlayState.hpp
    SceneNode.hpp
    SpriteNode.hpp
    TextNode.hpp
    AssetManager.hpp
    AssetMap.hpp
    DirectoryRange.hpp
   )

Include_Directories(${Game_Include_Dir})
Link_Directories(${Game_Library_Dir})
Add_Executable(${PROJECT_NAME} ${Game_sources} ${Game_Headers})
Target_Link_Libraries(${PROJECT_NAME} ${Game_Libraries})
