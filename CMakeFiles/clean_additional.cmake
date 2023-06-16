# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "")
  file(REMOVE_RECURSE
  "CMakeFiles\\TicTacToe_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\TicTacToe_autogen.dir\\ParseCache.txt"
  "CMakeFiles\\tests_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\tests_autogen.dir\\ParseCache.txt"
  "TicTacToe_autogen"
  "doctest\\CMakeFiles\\doctest_with_main_autogen.dir\\AutogenUsed.txt"
  "doctest\\CMakeFiles\\doctest_with_main_autogen.dir\\ParseCache.txt"
  "doctest\\doctest_with_main_autogen"
  "tests_autogen"
  )
endif()
