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
include CMakeFiles/Two-Knights.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Two-Knights.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Two-Knights.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Two-Knights.dir/flags.make

CMakeFiles/Two-Knights.dir/codegen:
.PHONY : CMakeFiles/Two-Knights.dir/codegen

CMakeFiles/Two-Knights.dir/Introductory-Problems/Two-Knights.cpp.obj: CMakeFiles/Two-Knights.dir/flags.make
CMakeFiles/Two-Knights.dir/Introductory-Problems/Two-Knights.cpp.obj: C:/Users/jacks/CSES_Solutions/Introductory-Problems/Two-Knights.cpp
CMakeFiles/Two-Knights.dir/Introductory-Problems/Two-Knights.cpp.obj: CMakeFiles/Two-Knights.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\jacks\CSES_Solutions\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Two-Knights.dir/Introductory-Problems/Two-Knights.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Two-Knights.dir/Introductory-Problems/Two-Knights.cpp.obj -MF CMakeFiles\Two-Knights.dir\Introductory-Problems\Two-Knights.cpp.obj.d -o CMakeFiles\Two-Knights.dir\Introductory-Problems\Two-Knights.cpp.obj -c C:\Users\jacks\CSES_Solutions\Introductory-Problems\Two-Knights.cpp

CMakeFiles/Two-Knights.dir/Introductory-Problems/Two-Knights.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Two-Knights.dir/Introductory-Problems/Two-Knights.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\jacks\CSES_Solutions\Introductory-Problems\Two-Knights.cpp > CMakeFiles\Two-Knights.dir\Introductory-Problems\Two-Knights.cpp.i

CMakeFiles/Two-Knights.dir/Introductory-Problems/Two-Knights.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Two-Knights.dir/Introductory-Problems/Two-Knights.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\jacks\CSES_Solutions\Introductory-Problems\Two-Knights.cpp -o CMakeFiles\Two-Knights.dir\Introductory-Problems\Two-Knights.cpp.s

# Object files for target Two-Knights
Two__Knights_OBJECTS = \
"CMakeFiles/Two-Knights.dir/Introductory-Problems/Two-Knights.cpp.obj"

# External object files for target Two-Knights
Two__Knights_EXTERNAL_OBJECTS =

Two-Knights.exe: CMakeFiles/Two-Knights.dir/Introductory-Problems/Two-Knights.cpp.obj
Two-Knights.exe: CMakeFiles/Two-Knights.dir/build.make
Two-Knights.exe: CMakeFiles/Two-Knights.dir/linkLibs.rsp
Two-Knights.exe: CMakeFiles/Two-Knights.dir/objects1.rsp
Two-Knights.exe: CMakeFiles/Two-Knights.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\jacks\CSES_Solutions\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Two-Knights.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Two-Knights.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Two-Knights.dir/build: Two-Knights.exe
.PHONY : CMakeFiles/Two-Knights.dir/build

CMakeFiles/Two-Knights.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Two-Knights.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Two-Knights.dir/clean

CMakeFiles/Two-Knights.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\jacks\CSES_Solutions C:\Users\jacks\CSES_Solutions C:\Users\jacks\CSES_Solutions\build C:\Users\jacks\CSES_Solutions\build C:\Users\jacks\CSES_Solutions\build\CMakeFiles\Two-Knights.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Two-Knights.dir/depend

