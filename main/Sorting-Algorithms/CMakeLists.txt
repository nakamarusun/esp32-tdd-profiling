if (DEFINED NRF_BUILD)

  project(Sorting-Algorithms
    "helper/utils.h"
    "sorting-methods/all.h"
    "sorting-methods/binary_insertion_sort.h"
    "sorting-methods/bubble_sort.h"
    "sorting-methods/couting_sort.h"
    "sorting-methods/flash_sort.h"
    "sorting-methods/heap_sort.h"
    "sorting-methods/insertion_sort.h"
    "sorting-methods/merge_sort.h"
    "sorting-methods/radix_sort.h"
    "sorting-methods/selection_sort.h"
    "sorting-methods/shaker_sort.h"
    "sorting-methods/shell_sort.h"
  )

  add_library(${PROJECT_NAME} ${SECURITIES_SOURCE})

  target_include_directories(${PROJECT_NAME} PUBLIC sorting-methods)

else()

  idf_component_register(SRCS
    "helper/utils.h"
    "sorting-methods/all.h"
    "sorting-methods/binary_insertion_sort.h"
    "sorting-methods/bubble_sort.h"
    "sorting-methods/couting_sort.h"
    "sorting-methods/flash_sort.h"
    "sorting-methods/heap_sort.h"
    "sorting-methods/insertion_sort.h"
    "sorting-methods/merge_sort.h"
    "sorting-methods/radix_sort.h"
    "sorting-methods/selection_sort.h"
    "sorting-methods/shaker_sort.h"
    "sorting-methods/shell_sort.h"
    INCLUDE_DIRS "sorting-methods"
  )

endif()