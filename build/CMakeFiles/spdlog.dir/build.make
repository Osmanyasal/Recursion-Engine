# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/rt7/Desktop/Recursion-Engine/lib/spdlog

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rt7/Desktop/Recursion-Engine/build

# Include any dependencies generated for this target.
include CMakeFiles/spdlog.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/spdlog.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/spdlog.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/spdlog.dir/flags.make

CMakeFiles/spdlog.dir/src/spdlog.cpp.o: CMakeFiles/spdlog.dir/flags.make
CMakeFiles/spdlog.dir/src/spdlog.cpp.o: /home/rt7/Desktop/Recursion-Engine/lib/spdlog/src/spdlog.cpp
CMakeFiles/spdlog.dir/src/spdlog.cpp.o: CMakeFiles/spdlog.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rt7/Desktop/Recursion-Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/spdlog.dir/src/spdlog.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/spdlog.dir/src/spdlog.cpp.o -MF CMakeFiles/spdlog.dir/src/spdlog.cpp.o.d -o CMakeFiles/spdlog.dir/src/spdlog.cpp.o -c /home/rt7/Desktop/Recursion-Engine/lib/spdlog/src/spdlog.cpp

CMakeFiles/spdlog.dir/src/spdlog.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/spdlog.dir/src/spdlog.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rt7/Desktop/Recursion-Engine/lib/spdlog/src/spdlog.cpp > CMakeFiles/spdlog.dir/src/spdlog.cpp.i

CMakeFiles/spdlog.dir/src/spdlog.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/spdlog.dir/src/spdlog.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rt7/Desktop/Recursion-Engine/lib/spdlog/src/spdlog.cpp -o CMakeFiles/spdlog.dir/src/spdlog.cpp.s

CMakeFiles/spdlog.dir/src/stdout_sinks.cpp.o: CMakeFiles/spdlog.dir/flags.make
CMakeFiles/spdlog.dir/src/stdout_sinks.cpp.o: /home/rt7/Desktop/Recursion-Engine/lib/spdlog/src/stdout_sinks.cpp
CMakeFiles/spdlog.dir/src/stdout_sinks.cpp.o: CMakeFiles/spdlog.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rt7/Desktop/Recursion-Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/spdlog.dir/src/stdout_sinks.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/spdlog.dir/src/stdout_sinks.cpp.o -MF CMakeFiles/spdlog.dir/src/stdout_sinks.cpp.o.d -o CMakeFiles/spdlog.dir/src/stdout_sinks.cpp.o -c /home/rt7/Desktop/Recursion-Engine/lib/spdlog/src/stdout_sinks.cpp

CMakeFiles/spdlog.dir/src/stdout_sinks.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/spdlog.dir/src/stdout_sinks.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rt7/Desktop/Recursion-Engine/lib/spdlog/src/stdout_sinks.cpp > CMakeFiles/spdlog.dir/src/stdout_sinks.cpp.i

CMakeFiles/spdlog.dir/src/stdout_sinks.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/spdlog.dir/src/stdout_sinks.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rt7/Desktop/Recursion-Engine/lib/spdlog/src/stdout_sinks.cpp -o CMakeFiles/spdlog.dir/src/stdout_sinks.cpp.s

CMakeFiles/spdlog.dir/src/color_sinks.cpp.o: CMakeFiles/spdlog.dir/flags.make
CMakeFiles/spdlog.dir/src/color_sinks.cpp.o: /home/rt7/Desktop/Recursion-Engine/lib/spdlog/src/color_sinks.cpp
CMakeFiles/spdlog.dir/src/color_sinks.cpp.o: CMakeFiles/spdlog.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rt7/Desktop/Recursion-Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/spdlog.dir/src/color_sinks.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/spdlog.dir/src/color_sinks.cpp.o -MF CMakeFiles/spdlog.dir/src/color_sinks.cpp.o.d -o CMakeFiles/spdlog.dir/src/color_sinks.cpp.o -c /home/rt7/Desktop/Recursion-Engine/lib/spdlog/src/color_sinks.cpp

CMakeFiles/spdlog.dir/src/color_sinks.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/spdlog.dir/src/color_sinks.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rt7/Desktop/Recursion-Engine/lib/spdlog/src/color_sinks.cpp > CMakeFiles/spdlog.dir/src/color_sinks.cpp.i

