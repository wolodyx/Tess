add_library(Geo STATIC
  include/Vector.h                 Vector.cpp
  include/ParametricGeometry.h     ParametricGeometry.cpp
)

target_include_directories(Geo
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)
