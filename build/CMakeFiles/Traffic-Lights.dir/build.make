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
include CMakeFiles/Traffic-Lights.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Traffic-Lights.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Traffic-Lights.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Traffic-Lights.dir/flags.make

CMakeFiles/Traffic-Lights.dir/codegen:
.PHONY : CMakeFiles/Traffic-Lights.dir/codegen

CMakeFiles/Traffic-Lights.dir/Sorting-and-Searching/Traffic-Lights.cpp.obj: CMakeFiles/Traffic-Lights.dir/flags.make
CMakeFiles/Traffic-Lights.dir/Sorting-and-Searching/Traffic-Lights.cpp.obj: C:/Users/jacks/CSES_Solutions/Sorting-and-Searching/Traffic-Lights.cpp
CMakeFiles/Traffic-Lights.dir/Sorting-and-Searching/Traffic-Lights.cpp.obj: CMakeFiles/Traffic-Lights.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\jacks\CSES_Solutions\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Traffic-Lights.dir/Sorting-and-Searching/Traffic-Lights.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Traffic-Lights.dir/Sorting-and-Searching/Traffic-Lights.cpp.obj -MF CMakeFiles\Traffic-Lights.dir\Sorting-and-Searching\Traffic-Lights.cpp.obj.d -o CMakeFiles\Traffic-Lights.dir\Sorting-and-Searching\Traffic-Lights.cpp.obj -c C:\Users\jacks\CSES_Solutions\Sorting-and-Searching\Traffic-Lights.cpp

CMakeFiles/Traffic-Lights.dir/Sorting-and-Searching/Traffic-Lights.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Traffic-Lights.dir/Sorting-and-Searching/Traffic-Lights.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\jacks\CSES_Solutions\Sorting-and-Searching\Traffic-Lights.cpp > CMakeFiles\Traffic-Lights.dir\Sorting-and-Searching\Traffic-Lights.cpp.i

CMakeFiles/Traffic-Lights.dir/Sorting-and-Searching/Traffic-Lights.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Traffic-Lights.dir/Sorting-and-Searching/Traffic-Lights.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\jacks\CSES_Solutions\Sorting-and-Searching\Traffic-Lights.cpp -o CMakeFiles\Traffic-Lights.dir\Sorting-and-Searching\Traffic-Lights.cpp.s

# Object files for target Traffic-Lights
Traffic__Lights_OBJECTS = \
"CMakeFiles/Traffic-Lights.dir/Sorting-and-Searching/Traffic-Lights.cpp.obj"

# External object files for target Traffic-Lights
Traffic__Lights_EXTERNAL_OBJECTS =

Traffic-Lights.exe: CMakeFiles/Traffic-Lights.dir/Sorting-and-Searching/Traffic-Lights.cpp.obj
Traffic-Lights.exe: CMakeFiles/Traffic-Lights.dir/build.make
Traffic-Lights.exe: CMakeFiles/Traffic-Lights.dir/linkLibs.rsp
Traffic-Lights.exe: CMakeFiles/Traffic-Lights.dir/objects1.rsp
Traffic-Lights.exe: CMakeFiles/Traffic-Lights.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\jacks\CSES_Solutions\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Traffic-Lights.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Traffic-Lights.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Traffic-Lights.dir/build: Traffic-Lights.exe
.PHONY : CMakeFiles/Traffic-Lights.dir/build

CMakeFiles/Traffic-Lights.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Traffic-Lights.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Traffic-Lights.dir/clean

CMakeFiles/Traffic-Lights.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\jacks\CSES_Solutions C:\Users\jacks\CSES_Solutions C:\Users\jacks\CSES_Solutions\build C:\Users\jacks\CSES_Solutions\build C:\Users\jacks\CSES_Solutions\build\CMakeFiles\Traffic-Lights.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Traffic-Lights.dir/depend

