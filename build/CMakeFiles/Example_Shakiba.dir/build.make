# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/gnt/Desktop/test/stepping

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/gnt/Desktop/test/stepping/build

# Utility rule file for Example_Shakiba.

# Include the progress variables for this target.
include CMakeFiles/Example_Shakiba.dir/progress.make

CMakeFiles/Example_Shakiba: sim


Example_Shakiba: CMakeFiles/Example_Shakiba
Example_Shakiba: CMakeFiles/Example_Shakiba.dir/build.make

.PHONY : Example_Shakiba

# Rule to build all files generated by this target.
CMakeFiles/Example_Shakiba.dir/build: Example_Shakiba

.PHONY : CMakeFiles/Example_Shakiba.dir/build

CMakeFiles/Example_Shakiba.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Example_Shakiba.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Example_Shakiba.dir/clean

CMakeFiles/Example_Shakiba.dir/depend:
	cd /home/gnt/Desktop/test/stepping/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gnt/Desktop/test/stepping /home/gnt/Desktop/test/stepping /home/gnt/Desktop/test/stepping/build /home/gnt/Desktop/test/stepping/build /home/gnt/Desktop/test/stepping/build/CMakeFiles/Example_Shakiba.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Example_Shakiba.dir/depend
