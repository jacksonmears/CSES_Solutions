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
include CMakeFiles/Shortest-Routes-I.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Shortest-Routes-I.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Shortest-Routes-I.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Shortest-Routes-I.dir/flags.make

CMakeFiles/Shortest-Routes-I.dir/codegen:
.PHONY : CMakeFiles/Shortest-Routes-I.dir/codegen

CMakeFiles/Shortest-Routes-I.dir/Graph-Algorithms/Shortest-Routes-I.cpp.obj: CMakeFiles/Shortest-Routes-I.dir/flags.make
CMakeFiles/Shortest-Routes-I.dir/Graph-Algorithms/Shortest-Routes-I.cpp.obj: C:/Users/jacks/CSES_Solutions/Graph-Algorithms/Shortest-Routes-I.cpp
CMakeFiles/Shortest-Routes-I.dir/Graph-Algorithms/Shortest-Routes-I.cpp.obj: CMakeFiles/Shortest-Routes-I.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\jacks\CSES_Solutions\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Shortest-Routes-I.dir/Graph-Algorithms/Shortest-Routes-I.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Shortest-Routes-I.dir/Graph-Algorithms/Shortest-Routes-I.cpp.obj -MF CMakeFiles\Shortest-Routes-I.dir\Graph-Algorithms\Shortest-Routes-I.cpp.obj.d -o CMakeFiles\Shortest-Routes-I.dir\Graph-Algorithms\Shortest-Routes-I.cpp.obj -c C:\Users\jacks\CSES_Solutions\Graph-Algorithms\Shortest-Routes-I.cpp

CMakeFiles/Shortest-Routes-I.dir/Graph-Algorithms/Shortest-Routes-I.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Shortest-Routes-I.dir/Graph-Algorithms/Shortest-Routes-I.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\jacks\CSES_Solutions\Graph-Algorithms\Shortest-Routes-I.cpp > CMakeFiles\Shortest-Routes-I.dir\Graph-Algorithms\Shortest-Routes-I.cpp.i

CMakeFiles/Shortest-Routes-I.dir/Graph-Algorithms/Shortest-Routes-I.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Shortest-Routes-I.dir/Graph-Algorithms/Shortest-Routes-I.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\jacks\CSES_Solutions\Graph-Algorithms\Shortest-Routes-I.cpp -o CMakeFiles\Shortest-Routes-I.dir\Graph-Algorithms\Shortest-Routes-I.cpp.s

# Object files for target Shortest-Routes-I
Shortest__Routes__I_OBJECTS = \
"CMakeFiles/Shortest-Routes-I.dir/Graph-Algorithms/Shortest-Routes-I.cpp.obj"

# External object files for target Shortest-Routes-I
Shortest__Routes__I_EXTERNAL_OBJECTS =

Shortest-Routes-I.exe: CMakeFiles/Shortest-Routes-I.dir/Graph-Algorithms/Shortest-Routes-I.cpp.obj
Shortest-Routes-I.exe: CMakeFiles/Shortest-Routes-I.dir/build.make
Shortest-Routes-I.exe: CMakeFiles/Shortest-Routes-I.dir/linkLibs.rsp
Shortest-Routes-I.exe: CMakeFiles/Shortest-Routes-I.dir/objects1.rsp
Shortest-Routes-I.exe: CMakeFiles/Shortest-Routes-I.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\jacks\CSES_Solutions\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Shortest-Routes-I.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Shortest-Routes-I.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Shortest-Routes-I.dir/build: Shortest-Routes-I.exe
.PHONY : CMakeFiles/Shortest-Routes-I.dir/build

CMakeFiles/Shortest-Routes-I.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Shortest-Routes-I.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Shortest-Routes-I.dir/clean

CMakeFiles/Shortest-Routes-I.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\jacks\CSES_Solutions C:\Users\jacks\CSES_Solutions C:\Users\jacks\CSES_Solutions\build C:\Users\jacks\CSES_Solutions\build C:\Users\jacks\CSES_Solutions\build\CMakeFiles\Shortest-Routes-I.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Shortest-Routes-I.dir/depend

