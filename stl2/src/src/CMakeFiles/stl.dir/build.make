# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = "/home/ana/Objektno C++/stl2-anaparac"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/ana/Objektno C++/stl2-anaparac/src"

# Include any dependencies generated for this target.
include src/CMakeFiles/stl.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/stl.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/stl.dir/flags.make

src/CMakeFiles/stl.dir/main.cpp.o: src/CMakeFiles/stl.dir/flags.make
src/CMakeFiles/stl.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/ana/Objektno C++/stl2-anaparac/src/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/stl.dir/main.cpp.o"
	cd "/home/ana/Objektno C++/stl2-anaparac/src/src" && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/stl.dir/main.cpp.o -c "/home/ana/Objektno C++/stl2-anaparac/src/main.cpp"

src/CMakeFiles/stl.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stl.dir/main.cpp.i"
	cd "/home/ana/Objektno C++/stl2-anaparac/src/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/ana/Objektno C++/stl2-anaparac/src/main.cpp" > CMakeFiles/stl.dir/main.cpp.i

src/CMakeFiles/stl.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stl.dir/main.cpp.s"
	cd "/home/ana/Objektno C++/stl2-anaparac/src/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/ana/Objektno C++/stl2-anaparac/src/main.cpp" -o CMakeFiles/stl.dir/main.cpp.s

src/CMakeFiles/stl.dir/main.cpp.o.requires:

.PHONY : src/CMakeFiles/stl.dir/main.cpp.o.requires

src/CMakeFiles/stl.dir/main.cpp.o.provides: src/CMakeFiles/stl.dir/main.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/stl.dir/build.make src/CMakeFiles/stl.dir/main.cpp.o.provides.build
.PHONY : src/CMakeFiles/stl.dir/main.cpp.o.provides

src/CMakeFiles/stl.dir/main.cpp.o.provides.build: src/CMakeFiles/stl.dir/main.cpp.o


# Object files for target stl
stl_OBJECTS = \
"CMakeFiles/stl.dir/main.cpp.o"

# External object files for target stl
stl_EXTERNAL_OBJECTS =

src/stl: src/CMakeFiles/stl.dir/main.cpp.o
src/stl: src/CMakeFiles/stl.dir/build.make
src/stl: src/libstl_lib.a
src/stl: src/CMakeFiles/stl.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/ana/Objektno C++/stl2-anaparac/src/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable stl"
	cd "/home/ana/Objektno C++/stl2-anaparac/src/src" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/stl.dir/link.txt --verbose=$(VERBOSE)
	cd "/home/ana/Objektno C++/stl2-anaparac/src/src" && /usr/bin/cmake -E copy /home/ana/Objektno\ C++/stl2-anaparac/src/*.txt /home/ana/Objektno\ C++/stl2-anaparac/src/src

# Rule to build all files generated by this target.
src/CMakeFiles/stl.dir/build: src/stl

.PHONY : src/CMakeFiles/stl.dir/build

src/CMakeFiles/stl.dir/requires: src/CMakeFiles/stl.dir/main.cpp.o.requires

.PHONY : src/CMakeFiles/stl.dir/requires

src/CMakeFiles/stl.dir/clean:
	cd "/home/ana/Objektno C++/stl2-anaparac/src/src" && $(CMAKE_COMMAND) -P CMakeFiles/stl.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/stl.dir/clean

src/CMakeFiles/stl.dir/depend:
	cd "/home/ana/Objektno C++/stl2-anaparac/src" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/ana/Objektno C++/stl2-anaparac" "/home/ana/Objektno C++/stl2-anaparac/src" "/home/ana/Objektno C++/stl2-anaparac/src" "/home/ana/Objektno C++/stl2-anaparac/src/src" "/home/ana/Objektno C++/stl2-anaparac/src/src/CMakeFiles/stl.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : src/CMakeFiles/stl.dir/depend