CMakeFiles/spdlog.dir/src/color_sinks.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/spdlog.dir/src/color_sinks.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rt7/Desktop/Recursion-Engine/lib/spdlog/src/color_sinks.cpp -o CMakeFiles/spdlog.dir/src/color_sinks.cpp.s

CMakeFiles/spdlog.dir/src/file_sinks.cpp.o: CMakeFiles/spdlog.dir/flags.make
CMakeFiles/spdlog.dir/src/file_sinks.cpp.o: /home/rt7/Desktop/Recursion-Engine/lib/spdlog/src/file_sinks.cpp
CMakeFiles/spdlog.dir/src/file_sinks.cpp.o: CMakeFiles/spdlog.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rt7/Desktop/Recursion-Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/spdlog.dir/src/file_sinks.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/spdlog.dir/src/file_sinks.cpp.o -MF CMakeFiles/spdlog.dir/src/file_sinks.cpp.o.d -o CMakeFiles/spdlog.dir/src/file_sinks.cpp.o -c /home/rt7/Desktop/Recursion-Engine/lib/spdlog/src/file_sinks.cpp

CMakeFiles/spdlog.dir/src/file_sinks.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/spdlog.dir/src/file_sinks.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rt7/Desktop/Recursion-Engine/lib/spdlog/src/file_sinks.cpp > CMakeFiles/spdlog.dir/src/file_sinks.cpp.i

CMakeFiles/spdlog.dir/src/file_sinks.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/spdlog.dir/src/file_sinks.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rt7/Desktop/Recursion-Engine/lib/spdlog/src/file_sinks.cpp -o CMakeFiles/spdlog.dir/src/file_sinks.cpp.s

CMakeFiles/spdlog.dir/src/async.cpp.o: CMakeFiles/spdlog.dir/flags.make
CMakeFiles/spdlog.dir/src/async.cpp.o: /home/rt7/Desktop/Recursion-Engine/lib/spdlog/src/async.cpp
CMakeFiles/spdlog.dir/src/async.cpp.o: CMakeFiles/spdlog.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rt7/Desktop/Recursion-Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/spdlog.dir/src/async.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/spdlog.dir/src/async.cpp.o -MF CMakeFiles/spdlog.dir/src/async.cpp.o.d -o CMakeFiles/spdlog.dir/src/async.cpp.o -c /home/rt7/Desktop/Recursion-Engine/lib/spdlog/src/async.cpp

CMakeFiles/spdlog.dir/src/async.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/spdlog.dir/src/async.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rt7/Desktop/Recursion-Engine/lib/spdlog/src/async.cpp > CMakeFiles/spdlog.dir/src/async.cpp.i

CMakeFiles/spdlog.dir/src/async.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/spdlog.dir/src/async.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rt7/Desktop/Recursion-Engine/lib/spdlog/src/async.cpp -o CMakeFiles/spdlog.dir/src/async.cpp.s

CMakeFiles/spdlog.dir/src/cfg.cpp.o: CMakeFiles/spdlog.dir/flags.make
CMakeFiles/spdlog.dir/src/cfg.cpp.o: /home/rt7/Desktop/Recursion-Engine/lib/spdlog/src/cfg.cpp
CMakeFiles/spdlog.dir/src/cfg.cpp.o: CMakeFiles/spdlog.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rt7/Desktop/Recursion-Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/spdlog.dir/src/cfg.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/spdlog.dir/src/cfg.cpp.o -MF CMakeFiles/spdlog.dir/src/cfg.cpp.o.d -o CMakeFiles/spdlog.dir/src/cfg.cpp.o -c /home/rt7/Desktop/Recursion-Engine/lib/spdlog/src/cfg.cpp

CMakeFiles/spdlog.dir/src/cfg.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/spdlog.dir/src/cfg.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rt7/Desktop/Recursion-Engine/lib/spdlog/src/cfg.cpp > CMakeFiles/spdlog.dir/src/cfg.cpp.i

CMakeFiles/spdlog.dir/src/cfg.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/spdlog.dir/src/cfg.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rt7/Desktop/Recursion-Engine/lib/spdlog/src/cfg.cpp -o CMakeFiles/spdlog.dir/src/cfg.cpp.s

