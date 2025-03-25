project (Lib_Log)

########################
# Create a library     #
########################

# File for Libary
file(GLOB FILE ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c)

### Static Libary ###
add_library(static_log STATIC ${FILE})

target_include_directories(static_log 
    PUBLIC 
        ${CMAKE_CURRENT_SOURCE_DIR}/header
)

set_target_properties(static_log PROPERTIES PREFIX "lib")
set_target_properties(static_log PROPERTIES OUTPUT_NAME "log")
set_target_properties(static_log PROPERTIES SUFFIX ".a")

### Dynamic Library ###
add_library(dynamic_log SHARED ${FILE})

target_include_directories(dynamic_log 
    PUBLIC 
        ${CMAKE_CURRENT_SOURCE_DIR}/header
)

set_target_properties(dynamic_log PROPERTIES PREFIX "lib")
set_target_properties(dynamic_log PROPERTIES OUTPUT_NAME "log")
set_target_properties(dynamic_log PROPERTIES SUFFIX ".so")

