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
include CMakeFiles/Maximum-Xor-Subset.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Maximum-Xor-Subset.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Maximum-Xor-Subset.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Maximum-Xor-Subset.dir/flags.make

CMakeFiles/Maximum-Xor-Subset.dir/codegen:
.PHONY : CMakeFiles/Maximum-Xor-Subset.dir/codegen

CMakeFiles/Maximum-Xor-Subset.dir/Bitwise-Operations/Maximum-Xor-Subset.cpp.obj: CMakeFiles/Maximum-Xor-Subset.dir/flags.make
CMakeFiles/Maximum-Xor-Subset.dir/Bitwise-Operations/Maximum-Xor-Subset.cpp.obj: C:/Users/jacks/CSES_Solutions/Bitwise-Operations/Maximum-Xor-Subset.cpp
CMakeFiles/Maximum-Xor-Subset.dir/Bitwise-Operations/Maximum-Xor-Subset.cpp.obj: CMakeFiles/Maximum-Xor-Subset.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\jacks\CSES_Solutions\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Maximum-Xor-Subset.dir/Bitwise-Operations/Maximum-Xor-Subset.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Maximum-Xor-Subset.dir/Bitwise-Operations/Maximum-Xor-Subset.cpp.obj -MF CMakeFiles\Maximum-Xor-Subset.dir\Bitwise-Operations\Maximum-Xor-Subset.cpp.obj.d -o CMakeFiles\Maximum-Xor-Subset.dir\Bitwise-Operations\Maximum-Xor-Subset.cpp.obj -c C:\Users\jacks\CSES_Solutions\Bitwise-Operations\Maximum-Xor-Subset.cpp

CMakeFiles/Maximum-Xor-Subset.dir/Bitwise-Operations/Maximum-Xor-Subset.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Maximum-Xor-Subset.dir/Bitwise-Operations/Maximum-Xor-Subset.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\jacks\CSES_Solutions\Bitwise-Operations\Maximum-Xor-Subset.cpp > CMakeFiles\Maximum-Xor-Subset.dir\Bitwise-Operations\Maximum-Xor-Subset.cpp.i

CMakeFiles/Maximum-Xor-Subset.dir/Bitwise-Operations/Maximum-Xor-Subset.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Maximum-Xor-Subset.dir/Bitwise-Operations/Maximum-Xor-Subset.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\jacks\CSES_Solutions\Bitwise-Operations\Maximum-Xor-Subset.cpp -o CMakeFiles\Maximum-Xor-Subset.dir\Bitwise-Operations\Maximum-Xor-Subset.cpp.s

# Object files for target Maximum-Xor-Subset
Maximum__Xor__Subset_OBJECTS = \
"CMakeFiles/Maximum-Xor-Subset.dir/Bitwise-Operations/Maximum-Xor-Subset.cpp.obj"

# External object files for target Maximum-Xor-Subset
Maximum__Xor__Subset_EXTERNAL_OBJECTS =

Maximum-Xor-Subset.exe: CMakeFiles/Maximum-Xor-Subset.dir/Bitwise-Operations/Maximum-Xor-Subset.cpp.obj
Maximum-Xor-Subset.exe: CMakeFiles/Maximum-Xor-Subset.dir/build.make
Maximum-Xor-Subset.exe: CMakeFiles/Maximum-Xor-Subset.dir/linkLibs.rsp
Maximum-Xor-Subset.exe: CMakeFiles/Maximum-Xor-Subset.dir/objects1.rsp
Maximum-Xor-Subset.exe: CMakeFiles/Maximum-Xor-Subset.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\jacks\CSES_Solutions\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Maximum-Xor-Subset.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Maximum-Xor-Subset.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Maximum-Xor-Subset.dir/build: Maximum-Xor-Subset.exe
.PHONY : CMakeFiles/Maximum-Xor-Subset.dir/build

CMakeFiles/Maximum-Xor-Subset.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Maximum-Xor-Subset.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Maximum-Xor-Subset.dir/clean

CMakeFiles/Maximum-Xor-Subset.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\jacks\CSES_Solutions C:\Users\jacks\CSES_Solutions C:\Users\jacks\CSES_Solutions\build C:\Users\jacks\CSES_Solutions\build C:\Users\jacks\CSES_Solutions\build\CMakeFiles\Maximum-Xor-Subset.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Maximum-Xor-Subset.dir/depend

