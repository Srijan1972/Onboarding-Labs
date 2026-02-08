# Week 1 Lab: CMake and Toolchain

## Notes

- The version of cmake on my machine is 3.22.1
- The valid targets for this project are: all, clean, depend, edit_cache, rebuild_cache, hello_world, hello.o, hello.i, and hello.s

## Answers

- The paths in the cmake commands are relative to the directory ``CMakeLists.txt`` is present in.
- ``cmake`` is a meta-build system, i.e., it takes the configuration provided in ``CMakeLists.txt`` and produces another build system. ``ninja`` is a build system, i.e., that takes a configuration file and produces an executable to be run.
- It is important to run ``cmake`` in a separate directory because the command produces a large number of output files and it prevents the directories with the source code from being polluted with the output(s) of ``cmake``