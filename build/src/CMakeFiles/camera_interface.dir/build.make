# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.6

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canoncical targets will work.
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
CMAKE_SOURCE_DIR = /home/aduda/MyProject/camera_interface

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/aduda/MyProject/camera_interface/build

# Include any dependencies generated for this target.
include src/CMakeFiles/camera_interface.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/camera_interface.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/camera_interface.dir/flags.make

src/CMakeFiles/camera_interface.dir/CamInterface.cpp.o: src/CMakeFiles/camera_interface.dir/flags.make
src/CMakeFiles/camera_interface.dir/CamInterface.cpp.o: ../src/CamInterface.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/aduda/MyProject/camera_interface/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/camera_interface.dir/CamInterface.cpp.o"
	cd /home/aduda/MyProject/camera_interface/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/camera_interface.dir/CamInterface.cpp.o -c /home/aduda/MyProject/camera_interface/src/CamInterface.cpp

src/CMakeFiles/camera_interface.dir/CamInterface.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/camera_interface.dir/CamInterface.cpp.i"
	cd /home/aduda/MyProject/camera_interface/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/aduda/MyProject/camera_interface/src/CamInterface.cpp > CMakeFiles/camera_interface.dir/CamInterface.cpp.i

src/CMakeFiles/camera_interface.dir/CamInterface.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/camera_interface.dir/CamInterface.cpp.s"
	cd /home/aduda/MyProject/camera_interface/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/aduda/MyProject/camera_interface/src/CamInterface.cpp -o CMakeFiles/camera_interface.dir/CamInterface.cpp.s

src/CMakeFiles/camera_interface.dir/CamInterface.cpp.o.requires:
.PHONY : src/CMakeFiles/camera_interface.dir/CamInterface.cpp.o.requires

src/CMakeFiles/camera_interface.dir/CamInterface.cpp.o.provides: src/CMakeFiles/camera_interface.dir/CamInterface.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/camera_interface.dir/build.make src/CMakeFiles/camera_interface.dir/CamInterface.cpp.o.provides.build
.PHONY : src/CMakeFiles/camera_interface.dir/CamInterface.cpp.o.provides

src/CMakeFiles/camera_interface.dir/CamInterface.cpp.o.provides.build: src/CMakeFiles/camera_interface.dir/CamInterface.cpp.o
.PHONY : src/CMakeFiles/camera_interface.dir/CamInterface.cpp.o.provides.build

# Object files for target camera_interface
camera_interface_OBJECTS = \
"CMakeFiles/camera_interface.dir/CamInterface.cpp.o"

# External object files for target camera_interface
camera_interface_EXTERNAL_OBJECTS =

lib/libcamera_interface.so: src/CMakeFiles/camera_interface.dir/CamInterface.cpp.o
lib/libcamera_interface.so: src/CMakeFiles/camera_interface.dir/build.make
lib/libcamera_interface.so: src/CMakeFiles/camera_interface.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared library ../lib/libcamera_interface.so"
	cd /home/aduda/MyProject/camera_interface/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/camera_interface.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/camera_interface.dir/build: lib/libcamera_interface.so
.PHONY : src/CMakeFiles/camera_interface.dir/build

src/CMakeFiles/camera_interface.dir/requires: src/CMakeFiles/camera_interface.dir/CamInterface.cpp.o.requires
.PHONY : src/CMakeFiles/camera_interface.dir/requires

src/CMakeFiles/camera_interface.dir/clean:
	cd /home/aduda/MyProject/camera_interface/build/src && $(CMAKE_COMMAND) -P CMakeFiles/camera_interface.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/camera_interface.dir/clean

src/CMakeFiles/camera_interface.dir/depend:
	cd /home/aduda/MyProject/camera_interface/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/aduda/MyProject/camera_interface /home/aduda/MyProject/camera_interface/src /home/aduda/MyProject/camera_interface/build /home/aduda/MyProject/camera_interface/build/src /home/aduda/MyProject/camera_interface/build/src/CMakeFiles/camera_interface.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/camera_interface.dir/depend

