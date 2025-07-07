cmake_minimum_required(VERSION 3.20)

project(root)

# For Clangd (generate compile_commands.json)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

# Set execute path
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/output)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output/lib/static) # static lib path
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output/lib/dynamic) # dynamic lib path


##################
# Build the lib  #
##################
set (LIB_PATH "include")
add_subdirectory(${LIB_PATH}/log)

######################
# Build the execute  #
######################
set (HELLOWORLD_PATH "src/helloWorld")

add_subdirectory(${HELLOWORLD_PATH})


