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
include CMakeFiles/Sliding-Window-Sum.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Sliding-Window-Sum.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Sliding-Window-Sum.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Sliding-Window-Sum.dir/flags.make

CMakeFiles/Sliding-Window-Sum.dir/codegen:
.PHONY : CMakeFiles/Sliding-Window-Sum.dir/codegen

CMakeFiles/Sliding-Window-Sum.dir/Sliding-Window-Problems/Sliding-Window-Sum.cpp.obj: CMakeFiles/Sliding-Window-Sum.dir/flags.make
CMakeFiles/Sliding-Window-Sum.dir/Sliding-Window-Problems/Sliding-Window-Sum.cpp.obj: C:/Users/jacks/CSES_Solutions/Sliding-Window-Problems/Sliding-Window-Sum.cpp
CMakeFiles/Sliding-Window-Sum.dir/Sliding-Window-Problems/Sliding-Window-Sum.cpp.obj: CMakeFiles/Sliding-Window-Sum.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\jacks\CSES_Solutions\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Sliding-Window-Sum.dir/Sliding-Window-Problems/Sliding-Window-Sum.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Sliding-Window-Sum.dir/Sliding-Window-Problems/Sliding-Window-Sum.cpp.obj -MF CMakeFiles\Sliding-Window-Sum.dir\Sliding-Window-Problems\Sliding-Window-Sum.cpp.obj.d -o CMakeFiles\Sliding-Window-Sum.dir\Sliding-Window-Problems\Sliding-Window-Sum.cpp.obj -c C:\Users\jacks\CSES_Solutions\Sliding-Window-Problems\Sliding-Window-Sum.cpp

CMakeFiles/Sliding-Window-Sum.dir/Sliding-Window-Problems/Sliding-Window-Sum.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Sliding-Window-Sum.dir/Sliding-Window-Problems/Sliding-Window-Sum.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\jacks\CSES_Solutions\Sliding-Window-Problems\Sliding-Window-Sum.cpp > CMakeFiles\Sliding-Window-Sum.dir\Sliding-Window-Problems\Sliding-Window-Sum.cpp.i

CMakeFiles/Sliding-Window-Sum.dir/Sliding-Window-Problems/Sliding-Window-Sum.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Sliding-Window-Sum.dir/Sliding-Window-Problems/Sliding-Window-Sum.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\jacks\CSES_Solutions\Sliding-Window-Problems\Sliding-Window-Sum.cpp -o CMakeFiles\Sliding-Window-Sum.dir\Sliding-Window-Problems\Sliding-Window-Sum.cpp.s

# Object files for target Sliding-Window-Sum
Sliding__Window__Sum_OBJECTS = \
"CMakeFiles/Sliding-Window-Sum.dir/Sliding-Window-Problems/Sliding-Window-Sum.cpp.obj"

# External object files for target Sliding-Window-Sum
Sliding__Window__Sum_EXTERNAL_OBJECTS =

Sliding-Window-Sum.exe: CMakeFiles/Sliding-Window-Sum.dir/Sliding-Window-Problems/Sliding-Window-Sum.cpp.obj
Sliding-Window-Sum.exe: CMakeFiles/Sliding-Window-Sum.dir/build.make
Sliding-Window-Sum.exe: CMakeFiles/Sliding-Window-Sum.dir/linkLibs.rsp
Sliding-Window-Sum.exe: CMakeFiles/Sliding-Window-Sum.dir/objects1.rsp
Sliding-Window-Sum.exe: CMakeFiles/Sliding-Window-Sum.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\jacks\CSES_Solutions\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Sliding-Window-Sum.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Sliding-Window-Sum.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Sliding-Window-Sum.dir/build: Sliding-Window-Sum.exe
.PHONY : CMakeFiles/Sliding-Window-Sum.dir/build

CMakeFiles/Sliding-Window-Sum.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Sliding-Window-Sum.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Sliding-Window-Sum.dir/clean

CMakeFiles/Sliding-Window-Sum.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\jacks\CSES_Solutions C:\Users\jacks\CSES_Solutions C:\Users\jacks\CSES_Solutions\build C:\Users\jacks\CSES_Solutions\build C:\Users\jacks\CSES_Solutions\build\CMakeFiles\Sliding-Window-Sum.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Sliding-Window-Sum.dir/depend