CMakeFiles/spdlog.dir/src/bundled_fmtlib_format.cpp.o: CMakeFiles/spdlog.dir/flags.make
CMakeFiles/spdlog.dir/src/bundled_fmtlib_format.cpp.o: /home/rt7/Desktop/Recursion-Engine/lib/spdlog/src/bundled_fmtlib_format.cpp
CMakeFiles/spdlog.dir/src/bundled_fmtlib_format.cpp.o: CMakeFiles/spdlog.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rt7/Desktop/Recursion-Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/spdlog.dir/src/bundled_fmtlib_format.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/spdlog.dir/src/bundled_fmtlib_format.cpp.o -MF CMakeFiles/spdlog.dir/src/bundled_fmtlib_format.cpp.o.d -o CMakeFiles/spdlog.dir/src/bundled_fmtlib_format.cpp.o -c /home/rt7/Desktop/Recursion-Engine/lib/spdlog/src/bundled_fmtlib_format.cpp

CMakeFiles/spdlog.dir/src/bundled_fmtlib_format.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/spdlog.dir/src/bundled_fmtlib_format.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rt7/Desktop/Recursion-Engine/lib/spdlog/src/bundled_fmtlib_format.cpp > CMakeFiles/spdlog.dir/src/bundled_fmtlib_format.cpp.i

CMakeFiles/spdlog.dir/src/bundled_fmtlib_format.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/spdlog.dir/src/bundled_fmtlib_format.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rt7/Desktop/Recursion-Engine/lib/spdlog/src/bundled_fmtlib_format.cpp -o CMakeFiles/spdlog.dir/src/bundled_fmtlib_format.cpp.s

# Object files for target spdlog
spdlog_OBJECTS = \
"CMakeFiles/spdlog.dir/src/spdlog.cpp.o" \
"CMakeFiles/spdlog.dir/src/stdout_sinks.cpp.o" \
"CMakeFiles/spdlog.dir/src/color_sinks.cpp.o" \
"CMakeFiles/spdlog.dir/src/file_sinks.cpp.o" \
"CMakeFiles/spdlog.dir/src/async.cpp.o" \
"CMakeFiles/spdlog.dir/src/cfg.cpp.o" \
"CMakeFiles/spdlog.dir/src/bundled_fmtlib_format.cpp.o"

# External object files for target spdlog
spdlog_EXTERNAL_OBJECTS =

libspdlogd.a: CMakeFiles/spdlog.dir/src/spdlog.cpp.o
libspdlogd.a: CMakeFiles/spdlog.dir/src/stdout_sinks.cpp.o
libspdlogd.a: CMakeFiles/spdlog.dir/src/color_sinks.cpp.o
libspdlogd.a: CMakeFiles/spdlog.dir/src/file_sinks.cpp.o
libspdlogd.a: CMakeFiles/spdlog.dir/src/async.cpp.o
libspdlogd.a: CMakeFiles/spdlog.dir/src/cfg.cpp.o
libspdlogd.a: CMakeFiles/spdlog.dir/src/bundled_fmtlib_format.cpp.o
libspdlogd.a: CMakeFiles/spdlog.dir/build.make
libspdlogd.a: CMakeFiles/spdlog.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/rt7/Desktop/Recursion-Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX static library libspdlogd.a"
	$(CMAKE_COMMAND) -P CMakeFiles/spdlog.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/spdlog.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/spdlog.dir/build: libspdlogd.a
.PHONY : CMakeFiles/spdlog.dir/build

CMakeFiles/spdlog.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/spdlog.dir/cmake_clean.cmake
.PHONY : CMakeFiles/spdlog.dir/clean

CMakeFiles/spdlog.dir/depend:
	cd /home/rt7/Desktop/Recursion-Engine/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rt7/Desktop/Recursion-Engine/lib/spdlog /home/rt7/Desktop/Recursion-Engine/lib/spdlog /home/rt7/Desktop/Recursion-Engine/build /home/rt7/Desktop/Recursion-Engine/build /home/rt7/Desktop/Recursion-Engine/build/CMakeFiles/spdlog.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/spdlog.dir/depend

