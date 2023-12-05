set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

# Komorebi lib
add_library(komorebi STATIC)

# base classes
file(GLOB BaseHeaders "Base/*.h")
file(GLOB BaseSources "Base/*.cpp")

target_sources(komorebi PRIVATE Komorebi.cpp)

target_include_directories(komorebi PUBLIC 
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Base>
	$<INSTALL_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)
