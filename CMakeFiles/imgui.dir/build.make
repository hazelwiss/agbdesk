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
CMAKE_BINARY_DIR = /home/nibbyt/Projects/emulators/agbdesk

# Include any dependencies generated for this target.
include CMakeFiles/imgui.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/imgui.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/imgui.dir/flags.make

CMakeFiles/imgui.dir/deps/imgui/imgui.cpp.o: CMakeFiles/imgui.dir/flags.make
CMakeFiles/imgui.dir/deps/imgui/imgui.cpp.o: deps/imgui/imgui.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nibbyt/Projects/emulators/agbdesk/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/imgui.dir/deps/imgui/imgui.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/imgui.dir/deps/imgui/imgui.cpp.o -c /home/nibbyt/Projects/emulators/agbdesk/deps/imgui/imgui.cpp

CMakeFiles/imgui.dir/deps/imgui/imgui.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/imgui.dir/deps/imgui/imgui.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nibbyt/Projects/emulators/agbdesk/deps/imgui/imgui.cpp > CMakeFiles/imgui.dir/deps/imgui/imgui.cpp.i

CMakeFiles/imgui.dir/deps/imgui/imgui.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/imgui.dir/deps/imgui/imgui.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nibbyt/Projects/emulators/agbdesk/deps/imgui/imgui.cpp -o CMakeFiles/imgui.dir/deps/imgui/imgui.cpp.s

CMakeFiles/imgui.dir/deps/imgui/imgui_demo.cpp.o: CMakeFiles/imgui.dir/flags.make
CMakeFiles/imgui.dir/deps/imgui/imgui_demo.cpp.o: deps/imgui/imgui_demo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nibbyt/Projects/emulators/agbdesk/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/imgui.dir/deps/imgui/imgui_demo.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/imgui.dir/deps/imgui/imgui_demo.cpp.o -c /home/nibbyt/Projects/emulators/agbdesk/deps/imgui/imgui_demo.cpp

CMakeFiles/imgui.dir/deps/imgui/imgui_demo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/imgui.dir/deps/imgui/imgui_demo.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nibbyt/Projects/emulators/agbdesk/deps/imgui/imgui_demo.cpp > CMakeFiles/imgui.dir/deps/imgui/imgui_demo.cpp.i

CMakeFiles/imgui.dir/deps/imgui/imgui_demo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/imgui.dir/deps/imgui/imgui_demo.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nibbyt/Projects/emulators/agbdesk/deps/imgui/imgui_demo.cpp -o CMakeFiles/imgui.dir/deps/imgui/imgui_demo.cpp.s

CMakeFiles/imgui.dir/deps/imgui/imgui_draw.cpp.o: CMakeFiles/imgui.dir/flags.make
CMakeFiles/imgui.dir/deps/imgui/imgui_draw.cpp.o: deps/imgui/imgui_draw.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nibbyt/Projects/emulators/agbdesk/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/imgui.dir/deps/imgui/imgui_draw.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/imgui.dir/deps/imgui/imgui_draw.cpp.o -c /home/nibbyt/Projects/emulators/agbdesk/deps/imgui/imgui_draw.cpp

CMakeFiles/imgui.dir/deps/imgui/imgui_draw.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/imgui.dir/deps/imgui/imgui_draw.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nibbyt/Projects/emulators/agbdesk/deps/imgui/imgui_draw.cpp > CMakeFiles/imgui.dir/deps/imgui/imgui_draw.cpp.i

CMakeFiles/imgui.dir/deps/imgui/imgui_draw.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/imgui.dir/deps/imgui/imgui_draw.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nibbyt/Projects/emulators/agbdesk/deps/imgui/imgui_draw.cpp -o CMakeFiles/imgui.dir/deps/imgui/imgui_draw.cpp.s

CMakeFiles/imgui.dir/deps/imgui/imgui_tables.cpp.o: CMakeFiles/imgui.dir/flags.make
CMakeFiles/imgui.dir/deps/imgui/imgui_tables.cpp.o: deps/imgui/imgui_tables.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nibbyt/Projects/emulators/agbdesk/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/imgui.dir/deps/imgui/imgui_tables.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/imgui.dir/deps/imgui/imgui_tables.cpp.o -c /home/nibbyt/Projects/emulators/agbdesk/deps/imgui/imgui_tables.cpp

