# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /home/huvalk/Загрузки/cmake-3.15.5/bin/cmake

# The command to remove a file.
RM = /home/huvalk/Загрузки/cmake-3.15.5/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/huvalk/Polaris/Main

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/huvalk/Polaris/Main/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Main.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Main.dir/flags.make

CMakeFiles/Main.dir/Main_autogen/mocs_compilation.cpp.o: CMakeFiles/Main.dir/flags.make
CMakeFiles/Main.dir/Main_autogen/mocs_compilation.cpp.o: Main_autogen/mocs_compilation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/huvalk/Polaris/Main/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Main.dir/Main_autogen/mocs_compilation.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Main.dir/Main_autogen/mocs_compilation.cpp.o -c /home/huvalk/Polaris/Main/cmake-build-debug/Main_autogen/mocs_compilation.cpp

CMakeFiles/Main.dir/Main_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Main.dir/Main_autogen/mocs_compilation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/huvalk/Polaris/Main/cmake-build-debug/Main_autogen/mocs_compilation.cpp > CMakeFiles/Main.dir/Main_autogen/mocs_compilation.cpp.i

CMakeFiles/Main.dir/Main_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Main.dir/Main_autogen/mocs_compilation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/huvalk/Polaris/Main/cmake-build-debug/Main_autogen/mocs_compilation.cpp -o CMakeFiles/Main.dir/Main_autogen/mocs_compilation.cpp.s

CMakeFiles/Main.dir/lib/button_click_handler.cpp.o: CMakeFiles/Main.dir/flags.make
CMakeFiles/Main.dir/lib/button_click_handler.cpp.o: ../lib/button_click_handler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/huvalk/Polaris/Main/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Main.dir/lib/button_click_handler.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Main.dir/lib/button_click_handler.cpp.o -c /home/huvalk/Polaris/Main/lib/button_click_handler.cpp

CMakeFiles/Main.dir/lib/button_click_handler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Main.dir/lib/button_click_handler.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/huvalk/Polaris/Main/lib/button_click_handler.cpp > CMakeFiles/Main.dir/lib/button_click_handler.cpp.i

CMakeFiles/Main.dir/lib/button_click_handler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Main.dir/lib/button_click_handler.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/huvalk/Polaris/Main/lib/button_click_handler.cpp -o CMakeFiles/Main.dir/lib/button_click_handler.cpp.s

CMakeFiles/Main.dir/lib/node_form.cpp.o: CMakeFiles/Main.dir/flags.make
CMakeFiles/Main.dir/lib/node_form.cpp.o: ../lib/node_form.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/huvalk/Polaris/Main/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Main.dir/lib/node_form.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Main.dir/lib/node_form.cpp.o -c /home/huvalk/Polaris/Main/lib/node_form.cpp

CMakeFiles/Main.dir/lib/node_form.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Main.dir/lib/node_form.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/huvalk/Polaris/Main/lib/node_form.cpp > CMakeFiles/Main.dir/lib/node_form.cpp.i

CMakeFiles/Main.dir/lib/node_form.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Main.dir/lib/node_form.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/huvalk/Polaris/Main/lib/node_form.cpp -o CMakeFiles/Main.dir/lib/node_form.cpp.s

CMakeFiles/Main.dir/lib/connection_form.cpp.o: CMakeFiles/Main.dir/flags.make
CMakeFiles/Main.dir/lib/connection_form.cpp.o: ../lib/connection_form.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/huvalk/Polaris/Main/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Main.dir/lib/connection_form.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Main.dir/lib/connection_form.cpp.o -c /home/huvalk/Polaris/Main/lib/connection_form.cpp

CMakeFiles/Main.dir/lib/connection_form.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Main.dir/lib/connection_form.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/huvalk/Polaris/Main/lib/connection_form.cpp > CMakeFiles/Main.dir/lib/connection_form.cpp.i

