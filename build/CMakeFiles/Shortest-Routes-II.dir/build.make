# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 4.0

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\jacks\CSES_Solutions

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\jacks\CSES_Solutions\build

# Include any dependencies generated for this target.
include CMakeFiles/Shortest-Routes-II.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Shortest-Routes-II.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Shortest-Routes-II.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Shortest-Routes-II.dir/flags.make

CMakeFiles/Shortest-Routes-II.dir/codegen:
.PHONY : CMakeFiles/Shortest-Routes-II.dir/codegen

CMakeFiles/Shortest-Routes-II.dir/Graph-Algorithms/Shortest-Routes-II.cpp.obj: CMakeFiles/Shortest-Routes-II.dir/flags.make
CMakeFiles/Shortest-Routes-II.dir/Graph-Algorithms/Shortest-Routes-II.cpp.obj: C:/Users/jacks/CSES_Solutions/Graph-Algorithms/Shortest-Routes-II.cpp
CMakeFiles/Shortest-Routes-II.dir/Graph-Algorithms/Shortest-Routes-II.cpp.obj: CMakeFiles/Shortest-Routes-II.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\jacks\CSES_Solutions\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Shortest-Routes-II.dir/Graph-Algorithms/Shortest-Routes-II.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Shortest-Routes-II.dir/Graph-Algorithms/Shortest-Routes-II.cpp.obj -MF CMakeFiles\Shortest-Routes-II.dir\Graph-Algorithms\Shortest-Routes-II.cpp.obj.d -o CMakeFiles\Shortest-Routes-II.dir\Graph-Algorithms\Shortest-Routes-II.cpp.obj -c C:\Users\jacks\CSES_Solutions\Graph-Algorithms\Shortest-Routes-II.cpp

CMakeFiles/Shortest-Routes-II.dir/Graph-Algorithms/Shortest-Routes-II.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Shortest-Routes-II.dir/Graph-Algorithms/Shortest-Routes-II.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\jacks\CSES_Solutions\Graph-Algorithms\Shortest-Routes-II.cpp > CMakeFiles\Shortest-Routes-II.dir\Graph-Algorithms\Shortest-Routes-II.cpp.i

CMakeFiles/Shortest-Routes-II.dir/Graph-Algorithms/Shortest-Routes-II.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Shortest-Routes-II.dir/Graph-Algorithms/Shortest-Routes-II.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\jacks\CSES_Solutions\Graph-Algorithms\Shortest-Routes-II.cpp -o CMakeFiles\Shortest-Routes-II.dir\Graph-Algorithms\Shortest-Routes-II.cpp.s

# Object files for target Shortest-Routes-II
Shortest__Routes__II_OBJECTS = \
"CMakeFiles/Shortest-Routes-II.dir/Graph-Algorithms/Shortest-Routes-II.cpp.obj"

# External object files for target Shortest-Routes-II
Shortest__Routes__II_EXTERNAL_OBJECTS =

Shortest-Routes-II.exe: CMakeFiles/Shortest-Routes-II.dir/Graph-Algorithms/Shortest-Routes-II.cpp.obj
Shortest-Routes-II.exe: CMakeFiles/Shortest-Routes-II.dir/build.make
Shortest-Routes-II.exe: CMakeFiles/Shortest-Routes-II.dir/linkLibs.rsp
Shortest-Routes-II.exe: CMakeFiles/Shortest-Routes-II.dir/objects1.rsp
Shortest-Routes-II.exe: CMakeFiles/Shortest-Routes-II.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\jacks\CSES_Solutions\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Shortest-Routes-II.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Shortest-Routes-II.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Shortest-Routes-II.dir/build: Shortest-Routes-II.exe
.PHONY : CMakeFiles/Shortest-Routes-II.dir/build

CMakeFiles/Shortest-Routes-II.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Shortest-Routes-II.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Shortest-Routes-II.dir/clean

CMakeFiles/Shortest-Routes-II.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\jacks\CSES_Solutions C:\Users\jacks\CSES_Solutions C:\Users\jacks\CSES_Solutions\build C:\Users\jacks\CSES_Solutions\build C:\Users\jacks\CSES_Solutions\build\CMakeFiles\Shortest-Routes-II.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Shortest-Routes-II.dir/depend

