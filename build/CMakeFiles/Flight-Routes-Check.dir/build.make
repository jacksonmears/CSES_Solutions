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
include CMakeFiles/Flight-Routes-Check.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Flight-Routes-Check.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Flight-Routes-Check.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Flight-Routes-Check.dir/flags.make

CMakeFiles/Flight-Routes-Check.dir/codegen:
.PHONY : CMakeFiles/Flight-Routes-Check.dir/codegen

CMakeFiles/Flight-Routes-Check.dir/Graph-Algorithms/Flight-Routes-Check.cpp.obj: CMakeFiles/Flight-Routes-Check.dir/flags.make
CMakeFiles/Flight-Routes-Check.dir/Graph-Algorithms/Flight-Routes-Check.cpp.obj: C:/Users/jacks/CSES_Solutions/Graph-Algorithms/Flight-Routes-Check.cpp
CMakeFiles/Flight-Routes-Check.dir/Graph-Algorithms/Flight-Routes-Check.cpp.obj: CMakeFiles/Flight-Routes-Check.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\jacks\CSES_Solutions\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Flight-Routes-Check.dir/Graph-Algorithms/Flight-Routes-Check.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Flight-Routes-Check.dir/Graph-Algorithms/Flight-Routes-Check.cpp.obj -MF CMakeFiles\Flight-Routes-Check.dir\Graph-Algorithms\Flight-Routes-Check.cpp.obj.d -o CMakeFiles\Flight-Routes-Check.dir\Graph-Algorithms\Flight-Routes-Check.cpp.obj -c C:\Users\jacks\CSES_Solutions\Graph-Algorithms\Flight-Routes-Check.cpp

CMakeFiles/Flight-Routes-Check.dir/Graph-Algorithms/Flight-Routes-Check.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Flight-Routes-Check.dir/Graph-Algorithms/Flight-Routes-Check.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\jacks\CSES_Solutions\Graph-Algorithms\Flight-Routes-Check.cpp > CMakeFiles\Flight-Routes-Check.dir\Graph-Algorithms\Flight-Routes-Check.cpp.i

CMakeFiles/Flight-Routes-Check.dir/Graph-Algorithms/Flight-Routes-Check.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Flight-Routes-Check.dir/Graph-Algorithms/Flight-Routes-Check.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\jacks\CSES_Solutions\Graph-Algorithms\Flight-Routes-Check.cpp -o CMakeFiles\Flight-Routes-Check.dir\Graph-Algorithms\Flight-Routes-Check.cpp.s

# Object files for target Flight-Routes-Check
Flight__Routes__Check_OBJECTS = \
"CMakeFiles/Flight-Routes-Check.dir/Graph-Algorithms/Flight-Routes-Check.cpp.obj"

# External object files for target Flight-Routes-Check
Flight__Routes__Check_EXTERNAL_OBJECTS =

Flight-Routes-Check.exe: CMakeFiles/Flight-Routes-Check.dir/Graph-Algorithms/Flight-Routes-Check.cpp.obj
Flight-Routes-Check.exe: CMakeFiles/Flight-Routes-Check.dir/build.make
Flight-Routes-Check.exe: CMakeFiles/Flight-Routes-Check.dir/linkLibs.rsp
Flight-Routes-Check.exe: CMakeFiles/Flight-Routes-Check.dir/objects1.rsp
Flight-Routes-Check.exe: CMakeFiles/Flight-Routes-Check.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\jacks\CSES_Solutions\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Flight-Routes-Check.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Flight-Routes-Check.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Flight-Routes-Check.dir/build: Flight-Routes-Check.exe
.PHONY : CMakeFiles/Flight-Routes-Check.dir/build

CMakeFiles/Flight-Routes-Check.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Flight-Routes-Check.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Flight-Routes-Check.dir/clean

CMakeFiles/Flight-Routes-Check.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\jacks\CSES_Solutions C:\Users\jacks\CSES_Solutions C:\Users\jacks\CSES_Solutions\build C:\Users\jacks\CSES_Solutions\build C:\Users\jacks\CSES_Solutions\build\CMakeFiles\Flight-Routes-Check.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Flight-Routes-Check.dir/depend

