cmake_minimum_required(VERSION 3.10)

# set the project name
project(SFMLSnake VERSION 1.0)

#Set executable
add_executable(${PROJECT_NAME}
    main.cpp
    src/board.cpp
    src/cell.cpp
    src/game.cpp
    src/snake.cpp
    src/snakeIndex.cpp
)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

target_include_directories(${PROJECT_NAME} PRIVATE fonts/)

find_package(SFML REQUIRED graphics window system)

target_link_libraries(${PROJECT_NAME} 
    ${SFML_LIBRARIES} 
    ${SFML_DEPENDENCIES}
)