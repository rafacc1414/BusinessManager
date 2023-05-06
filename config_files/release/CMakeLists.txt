cmake_minimum_required(VERSION 3.10)

set(PROJECT_NAME "BusinessManager") # CUSTOMISE: your project name
set(PROJECT_VERSION 0.1.0) # CUSTOMISE: project version
set(CMAKE_CXX_STANDARD 17) # CUSTOMISE: standard
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(${PROJECT_NAME} VERSION ${PROJECT_VERSION})

# Include all esential directories
include_directories(
    ./../../include
    ./../../include/model
    ./../../include/view
)

# add all files of source folder
file(GLOB SOURCES
    ./../../include/*.hpp
	./../../include/model/*.hpp
    ./../../include/view/*.hpp
    ./../../src/model/*.cpp
    ./../../src/view/*.cpp
	./../../src/*.cpp
)

# $source_files is a space-delimited list of filenames.
add_executable(${PROJECT_NAME} ${SOURCES})  # Specifies the executable to build.
set_target_properties(
    ${PROJECT_NAME} 
    PROPERTIES 
        OUTPUT_NAME ${PROJECT_NAME}
        SUFFIX ".bin"
)