# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/GAG_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/GAG_autogen.dir/ParseCache.txt"
  "GAG_autogen"
  )
endif()
