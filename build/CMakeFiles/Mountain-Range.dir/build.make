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
include CMakeFiles/Mountain-Range.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Mountain-Range.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Mountain-Range.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Mountain-Range.dir/flags.make

CMakeFiles/Mountain-Range.dir/codegen:
.PHONY : CMakeFiles/Mountain-Range.dir/codegen

CMakeFiles/Mountain-Range.dir/Dynamic-Programming/Mountain-Range.cpp.obj: CMakeFiles/Mountain-Range.dir/flags.make
CMakeFiles/Mountain-Range.dir/Dynamic-Programming/Mountain-Range.cpp.obj: C:/Users/jacks/CSES_Solutions/Dynamic-Programming/Mountain-Range.cpp
CMakeFiles/Mountain-Range.dir/Dynamic-Programming/Mountain-Range.cpp.obj: CMakeFiles/Mountain-Range.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\jacks\CSES_Solutions\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Mountain-Range.dir/Dynamic-Programming/Mountain-Range.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Mountain-Range.dir/Dynamic-Programming/Mountain-Range.cpp.obj -MF CMakeFiles\Mountain-Range.dir\Dynamic-Programming\Mountain-Range.cpp.obj.d -o CMakeFiles\Mountain-Range.dir\Dynamic-Programming\Mountain-Range.cpp.obj -c C:\Users\jacks\CSES_Solutions\Dynamic-Programming\Mountain-Range.cpp

CMakeFiles/Mountain-Range.dir/Dynamic-Programming/Mountain-Range.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Mountain-Range.dir/Dynamic-Programming/Mountain-Range.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\jacks\CSES_Solutions\Dynamic-Programming\Mountain-Range.cpp > CMakeFiles\Mountain-Range.dir\Dynamic-Programming\Mountain-Range.cpp.i

CMakeFiles/Mountain-Range.dir/Dynamic-Programming/Mountain-Range.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Mountain-Range.dir/Dynamic-Programming/Mountain-Range.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\jacks\CSES_Solutions\Dynamic-Programming\Mountain-Range.cpp -o CMakeFiles\Mountain-Range.dir\Dynamic-Programming\Mountain-Range.cpp.s

# Object files for target Mountain-Range
Mountain__Range_OBJECTS = \
"CMakeFiles/Mountain-Range.dir/Dynamic-Programming/Mountain-Range.cpp.obj"

# External object files for target Mountain-Range
Mountain__Range_EXTERNAL_OBJECTS =

Mountain-Range.exe: CMakeFiles/Mountain-Range.dir/Dynamic-Programming/Mountain-Range.cpp.obj
Mountain-Range.exe: CMakeFiles/Mountain-Range.dir/build.make
Mountain-Range.exe: CMakeFiles/Mountain-Range.dir/linkLibs.rsp
Mountain-Range.exe: CMakeFiles/Mountain-Range.dir/objects1.rsp
Mountain-Range.exe: CMakeFiles/Mountain-Range.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\jacks\CSES_Solutions\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Mountain-Range.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Mountain-Range.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Mountain-Range.dir/build: Mountain-Range.exe
.PHONY : CMakeFiles/Mountain-Range.dir/build

CMakeFiles/Mountain-Range.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Mountain-Range.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Mountain-Range.dir/clean

CMakeFiles/Mountain-Range.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\jacks\CSES_Solutions C:\Users\jacks\CSES_Solutions C:\Users\jacks\CSES_Solutions\build C:\Users\jacks\CSES_Solutions\build C:\Users\jacks\CSES_Solutions\build\CMakeFiles\Mountain-Range.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Mountain-Range.dir/depend