CMakeFiles/Main.dir/lib/connection_form.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Main.dir/lib/connection_form.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/huvalk/Polaris/Main/lib/connection_form.cpp -o CMakeFiles/Main.dir/lib/connection_form.cpp.s

CMakeFiles/Main.dir/lib/mainwindow.cpp.o: CMakeFiles/Main.dir/flags.make
CMakeFiles/Main.dir/lib/mainwindow.cpp.o: ../lib/mainwindow.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/huvalk/Polaris/Main/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Main.dir/lib/mainwindow.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Main.dir/lib/mainwindow.cpp.o -c /home/huvalk/Polaris/Main/lib/mainwindow.cpp

CMakeFiles/Main.dir/lib/mainwindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Main.dir/lib/mainwindow.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/huvalk/Polaris/Main/lib/mainwindow.cpp > CMakeFiles/Main.dir/lib/mainwindow.cpp.i

CMakeFiles/Main.dir/lib/mainwindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Main.dir/lib/mainwindow.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/huvalk/Polaris/Main/lib/mainwindow.cpp -o CMakeFiles/Main.dir/lib/mainwindow.cpp.s

CMakeFiles/Main.dir/lib/view_sub.cpp.o: CMakeFiles/Main.dir/flags.make
CMakeFiles/Main.dir/lib/view_sub.cpp.o: ../lib/view_sub.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/huvalk/Polaris/Main/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Main.dir/lib/view_sub.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Main.dir/lib/view_sub.cpp.o -c /home/huvalk/Polaris/Main/lib/view_sub.cpp

CMakeFiles/Main.dir/lib/view_sub.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Main.dir/lib/view_sub.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/huvalk/Polaris/Main/lib/view_sub.cpp > CMakeFiles/Main.dir/lib/view_sub.cpp.i

CMakeFiles/Main.dir/lib/view_sub.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Main.dir/lib/view_sub.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/huvalk/Polaris/Main/lib/view_sub.cpp -o CMakeFiles/Main.dir/lib/view_sub.cpp.s

# Object files for target Main
Main_OBJECTS = \
"CMakeFiles/Main.dir/Main_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/Main.dir/lib/button_click_handler.cpp.o" \
"CMakeFiles/Main.dir/lib/node_form.cpp.o" \
"CMakeFiles/Main.dir/lib/connection_form.cpp.o" \
"CMakeFiles/Main.dir/lib/mainwindow.cpp.o" \
"CMakeFiles/Main.dir/lib/view_sub.cpp.o"

# External object files for target Main
Main_EXTERNAL_OBJECTS =

libMain.a: CMakeFiles/Main.dir/Main_autogen/mocs_compilation.cpp.o
libMain.a: CMakeFiles/Main.dir/lib/button_click_handler.cpp.o
libMain.a: CMakeFiles/Main.dir/lib/node_form.cpp.o
libMain.a: CMakeFiles/Main.dir/lib/connection_form.cpp.o
libMain.a: CMakeFiles/Main.dir/lib/mainwindow.cpp.o
libMain.a: CMakeFiles/Main.dir/lib/view_sub.cpp.o
libMain.a: CMakeFiles/Main.dir/build.make
libMain.a: CMakeFiles/Main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/huvalk/Polaris/Main/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX static library libMain.a"
	$(CMAKE_COMMAND) -P CMakeFiles/Main.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Main.dir/build: libMain.a

.PHONY : CMakeFiles/Main.dir/build

CMakeFiles/Main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Main.dir/clean

CMakeFiles/Main.dir/depend:
	cd /home/huvalk/Polaris/Main/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/huvalk/Polaris/Main /home/huvalk/Polaris/Main /home/huvalk/Polaris/Main/cmake-build-debug /home/huvalk/Polaris/Main/cmake-build-debug /home/huvalk/Polaris/Main/cmake-build-debug/CMakeFiles/Main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Main.dir/depend

