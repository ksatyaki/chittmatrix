# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ace/chitt_workspace/eclipse_workspace/ChittMatrix

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ace/chitt_workspace/eclipse_workspace/ChittMatrix

# Include any dependencies generated for this target.
include CMakeFiles/chittmatrix.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/chittmatrix.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/chittmatrix.dir/flags.make

CMakeFiles/chittmatrix.dir/src/Matrix.cpp.o: CMakeFiles/chittmatrix.dir/flags.make
CMakeFiles/chittmatrix.dir/src/Matrix.cpp.o: src/Matrix.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ace/chitt_workspace/eclipse_workspace/ChittMatrix/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/chittmatrix.dir/src/Matrix.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/chittmatrix.dir/src/Matrix.cpp.o -c /home/ace/chitt_workspace/eclipse_workspace/ChittMatrix/src/Matrix.cpp

CMakeFiles/chittmatrix.dir/src/Matrix.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chittmatrix.dir/src/Matrix.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ace/chitt_workspace/eclipse_workspace/ChittMatrix/src/Matrix.cpp > CMakeFiles/chittmatrix.dir/src/Matrix.cpp.i

CMakeFiles/chittmatrix.dir/src/Matrix.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chittmatrix.dir/src/Matrix.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ace/chitt_workspace/eclipse_workspace/ChittMatrix/src/Matrix.cpp -o CMakeFiles/chittmatrix.dir/src/Matrix.cpp.s

CMakeFiles/chittmatrix.dir/src/Matrix.cpp.o.requires:
.PHONY : CMakeFiles/chittmatrix.dir/src/Matrix.cpp.o.requires

CMakeFiles/chittmatrix.dir/src/Matrix.cpp.o.provides: CMakeFiles/chittmatrix.dir/src/Matrix.cpp.o.requires
	$(MAKE) -f CMakeFiles/chittmatrix.dir/build.make CMakeFiles/chittmatrix.dir/src/Matrix.cpp.o.provides.build
.PHONY : CMakeFiles/chittmatrix.dir/src/Matrix.cpp.o.provides

CMakeFiles/chittmatrix.dir/src/Matrix.cpp.o.provides.build: CMakeFiles/chittmatrix.dir/src/Matrix.cpp.o

# Object files for target chittmatrix
chittmatrix_OBJECTS = \
"CMakeFiles/chittmatrix.dir/src/Matrix.cpp.o"

# External object files for target chittmatrix
chittmatrix_EXTERNAL_OBJECTS =

lib/libchittmatrix.so: CMakeFiles/chittmatrix.dir/src/Matrix.cpp.o
lib/libchittmatrix.so: CMakeFiles/chittmatrix.dir/build.make
lib/libchittmatrix.so: CMakeFiles/chittmatrix.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared library lib/libchittmatrix.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/chittmatrix.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/chittmatrix.dir/build: lib/libchittmatrix.so
.PHONY : CMakeFiles/chittmatrix.dir/build

CMakeFiles/chittmatrix.dir/requires: CMakeFiles/chittmatrix.dir/src/Matrix.cpp.o.requires
.PHONY : CMakeFiles/chittmatrix.dir/requires

CMakeFiles/chittmatrix.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/chittmatrix.dir/cmake_clean.cmake
.PHONY : CMakeFiles/chittmatrix.dir/clean

CMakeFiles/chittmatrix.dir/depend:
	cd /home/ace/chitt_workspace/eclipse_workspace/ChittMatrix && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ace/chitt_workspace/eclipse_workspace/ChittMatrix /home/ace/chitt_workspace/eclipse_workspace/ChittMatrix /home/ace/chitt_workspace/eclipse_workspace/ChittMatrix /home/ace/chitt_workspace/eclipse_workspace/ChittMatrix /home/ace/chitt_workspace/eclipse_workspace/ChittMatrix/CMakeFiles/chittmatrix.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/chittmatrix.dir/depend

