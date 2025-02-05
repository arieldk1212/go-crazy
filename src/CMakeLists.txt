list(APPEND sources
App.cpp
)

add_library(src STATIC ${sources})

add_executable(App ${sources})

target_link_libraries(App PRIVATE src ${project_libraries})