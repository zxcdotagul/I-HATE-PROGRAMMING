# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\kalkulator_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\kalkulator_autogen.dir\\ParseCache.txt"
  "kalkulator_autogen"
  )
endif()
