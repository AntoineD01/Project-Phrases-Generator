# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.3.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Antoine Dupont\CLionProjects\!L2\Project-Phrases-Generator"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Antoine Dupont\CLionProjects\!L2\Project-Phrases-Generator\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/TD1.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/TD1.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/TD1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TD1.dir/flags.make

CMakeFiles/TD1.dir/main.c.obj: CMakeFiles/TD1.dir/flags.make
CMakeFiles/TD1.dir/main.c.obj: ../main.c
CMakeFiles/TD1.dir/main.c.obj: CMakeFiles/TD1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Antoine Dupont\CLionProjects\!L2\Project-Phrases-Generator\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/TD1.dir/main.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/TD1.dir/main.c.obj -MF CMakeFiles\TD1.dir\main.c.obj.d -o CMakeFiles\TD1.dir\main.c.obj -c "C:\Users\Antoine Dupont\CLionProjects\!L2\Project-Phrases-Generator\main.c"

CMakeFiles/TD1.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TD1.dir/main.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Antoine Dupont\CLionProjects\!L2\Project-Phrases-Generator\main.c" > CMakeFiles\TD1.dir\main.c.i

CMakeFiles/TD1.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TD1.dir/main.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Antoine Dupont\CLionProjects\!L2\Project-Phrases-Generator\main.c" -o CMakeFiles\TD1.dir\main.c.s

CMakeFiles/TD1.dir/product.c.obj: CMakeFiles/TD1.dir/flags.make
CMakeFiles/TD1.dir/product.c.obj: ../product.c
CMakeFiles/TD1.dir/product.c.obj: CMakeFiles/TD1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Antoine Dupont\CLionProjects\!L2\Project-Phrases-Generator\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/TD1.dir/product.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/TD1.dir/product.c.obj -MF CMakeFiles\TD1.dir\product.c.obj.d -o CMakeFiles\TD1.dir\product.c.obj -c "C:\Users\Antoine Dupont\CLionProjects\!L2\Project-Phrases-Generator\product.c"

CMakeFiles/TD1.dir/product.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TD1.dir/product.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Antoine Dupont\CLionProjects\!L2\Project-Phrases-Generator\product.c" > CMakeFiles\TD1.dir\product.c.i

CMakeFiles/TD1.dir/product.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TD1.dir/product.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Antoine Dupont\CLionProjects\!L2\Project-Phrases-Generator\product.c" -o CMakeFiles\TD1.dir\product.c.s

# Object files for target TD1
TD1_OBJECTS = \
"CMakeFiles/TD1.dir/main.c.obj" \
"CMakeFiles/TD1.dir/product.c.obj"

# External object files for target TD1
TD1_EXTERNAL_OBJECTS =

TD1.exe: CMakeFiles/TD1.dir/main.c.obj
TD1.exe: CMakeFiles/TD1.dir/product.c.obj
TD1.exe: CMakeFiles/TD1.dir/build.make
TD1.exe: CMakeFiles/TD1.dir/linklibs.rsp
TD1.exe: CMakeFiles/TD1.dir/objects1.rsp
TD1.exe: CMakeFiles/TD1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Antoine Dupont\CLionProjects\!L2\Project-Phrases-Generator\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable TD1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\TD1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TD1.dir/build: TD1.exe
.PHONY : CMakeFiles/TD1.dir/build

CMakeFiles/TD1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\TD1.dir\cmake_clean.cmake
.PHONY : CMakeFiles/TD1.dir/clean

CMakeFiles/TD1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Antoine Dupont\CLionProjects\!L2\Project-Phrases-Generator" "C:\Users\Antoine Dupont\CLionProjects\!L2\Project-Phrases-Generator" "C:\Users\Antoine Dupont\CLionProjects\!L2\Project-Phrases-Generator\cmake-build-debug" "C:\Users\Antoine Dupont\CLionProjects\!L2\Project-Phrases-Generator\cmake-build-debug" "C:\Users\Antoine Dupont\CLionProjects\!L2\Project-Phrases-Generator\cmake-build-debug\CMakeFiles\TD1.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/TD1.dir/depend

