add_subdirectory(Komorebi)

add_executable(app)
target_include_directories(app PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/App)
target_sources(app PUBLIC App/App.cpp)

target_link_libraries(app PUBLIC komorebi)