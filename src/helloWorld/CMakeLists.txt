project (helloWorld)


set(SOURCES
    ${PROJECT_SOURCE_DIR}/main.c
)


#######################
### With static Lib ###
########################
# Add an executable with the above sources
add_executable(hello_static ${SOURCES})
# link to static Libary
target_link_libraries(hello_static
    PRIVATE
        static_log
)

########################
### With dynamic Lib ###
########################
add_executable(hello_dynamic ${SOURCES})
# link to dynamic Libary
target_link_libraries(hello_dynamic
    PRIVATE
        dynamic_log
)




