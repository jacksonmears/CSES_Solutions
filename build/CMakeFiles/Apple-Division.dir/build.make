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
include CMakeFiles/Apple-Division.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Apple-Division.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Apple-Division.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Apple-Division.dir/flags.make

CMakeFiles/Apple-Division.dir/codegen:
.PHONY : CMakeFiles/Apple-Division.dir/codegen

CMakeFiles/Apple-Division.dir/Introductory-Problems/Apple-Division.cpp.obj: CMakeFiles/Apple-Division.dir/flags.make
CMakeFiles/Apple-Division.dir/Introductory-Problems/Apple-Division.cpp.obj: C:/Users/jacks/CSES_Solutions/Introductory-Problems/Apple-Division.cpp
CMakeFiles/Apple-Division.dir/Introductory-Problems/Apple-Division.cpp.obj: CMakeFiles/Apple-Division.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\jacks\CSES_Solutions\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Apple-Division.dir/Introductory-Problems/Apple-Division.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Apple-Division.dir/Introductory-Problems/Apple-Division.cpp.obj -MF CMakeFiles\Apple-Division.dir\Introductory-Problems\Apple-Division.cpp.obj.d -o CMakeFiles\Apple-Division.dir\Introductory-Problems\Apple-Division.cpp.obj -c C:\Users\jacks\CSES_Solutions\Introductory-Problems\Apple-Division.cpp

CMakeFiles/Apple-Division.dir/Introductory-Problems/Apple-Division.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Apple-Division.dir/Introductory-Problems/Apple-Division.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\jacks\CSES_Solutions\Introductory-Problems\Apple-Division.cpp > CMakeFiles\Apple-Division.dir\Introductory-Problems\Apple-Division.cpp.i

CMakeFiles/Apple-Division.dir/Introductory-Problems/Apple-Division.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Apple-Division.dir/Introductory-Problems/Apple-Division.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\jacks\CSES_Solutions\Introductory-Problems\Apple-Division.cpp -o CMakeFiles\Apple-Division.dir\Introductory-Problems\Apple-Division.cpp.s

# Object files for target Apple-Division
Apple__Division_OBJECTS = \
"CMakeFiles/Apple-Division.dir/Introductory-Problems/Apple-Division.cpp.obj"

# External object files for target Apple-Division
Apple__Division_EXTERNAL_OBJECTS =

Apple-Division.exe: CMakeFiles/Apple-Division.dir/Introductory-Problems/Apple-Division.cpp.obj
Apple-Division.exe: CMakeFiles/Apple-Division.dir/build.make
Apple-Division.exe: CMakeFiles/Apple-Division.dir/linkLibs.rsp
Apple-Division.exe: CMakeFiles/Apple-Division.dir/objects1.rsp
Apple-Division.exe: CMakeFiles/Apple-Division.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\jacks\CSES_Solutions\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Apple-Division.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Apple-Division.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Apple-Division.dir/build: Apple-Division.exe
.PHONY : CMakeFiles/Apple-Division.dir/build

CMakeFiles/Apple-Division.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Apple-Division.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Apple-Division.dir/clean

CMakeFiles/Apple-Division.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\jacks\CSES_Solutions C:\Users\jacks\CSES_Solutions C:\Users\jacks\CSES_Solutions\build C:\Users\jacks\CSES_Solutions\build C:\Users\jacks\CSES_Solutions\build\CMakeFiles\Apple-Division.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Apple-Division.dir/depend

