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
include CMakeFiles/Array-Description.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Array-Description.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Array-Description.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Array-Description.dir/flags.make

CMakeFiles/Array-Description.dir/codegen:
.PHONY : CMakeFiles/Array-Description.dir/codegen

CMakeFiles/Array-Description.dir/Dynamic-Programming/Array-Description.cpp.obj: CMakeFiles/Array-Description.dir/flags.make
CMakeFiles/Array-Description.dir/Dynamic-Programming/Array-Description.cpp.obj: C:/Users/jacks/CSES_Solutions/Dynamic-Programming/Array-Description.cpp
CMakeFiles/Array-Description.dir/Dynamic-Programming/Array-Description.cpp.obj: CMakeFiles/Array-Description.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\jacks\CSES_Solutions\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Array-Description.dir/Dynamic-Programming/Array-Description.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Array-Description.dir/Dynamic-Programming/Array-Description.cpp.obj -MF CMakeFiles\Array-Description.dir\Dynamic-Programming\Array-Description.cpp.obj.d -o CMakeFiles\Array-Description.dir\Dynamic-Programming\Array-Description.cpp.obj -c C:\Users\jacks\CSES_Solutions\Dynamic-Programming\Array-Description.cpp

CMakeFiles/Array-Description.dir/Dynamic-Programming/Array-Description.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Array-Description.dir/Dynamic-Programming/Array-Description.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\jacks\CSES_Solutions\Dynamic-Programming\Array-Description.cpp > CMakeFiles\Array-Description.dir\Dynamic-Programming\Array-Description.cpp.i

CMakeFiles/Array-Description.dir/Dynamic-Programming/Array-Description.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Array-Description.dir/Dynamic-Programming/Array-Description.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\jacks\CSES_Solutions\Dynamic-Programming\Array-Description.cpp -o CMakeFiles\Array-Description.dir\Dynamic-Programming\Array-Description.cpp.s

# Object files for target Array-Description
Array__Description_OBJECTS = \
"CMakeFiles/Array-Description.dir/Dynamic-Programming/Array-Description.cpp.obj"

# External object files for target Array-Description
Array__Description_EXTERNAL_OBJECTS =

Array-Description.exe: CMakeFiles/Array-Description.dir/Dynamic-Programming/Array-Description.cpp.obj
Array-Description.exe: CMakeFiles/Array-Description.dir/build.make
Array-Description.exe: CMakeFiles/Array-Description.dir/linkLibs.rsp
Array-Description.exe: CMakeFiles/Array-Description.dir/objects1.rsp
Array-Description.exe: CMakeFiles/Array-Description.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\jacks\CSES_Solutions\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Array-Description.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Array-Description.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Array-Description.dir/build: Array-Description.exe
.PHONY : CMakeFiles/Array-Description.dir/build

CMakeFiles/Array-Description.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Array-Description.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Array-Description.dir/clean

CMakeFiles/Array-Description.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\jacks\CSES_Solutions C:\Users\jacks\CSES_Solutions C:\Users\jacks\CSES_Solutions\build C:\Users\jacks\CSES_Solutions\build C:\Users\jacks\CSES_Solutions\build\CMakeFiles\Array-Description.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Array-Description.dir/depend

