set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)


# Option to choose between float and double precision
option(USE_FLOAT_PRECISION "Use float precision instead of double" OFF)
set(FLOAT_PRECISION OFF)
set(DOUBLE_PRECISION ON)

if(USE_FLOAT_PRECISION)
    set(FLOAT_PRECISION ON)
    set(DOUBLE_PRECISION OFF)
endif()

# Add definitions based on the selected precision
if(FLOAT_PRECISION)
    add_definitions(-DFLOAT_PRECISION)
elseif(DOUBLE_PRECISION)
    add_definitions(-DDOUBLE_PRECISION)
endif()

# Komorebi lib
add_library(komorebi STATIC)

# base classes
file(GLOB BaseHeaders "Base/*.h")
file(GLOB BaseSources "Base/*.cpp")

source_group(BaseHeaders "Base/*.h")

target_sources(komorebi PRIVATE Komorebi.cpp "Base/Common.h")

target_include_directories(komorebi PUBLIC 
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Base>
	$<INSTALL_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)
