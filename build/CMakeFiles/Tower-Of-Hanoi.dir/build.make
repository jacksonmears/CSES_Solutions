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
include CMakeFiles/Tower-Of-Hanoi.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Tower-Of-Hanoi.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Tower-Of-Hanoi.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Tower-Of-Hanoi.dir/flags.make

CMakeFiles/Tower-Of-Hanoi.dir/codegen:
.PHONY : CMakeFiles/Tower-Of-Hanoi.dir/codegen

CMakeFiles/Tower-Of-Hanoi.dir/Introductory-Problems/Tower-Of-Hanoi.cpp.obj: CMakeFiles/Tower-Of-Hanoi.dir/flags.make
CMakeFiles/Tower-Of-Hanoi.dir/Introductory-Problems/Tower-Of-Hanoi.cpp.obj: C:/Users/jacks/CSES_Solutions/Introductory-Problems/Tower-Of-Hanoi.cpp
CMakeFiles/Tower-Of-Hanoi.dir/Introductory-Problems/Tower-Of-Hanoi.cpp.obj: CMakeFiles/Tower-Of-Hanoi.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\jacks\CSES_Solutions\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Tower-Of-Hanoi.dir/Introductory-Problems/Tower-Of-Hanoi.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Tower-Of-Hanoi.dir/Introductory-Problems/Tower-Of-Hanoi.cpp.obj -MF CMakeFiles\Tower-Of-Hanoi.dir\Introductory-Problems\Tower-Of-Hanoi.cpp.obj.d -o CMakeFiles\Tower-Of-Hanoi.dir\Introductory-Problems\Tower-Of-Hanoi.cpp.obj -c C:\Users\jacks\CSES_Solutions\Introductory-Problems\Tower-Of-Hanoi.cpp

CMakeFiles/Tower-Of-Hanoi.dir/Introductory-Problems/Tower-Of-Hanoi.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Tower-Of-Hanoi.dir/Introductory-Problems/Tower-Of-Hanoi.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\jacks\CSES_Solutions\Introductory-Problems\Tower-Of-Hanoi.cpp > CMakeFiles\Tower-Of-Hanoi.dir\Introductory-Problems\Tower-Of-Hanoi.cpp.i

CMakeFiles/Tower-Of-Hanoi.dir/Introductory-Problems/Tower-Of-Hanoi.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Tower-Of-Hanoi.dir/Introductory-Problems/Tower-Of-Hanoi.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\jacks\CSES_Solutions\Introductory-Problems\Tower-Of-Hanoi.cpp -o CMakeFiles\Tower-Of-Hanoi.dir\Introductory-Problems\Tower-Of-Hanoi.cpp.s

# Object files for target Tower-Of-Hanoi
Tower__Of__Hanoi_OBJECTS = \
"CMakeFiles/Tower-Of-Hanoi.dir/Introductory-Problems/Tower-Of-Hanoi.cpp.obj"

# External object files for target Tower-Of-Hanoi
Tower__Of__Hanoi_EXTERNAL_OBJECTS =

Tower-Of-Hanoi.exe: CMakeFiles/Tower-Of-Hanoi.dir/Introductory-Problems/Tower-Of-Hanoi.cpp.obj
Tower-Of-Hanoi.exe: CMakeFiles/Tower-Of-Hanoi.dir/build.make
Tower-Of-Hanoi.exe: CMakeFiles/Tower-Of-Hanoi.dir/linkLibs.rsp
Tower-Of-Hanoi.exe: CMakeFiles/Tower-Of-Hanoi.dir/objects1.rsp
Tower-Of-Hanoi.exe: CMakeFiles/Tower-Of-Hanoi.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\jacks\CSES_Solutions\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Tower-Of-Hanoi.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Tower-Of-Hanoi.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Tower-Of-Hanoi.dir/build: Tower-Of-Hanoi.exe
.PHONY : CMakeFiles/Tower-Of-Hanoi.dir/build

CMakeFiles/Tower-Of-Hanoi.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Tower-Of-Hanoi.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Tower-Of-Hanoi.dir/clean

CMakeFiles/Tower-Of-Hanoi.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\jacks\CSES_Solutions C:\Users\jacks\CSES_Solutions C:\Users\jacks\CSES_Solutions\build C:\Users\jacks\CSES_Solutions\build C:\Users\jacks\CSES_Solutions\build\CMakeFiles\Tower-Of-Hanoi.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Tower-Of-Hanoi.dir/depend

