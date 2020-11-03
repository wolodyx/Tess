add_executable(tests
  TestCurve.cpp
)

target_link_libraries(tests gtest_main Geo)
