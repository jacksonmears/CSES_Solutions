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
include CMakeFiles/Distinct-Value-Subsequences.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Distinct-Value-Subsequences.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Distinct-Value-Subsequences.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Distinct-Value-Subsequences.dir/flags.make

CMakeFiles/Distinct-Value-Subsequences.dir/codegen:
.PHONY : CMakeFiles/Distinct-Value-Subsequences.dir/codegen

CMakeFiles/Distinct-Value-Subsequences.dir/Sorting-and-Searching/Distinct-Value-Subsequences.cpp.obj: CMakeFiles/Distinct-Value-Subsequences.dir/flags.make
CMakeFiles/Distinct-Value-Subsequences.dir/Sorting-and-Searching/Distinct-Value-Subsequences.cpp.obj: C:/Users/jacks/CSES_Solutions/Sorting-and-Searching/Distinct-Value-Subsequences.cpp
CMakeFiles/Distinct-Value-Subsequences.dir/Sorting-and-Searching/Distinct-Value-Subsequences.cpp.obj: CMakeFiles/Distinct-Value-Subsequences.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\jacks\CSES_Solutions\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Distinct-Value-Subsequences.dir/Sorting-and-Searching/Distinct-Value-Subsequences.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Distinct-Value-Subsequences.dir/Sorting-and-Searching/Distinct-Value-Subsequences.cpp.obj -MF CMakeFiles\Distinct-Value-Subsequences.dir\Sorting-and-Searching\Distinct-Value-Subsequences.cpp.obj.d -o CMakeFiles\Distinct-Value-Subsequences.dir\Sorting-and-Searching\Distinct-Value-Subsequences.cpp.obj -c C:\Users\jacks\CSES_Solutions\Sorting-and-Searching\Distinct-Value-Subsequences.cpp

CMakeFiles/Distinct-Value-Subsequences.dir/Sorting-and-Searching/Distinct-Value-Subsequences.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Distinct-Value-Subsequences.dir/Sorting-and-Searching/Distinct-Value-Subsequences.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\jacks\CSES_Solutions\Sorting-and-Searching\Distinct-Value-Subsequences.cpp > CMakeFiles\Distinct-Value-Subsequences.dir\Sorting-and-Searching\Distinct-Value-Subsequences.cpp.i

CMakeFiles/Distinct-Value-Subsequences.dir/Sorting-and-Searching/Distinct-Value-Subsequences.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Distinct-Value-Subsequences.dir/Sorting-and-Searching/Distinct-Value-Subsequences.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\jacks\CSES_Solutions\Sorting-and-Searching\Distinct-Value-Subsequences.cpp -o CMakeFiles\Distinct-Value-Subsequences.dir\Sorting-and-Searching\Distinct-Value-Subsequences.cpp.s

# Object files for target Distinct-Value-Subsequences
Distinct__Value__Subsequences_OBJECTS = \
"CMakeFiles/Distinct-Value-Subsequences.dir/Sorting-and-Searching/Distinct-Value-Subsequences.cpp.obj"

# External object files for target Distinct-Value-Subsequences
Distinct__Value__Subsequences_EXTERNAL_OBJECTS =

Distinct-Value-Subsequences.exe: CMakeFiles/Distinct-Value-Subsequences.dir/Sorting-and-Searching/Distinct-Value-Subsequences.cpp.obj
Distinct-Value-Subsequences.exe: CMakeFiles/Distinct-Value-Subsequences.dir/build.make
Distinct-Value-Subsequences.exe: CMakeFiles/Distinct-Value-Subsequences.dir/linkLibs.rsp
Distinct-Value-Subsequences.exe: CMakeFiles/Distinct-Value-Subsequences.dir/objects1.rsp
Distinct-Value-Subsequences.exe: CMakeFiles/Distinct-Value-Subsequences.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\jacks\CSES_Solutions\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Distinct-Value-Subsequences.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Distinct-Value-Subsequences.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Distinct-Value-Subsequences.dir/build: Distinct-Value-Subsequences.exe
.PHONY : CMakeFiles/Distinct-Value-Subsequences.dir/build

CMakeFiles/Distinct-Value-Subsequences.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Distinct-Value-Subsequences.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Distinct-Value-Subsequences.dir/clean

CMakeFiles/Distinct-Value-Subsequences.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\jacks\CSES_Solutions C:\Users\jacks\CSES_Solutions C:\Users\jacks\CSES_Solutions\build C:\Users\jacks\CSES_Solutions\build C:\Users\jacks\CSES_Solutions\build\CMakeFiles\Distinct-Value-Subsequences.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Distinct-Value-Subsequences.dir/depend

