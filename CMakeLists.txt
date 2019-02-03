
# To use this example as a standalone project using CMake:
# mkdir build
# cd build
# cmake .. -DCMAKE_TOOLCHAIN_FILE=path/to/Retro68-build/toolchain/m68k-apple-macos/cmake/retro68.toolchain.cmake
# make

cmake_minimum_required(VERSION 2.8)

add_application(PLATOTERM
  PLATOTERM.r
  help.c
  io.c
  keyboard.c
  main.c
  protocol.c
  screen.c
  terminal.c
  touch.c
  trace.c
  config.c
  CREATOR "PLTO"
  )
target_link_libraries(PLATOTERM "-lm")

# save 200KB of code by removing unused stuff
set_target_properties(PLATOTERM PROPERTIES LINK_FLAGS "-Wl,-gc-sections")

