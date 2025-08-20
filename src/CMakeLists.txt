target_link_libraries(${PROJECT_NAME} PRIVATE 
    vendor
)

target_sources(${EXECUTABLE_NAME} PRIVATE 
    main.cpp
    Version.cpp
)
