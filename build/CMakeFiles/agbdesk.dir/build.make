# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/nibbyt/Projects/emulators/agbdesk

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nibbyt/Projects/emulators/agbdesk/build

# Include any dependencies generated for this target.
include CMakeFiles/agbdesk.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/agbdesk.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/agbdesk.dir/flags.make

CMakeFiles/agbdesk.dir/src/main.cpp.o: CMakeFiles/agbdesk.dir/flags.make
CMakeFiles/agbdesk.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nibbyt/Projects/emulators/agbdesk/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/agbdesk.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/agbdesk.dir/src/main.cpp.o -c /home/nibbyt/Projects/emulators/agbdesk/src/main.cpp

CMakeFiles/agbdesk.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/agbdesk.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nibbyt/Projects/emulators/agbdesk/src/main.cpp > CMakeFiles/agbdesk.dir/src/main.cpp.i

CMakeFiles/agbdesk.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/agbdesk.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nibbyt/Projects/emulators/agbdesk/src/main.cpp -o CMakeFiles/agbdesk.dir/src/main.cpp.s

CMakeFiles/agbdesk.dir/src/test/test.cpp.o: CMakeFiles/agbdesk.dir/flags.make
CMakeFiles/agbdesk.dir/src/test/test.cpp.o: ../src/test/test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nibbyt/Projects/emulators/agbdesk/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/agbdesk.dir/src/test/test.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/agbdesk.dir/src/test/test.cpp.o -c /home/nibbyt/Projects/emulators/agbdesk/src/test/test.cpp

CMakeFiles/agbdesk.dir/src/test/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/agbdesk.dir/src/test/test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nibbyt/Projects/emulators/agbdesk/src/test/test.cpp > CMakeFiles/agbdesk.dir/src/test/test.cpp.i

CMakeFiles/agbdesk.dir/src/test/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/agbdesk.dir/src/test/test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nibbyt/Projects/emulators/agbdesk/src/test/test.cpp -o CMakeFiles/agbdesk.dir/src/test/test.cpp.s

# Object files for target agbdesk
agbdesk_OBJECTS = \
"CMakeFiles/agbdesk.dir/src/main.cpp.o" \
"CMakeFiles/agbdesk.dir/src/test/test.cpp.o"

# External object files for target agbdesk
agbdesk_EXTERNAL_OBJECTS =

../bin/agbdesk: CMakeFiles/agbdesk.dir/src/main.cpp.o
../bin/agbdesk: CMakeFiles/agbdesk.dir/src/test/test.cpp.o
../bin/agbdesk: CMakeFiles/agbdesk.dir/build.make
../bin/agbdesk: CMakeFiles/agbdesk.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nibbyt/Projects/emulators/agbdesk/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ../bin/agbdesk"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/agbdesk.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/agbdesk.dir/build: ../bin/agbdesk

.PHONY : CMakeFiles/agbdesk.dir/build

CMakeFiles/agbdesk.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/agbdesk.dir/cmake_clean.cmake
.PHONY : CMakeFiles/agbdesk.dir/clean

CMakeFiles/agbdesk.dir/depend:
	cd /home/nibbyt/Projects/emulators/agbdesk/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nibbyt/Projects/emulators/agbdesk /home/nibbyt/Projects/emulators/agbdesk /home/nibbyt/Projects/emulators/agbdesk/build /home/nibbyt/Projects/emulators/agbdesk/build /home/nibbyt/Projects/emulators/agbdesk/build/CMakeFiles/agbdesk.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/agbdesk.dir/depend
