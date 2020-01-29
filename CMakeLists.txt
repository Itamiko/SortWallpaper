cmake_minimum_required(VERSION 3.15)
project(sw C)

set(CMAKE_C_STANDARD 11)

set(SOURCES
	src/main.c
	src/determineImageSize.c
)


add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})

find_library(libargparse sw)

target_link_libraries(sw libargparse)
target_link_libraries(sw libpng16d)

target_include_directories(${CMAKE_PROJECT_NAME}
	PRIVATE
		${PROJECT_SOURCE_DIR}/inc
)

install(TARGETS ${CMAKE_PROJECT_NAME} DESTINATION bin)