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
include CMakeFiles/Chessboard-And-Queens.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Chessboard-And-Queens.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Chessboard-And-Queens.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Chessboard-And-Queens.dir/flags.make

CMakeFiles/Chessboard-And-Queens.dir/codegen:
.PHONY : CMakeFiles/Chessboard-And-Queens.dir/codegen

CMakeFiles/Chessboard-And-Queens.dir/Introductory-Problems/Chessboard-And-Queens.cpp.obj: CMakeFiles/Chessboard-And-Queens.dir/flags.make
CMakeFiles/Chessboard-And-Queens.dir/Introductory-Problems/Chessboard-And-Queens.cpp.obj: C:/Users/jacks/CSES_Solutions/Introductory-Problems/Chessboard-And-Queens.cpp
CMakeFiles/Chessboard-And-Queens.dir/Introductory-Problems/Chessboard-And-Queens.cpp.obj: CMakeFiles/Chessboard-And-Queens.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\jacks\CSES_Solutions\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Chessboard-And-Queens.dir/Introductory-Problems/Chessboard-And-Queens.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Chessboard-And-Queens.dir/Introductory-Problems/Chessboard-And-Queens.cpp.obj -MF CMakeFiles\Chessboard-And-Queens.dir\Introductory-Problems\Chessboard-And-Queens.cpp.obj.d -o CMakeFiles\Chessboard-And-Queens.dir\Introductory-Problems\Chessboard-And-Queens.cpp.obj -c C:\Users\jacks\CSES_Solutions\Introductory-Problems\Chessboard-And-Queens.cpp

CMakeFiles/Chessboard-And-Queens.dir/Introductory-Problems/Chessboard-And-Queens.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Chessboard-And-Queens.dir/Introductory-Problems/Chessboard-And-Queens.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\jacks\CSES_Solutions\Introductory-Problems\Chessboard-And-Queens.cpp > CMakeFiles\Chessboard-And-Queens.dir\Introductory-Problems\Chessboard-And-Queens.cpp.i

CMakeFiles/Chessboard-And-Queens.dir/Introductory-Problems/Chessboard-And-Queens.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Chessboard-And-Queens.dir/Introductory-Problems/Chessboard-And-Queens.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\jacks\CSES_Solutions\Introductory-Problems\Chessboard-And-Queens.cpp -o CMakeFiles\Chessboard-And-Queens.dir\Introductory-Problems\Chessboard-And-Queens.cpp.s

# Object files for target Chessboard-And-Queens
Chessboard__And__Queens_OBJECTS = \
"CMakeFiles/Chessboard-And-Queens.dir/Introductory-Problems/Chessboard-And-Queens.cpp.obj"

# External object files for target Chessboard-And-Queens
Chessboard__And__Queens_EXTERNAL_OBJECTS =

Chessboard-And-Queens.exe: CMakeFiles/Chessboard-And-Queens.dir/Introductory-Problems/Chessboard-And-Queens.cpp.obj
Chessboard-And-Queens.exe: CMakeFiles/Chessboard-And-Queens.dir/build.make
Chessboard-And-Queens.exe: CMakeFiles/Chessboard-And-Queens.dir/linkLibs.rsp
Chessboard-And-Queens.exe: CMakeFiles/Chessboard-And-Queens.dir/objects1.rsp
Chessboard-And-Queens.exe: CMakeFiles/Chessboard-And-Queens.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\jacks\CSES_Solutions\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Chessboard-And-Queens.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Chessboard-And-Queens.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Chessboard-And-Queens.dir/build: Chessboard-And-Queens.exe
.PHONY : CMakeFiles/Chessboard-And-Queens.dir/build

CMakeFiles/Chessboard-And-Queens.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Chessboard-And-Queens.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Chessboard-And-Queens.dir/clean

CMakeFiles/Chessboard-And-Queens.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\jacks\CSES_Solutions C:\Users\jacks\CSES_Solutions C:\Users\jacks\CSES_Solutions\build C:\Users\jacks\CSES_Solutions\build C:\Users\jacks\CSES_Solutions\build\CMakeFiles\Chessboard-And-Queens.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Chessboard-And-Queens.dir/depend

