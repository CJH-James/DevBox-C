project (Lib_ParseArg)

########################
# Create a library     #
########################

# File for Libary
file(GLOB FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c)

### Static Libary ###
add_library(static_parseArg STATIC ${FILES})

target_include_directories(static_parseArg
    PUBLIC 
        ${CMAKE_CURRENT_SOURCE_DIR}/header
)

# Link to static_log and add its include directories
# target_link_libraries(static_parseArg
#     PUBLIC
#         static_log
# )

set_target_properties(static_parseArg PROPERTIES PREFIX "lib")
set_target_properties(static_parseArg PROPERTIES OUTPUT_NAME "parseArg")
set_target_properties(static_parseArg PROPERTIES SUFFIX ".a")

### Dynamic Library ###
add_library(dynamic_parseArg SHARED ${FILES})
target_include_directories(dynamic_parseArg 
    PUBLIC 
        ${CMAKE_CURRENT_SOURCE_DIR}/header
)

# Link to dynamic_log and add its include directories
# target_link_libraries(dynamic_parseArg
#     PUBLIC
#         dynamic_log
# )

set_target_properties(dynamic_parseArg PROPERTIES PREFIX "lib")
set_target_properties(dynamic_parseArg PROPERTIES OUTPUT_NAME "parseArg")
set_target_properties(dynamic_parseArg PROPERTIES SUFFIX ".so")

