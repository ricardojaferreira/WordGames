# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ricardo/Documents/clion-workspace/WordGames

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ricardo/Documents/clion-workspace/WordGames/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Projecto.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Projecto.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Projecto.dir/flags.make

CMakeFiles/Projecto.dir/main.cpp.o: CMakeFiles/Projecto.dir/flags.make
CMakeFiles/Projecto.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ricardo/Documents/clion-workspace/WordGames/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Projecto.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Projecto.dir/main.cpp.o -c /Users/ricardo/Documents/clion-workspace/WordGames/main.cpp

CMakeFiles/Projecto.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Projecto.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ricardo/Documents/clion-workspace/WordGames/main.cpp > CMakeFiles/Projecto.dir/main.cpp.i

CMakeFiles/Projecto.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Projecto.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ricardo/Documents/clion-workspace/WordGames/main.cpp -o CMakeFiles/Projecto.dir/main.cpp.s

CMakeFiles/Projecto.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/Projecto.dir/main.cpp.o.requires

CMakeFiles/Projecto.dir/main.cpp.o.provides: CMakeFiles/Projecto.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Projecto.dir/build.make CMakeFiles/Projecto.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Projecto.dir/main.cpp.o.provides

CMakeFiles/Projecto.dir/main.cpp.o.provides.build: CMakeFiles/Projecto.dir/main.cpp.o


# Object files for target Projecto
Projecto_OBJECTS = \
"CMakeFiles/Projecto.dir/main.cpp.o"

# External object files for target Projecto
Projecto_EXTERNAL_OBJECTS =

Projecto: CMakeFiles/Projecto.dir/main.cpp.o
Projecto: CMakeFiles/Projecto.dir/build.make
Projecto: CMakeFiles/Projecto.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ricardo/Documents/clion-workspace/WordGames/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Projecto"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Projecto.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Projecto.dir/build: Projecto

.PHONY : CMakeFiles/Projecto.dir/build

CMakeFiles/Projecto.dir/requires: CMakeFiles/Projecto.dir/main.cpp.o.requires

.PHONY : CMakeFiles/Projecto.dir/requires

CMakeFiles/Projecto.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Projecto.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Projecto.dir/clean

CMakeFiles/Projecto.dir/depend:
	cd /Users/ricardo/Documents/clion-workspace/WordGames/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ricardo/Documents/clion-workspace/WordGames /Users/ricardo/Documents/clion-workspace/WordGames /Users/ricardo/Documents/clion-workspace/WordGames/cmake-build-debug /Users/ricardo/Documents/clion-workspace/WordGames/cmake-build-debug /Users/ricardo/Documents/clion-workspace/WordGames/cmake-build-debug/CMakeFiles/Projecto.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Projecto.dir/depend

