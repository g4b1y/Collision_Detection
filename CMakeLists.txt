cmake_minimum_required(VERSION 3.22)
project(CollisionDetection)

set(CMAKE_CXX_STANDARD 23)

add_executable(CollisionDetection main.cpp Assets/Asset.hpp Collision/Collision.cpp Collision/Collision.h Run/Run.cpp Run/Run.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR G:/SFML-2.5.1/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(G:/SFML-2.5.1/include)
target_link_libraries(CollisionDetection sfml-system sfml-window sfml-audio sfml-graphics)