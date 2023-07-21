cmake_minimum_required(VERSION 3.0)

set(EXTRA_COMPONENT_DIRS
  "../main/Sorting-Algorithms"
)

set(TEST_COMPONENTS
  "Sorting-Algorithms"
)

include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(algo_test)