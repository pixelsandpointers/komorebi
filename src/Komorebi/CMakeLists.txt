set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

# Option to choose between float and double precision
option(USE_FLOAT_PRECISION "Use float precision instead of double" OFF)

# Komorebi lib
add_library(komorebi STATIC)

# base classes
file(GLOB BaseHeaders "Base/*.h")
file(GLOB BaseSources "Base/*.cpp")
file(GLOB Headers ".h")
file(GLOB Sources ".cpp")

source_group(BaseHeaders "Base/*.h")

target_sources(komorebi PRIVATE Komorebi.cpp)

target_include_directories(komorebi PUBLIC 
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Base>
	$<INSTALL_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)