CMakeFiles/imgui.dir/deps/imgui/imgui_tables.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/imgui.dir/deps/imgui/imgui_tables.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nibbyt/Projects/emulators/agbdesk/deps/imgui/imgui_tables.cpp > CMakeFiles/imgui.dir/deps/imgui/imgui_tables.cpp.i

CMakeFiles/imgui.dir/deps/imgui/imgui_tables.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/imgui.dir/deps/imgui/imgui_tables.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nibbyt/Projects/emulators/agbdesk/deps/imgui/imgui_tables.cpp -o CMakeFiles/imgui.dir/deps/imgui/imgui_tables.cpp.s

CMakeFiles/imgui.dir/deps/imgui/imgui_widgets.cpp.o: CMakeFiles/imgui.dir/flags.make
CMakeFiles/imgui.dir/deps/imgui/imgui_widgets.cpp.o: deps/imgui/imgui_widgets.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nibbyt/Projects/emulators/agbdesk/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/imgui.dir/deps/imgui/imgui_widgets.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/imgui.dir/deps/imgui/imgui_widgets.cpp.o -c /home/nibbyt/Projects/emulators/agbdesk/deps/imgui/imgui_widgets.cpp

CMakeFiles/imgui.dir/deps/imgui/imgui_widgets.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/imgui.dir/deps/imgui/imgui_widgets.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nibbyt/Projects/emulators/agbdesk/deps/imgui/imgui_widgets.cpp > CMakeFiles/imgui.dir/deps/imgui/imgui_widgets.cpp.i

CMakeFiles/imgui.dir/deps/imgui/imgui_widgets.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/imgui.dir/deps/imgui/imgui_widgets.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nibbyt/Projects/emulators/agbdesk/deps/imgui/imgui_widgets.cpp -o CMakeFiles/imgui.dir/deps/imgui/imgui_widgets.cpp.s

# Object files for target imgui
imgui_OBJECTS = \
"CMakeFiles/imgui.dir/deps/imgui/imgui.cpp.o" \
"CMakeFiles/imgui.dir/deps/imgui/imgui_demo.cpp.o" \
"CMakeFiles/imgui.dir/deps/imgui/imgui_draw.cpp.o" \
"CMakeFiles/imgui.dir/deps/imgui/imgui_tables.cpp.o" \
"CMakeFiles/imgui.dir/deps/imgui/imgui_widgets.cpp.o"

# External object files for target imgui
imgui_EXTERNAL_OBJECTS =

bin/lib/libimgui.a: CMakeFiles/imgui.dir/deps/imgui/imgui.cpp.o
bin/lib/libimgui.a: CMakeFiles/imgui.dir/deps/imgui/imgui_demo.cpp.o
bin/lib/libimgui.a: CMakeFiles/imgui.dir/deps/imgui/imgui_draw.cpp.o
bin/lib/libimgui.a: CMakeFiles/imgui.dir/deps/imgui/imgui_tables.cpp.o
bin/lib/libimgui.a: CMakeFiles/imgui.dir/deps/imgui/imgui_widgets.cpp.o
bin/lib/libimgui.a: CMakeFiles/imgui.dir/build.make
bin/lib/libimgui.a: CMakeFiles/imgui.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nibbyt/Projects/emulators/agbdesk/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX static library bin/lib/libimgui.a"
	$(CMAKE_COMMAND) -P CMakeFiles/imgui.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/imgui.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/imgui.dir/build: bin/lib/libimgui.a

.PHONY : CMakeFiles/imgui.dir/build

CMakeFiles/imgui.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/imgui.dir/cmake_clean.cmake
.PHONY : CMakeFiles/imgui.dir/clean

CMakeFiles/imgui.dir/depend:
	cd /home/nibbyt/Projects/emulators/agbdesk && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nibbyt/Projects/emulators/agbdesk /home/nibbyt/Projects/emulators/agbdesk /home/nibbyt/Projects/emulators/agbdesk /home/nibbyt/Projects/emulators/agbdesk /home/nibbyt/Projects/emulators/agbdesk/CMakeFiles/imgui.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/imgui.dir/depend
