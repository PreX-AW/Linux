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
CMAKE_SOURCE_DIR = /home/ros1/Documents/Cpp/Linux/Myshell/myShell_simple/testcmake

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ros1/Documents/Cpp/Linux/Myshell/myShell_simple/testcmake/build

# Include any dependencies generated for this target.
include CMakeFiles/my_Shell_lib.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/my_Shell_lib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/my_Shell_lib.dir/flags.make

CMakeFiles/my_Shell_lib.dir/src/myShell_simple.c.o: CMakeFiles/my_Shell_lib.dir/flags.make
CMakeFiles/my_Shell_lib.dir/src/myShell_simple.c.o: ../src/myShell_simple.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ros1/Documents/Cpp/Linux/Myshell/myShell_simple/testcmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/my_Shell_lib.dir/src/myShell_simple.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/my_Shell_lib.dir/src/myShell_simple.c.o   -c /home/ros1/Documents/Cpp/Linux/Myshell/myShell_simple/testcmake/src/myShell_simple.c

CMakeFiles/my_Shell_lib.dir/src/myShell_simple.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/my_Shell_lib.dir/src/myShell_simple.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ros1/Documents/Cpp/Linux/Myshell/myShell_simple/testcmake/src/myShell_simple.c > CMakeFiles/my_Shell_lib.dir/src/myShell_simple.c.i

CMakeFiles/my_Shell_lib.dir/src/myShell_simple.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/my_Shell_lib.dir/src/myShell_simple.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ros1/Documents/Cpp/Linux/Myshell/myShell_simple/testcmake/src/myShell_simple.c -o CMakeFiles/my_Shell_lib.dir/src/myShell_simple.c.s

CMakeFiles/my_Shell_lib.dir/src/print_Sub_command.c.o: CMakeFiles/my_Shell_lib.dir/flags.make
CMakeFiles/my_Shell_lib.dir/src/print_Sub_command.c.o: ../src/print_Sub_command.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ros1/Documents/Cpp/Linux/Myshell/myShell_simple/testcmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/my_Shell_lib.dir/src/print_Sub_command.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/my_Shell_lib.dir/src/print_Sub_command.c.o   -c /home/ros1/Documents/Cpp/Linux/Myshell/myShell_simple/testcmake/src/print_Sub_command.c

CMakeFiles/my_Shell_lib.dir/src/print_Sub_command.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/my_Shell_lib.dir/src/print_Sub_command.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ros1/Documents/Cpp/Linux/Myshell/myShell_simple/testcmake/src/print_Sub_command.c > CMakeFiles/my_Shell_lib.dir/src/print_Sub_command.c.i

CMakeFiles/my_Shell_lib.dir/src/print_Sub_command.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/my_Shell_lib.dir/src/print_Sub_command.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ros1/Documents/Cpp/Linux/Myshell/myShell_simple/testcmake/src/print_Sub_command.c -o CMakeFiles/my_Shell_lib.dir/src/print_Sub_command.c.s

CMakeFiles/my_Shell_lib.dir/src/saparate_Command.c.o: CMakeFiles/my_Shell_lib.dir/flags.make
CMakeFiles/my_Shell_lib.dir/src/saparate_Command.c.o: ../src/saparate_Command.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ros1/Documents/Cpp/Linux/Myshell/myShell_simple/testcmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/my_Shell_lib.dir/src/saparate_Command.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/my_Shell_lib.dir/src/saparate_Command.c.o   -c /home/ros1/Documents/Cpp/Linux/Myshell/myShell_simple/testcmake/src/saparate_Command.c

CMakeFiles/my_Shell_lib.dir/src/saparate_Command.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/my_Shell_lib.dir/src/saparate_Command.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ros1/Documents/Cpp/Linux/Myshell/myShell_simple/testcmake/src/saparate_Command.c > CMakeFiles/my_Shell_lib.dir/src/saparate_Command.c.i

CMakeFiles/my_Shell_lib.dir/src/saparate_Command.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/my_Shell_lib.dir/src/saparate_Command.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ros1/Documents/Cpp/Linux/Myshell/myShell_simple/testcmake/src/saparate_Command.c -o CMakeFiles/my_Shell_lib.dir/src/saparate_Command.c.s

# Object files for target my_Shell_lib
my_Shell_lib_OBJECTS = \
"CMakeFiles/my_Shell_lib.dir/src/myShell_simple.c.o" \
"CMakeFiles/my_Shell_lib.dir/src/print_Sub_command.c.o" \
"CMakeFiles/my_Shell_lib.dir/src/saparate_Command.c.o"

# External object files for target my_Shell_lib
my_Shell_lib_EXTERNAL_OBJECTS =

../lib/libmy_Shell_lib.so: CMakeFiles/my_Shell_lib.dir/src/myShell_simple.c.o
../lib/libmy_Shell_lib.so: CMakeFiles/my_Shell_lib.dir/src/print_Sub_command.c.o
../lib/libmy_Shell_lib.so: CMakeFiles/my_Shell_lib.dir/src/saparate_Command.c.o
../lib/libmy_Shell_lib.so: CMakeFiles/my_Shell_lib.dir/build.make
../lib/libmy_Shell_lib.so: CMakeFiles/my_Shell_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ros1/Documents/Cpp/Linux/Myshell/myShell_simple/testcmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C shared library ../lib/libmy_Shell_lib.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/my_Shell_lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/my_Shell_lib.dir/build: ../lib/libmy_Shell_lib.so

.PHONY : CMakeFiles/my_Shell_lib.dir/build

CMakeFiles/my_Shell_lib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/my_Shell_lib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/my_Shell_lib.dir/clean

CMakeFiles/my_Shell_lib.dir/depend:
	cd /home/ros1/Documents/Cpp/Linux/Myshell/myShell_simple/testcmake/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ros1/Documents/Cpp/Linux/Myshell/myShell_simple/testcmake /home/ros1/Documents/Cpp/Linux/Myshell/myShell_simple/testcmake /home/ros1/Documents/Cpp/Linux/Myshell/myShell_simple/testcmake/build /home/ros1/Documents/Cpp/Linux/Myshell/myShell_simple/testcmake/build /home/ros1/Documents/Cpp/Linux/Myshell/myShell_simple/testcmake/build/CMakeFiles/my_Shell_lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/my_Shell_lib.dir/depend

