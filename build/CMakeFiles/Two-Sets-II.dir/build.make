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
include CMakeFiles/Two-Sets-II.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Two-Sets-II.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Two-Sets-II.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Two-Sets-II.dir/flags.make

CMakeFiles/Two-Sets-II.dir/codegen:
.PHONY : CMakeFiles/Two-Sets-II.dir/codegen

CMakeFiles/Two-Sets-II.dir/Dynamic-Programming/Two-Sets-II.cpp.obj: CMakeFiles/Two-Sets-II.dir/flags.make
CMakeFiles/Two-Sets-II.dir/Dynamic-Programming/Two-Sets-II.cpp.obj: C:/Users/jacks/CSES_Solutions/Dynamic-Programming/Two-Sets-II.cpp
CMakeFiles/Two-Sets-II.dir/Dynamic-Programming/Two-Sets-II.cpp.obj: CMakeFiles/Two-Sets-II.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\jacks\CSES_Solutions\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Two-Sets-II.dir/Dynamic-Programming/Two-Sets-II.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Two-Sets-II.dir/Dynamic-Programming/Two-Sets-II.cpp.obj -MF CMakeFiles\Two-Sets-II.dir\Dynamic-Programming\Two-Sets-II.cpp.obj.d -o CMakeFiles\Two-Sets-II.dir\Dynamic-Programming\Two-Sets-II.cpp.obj -c C:\Users\jacks\CSES_Solutions\Dynamic-Programming\Two-Sets-II.cpp

CMakeFiles/Two-Sets-II.dir/Dynamic-Programming/Two-Sets-II.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Two-Sets-II.dir/Dynamic-Programming/Two-Sets-II.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\jacks\CSES_Solutions\Dynamic-Programming\Two-Sets-II.cpp > CMakeFiles\Two-Sets-II.dir\Dynamic-Programming\Two-Sets-II.cpp.i

CMakeFiles/Two-Sets-II.dir/Dynamic-Programming/Two-Sets-II.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Two-Sets-II.dir/Dynamic-Programming/Two-Sets-II.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\jacks\CSES_Solutions\Dynamic-Programming\Two-Sets-II.cpp -o CMakeFiles\Two-Sets-II.dir\Dynamic-Programming\Two-Sets-II.cpp.s

# Object files for target Two-Sets-II
Two__Sets__II_OBJECTS = \
"CMakeFiles/Two-Sets-II.dir/Dynamic-Programming/Two-Sets-II.cpp.obj"

# External object files for target Two-Sets-II
Two__Sets__II_EXTERNAL_OBJECTS =

Two-Sets-II.exe: CMakeFiles/Two-Sets-II.dir/Dynamic-Programming/Two-Sets-II.cpp.obj
Two-Sets-II.exe: CMakeFiles/Two-Sets-II.dir/build.make
Two-Sets-II.exe: CMakeFiles/Two-Sets-II.dir/linkLibs.rsp
Two-Sets-II.exe: CMakeFiles/Two-Sets-II.dir/objects1.rsp
Two-Sets-II.exe: CMakeFiles/Two-Sets-II.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\jacks\CSES_Solutions\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Two-Sets-II.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Two-Sets-II.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Two-Sets-II.dir/build: Two-Sets-II.exe
.PHONY : CMakeFiles/Two-Sets-II.dir/build

CMakeFiles/Two-Sets-II.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Two-Sets-II.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Two-Sets-II.dir/clean

CMakeFiles/Two-Sets-II.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\jacks\CSES_Solutions C:\Users\jacks\CSES_Solutions C:\Users\jacks\CSES_Solutions\build C:\Users\jacks\CSES_Solutions\build C:\Users\jacks\CSES_Solutions\build\CMakeFiles\Two-Sets-II.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Two-Sets-II.dir/depend

