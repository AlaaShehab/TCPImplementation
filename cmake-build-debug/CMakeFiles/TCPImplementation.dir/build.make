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
CMAKE_COMMAND = /opt/clion-2019.2.5/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2019.2.5/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/alaa/Desktop/TCPImplementation

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alaa/Desktop/TCPImplementation/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/TCPImplementation.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TCPImplementation.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TCPImplementation.dir/flags.make

CMakeFiles/TCPImplementation.dir/main.cpp.o: CMakeFiles/TCPImplementation.dir/flags.make
CMakeFiles/TCPImplementation.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alaa/Desktop/TCPImplementation/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TCPImplementation.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TCPImplementation.dir/main.cpp.o -c /home/alaa/Desktop/TCPImplementation/main.cpp

CMakeFiles/TCPImplementation.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TCPImplementation.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alaa/Desktop/TCPImplementation/main.cpp > CMakeFiles/TCPImplementation.dir/main.cpp.i

CMakeFiles/TCPImplementation.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TCPImplementation.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alaa/Desktop/TCPImplementation/main.cpp -o CMakeFiles/TCPImplementation.dir/main.cpp.s

CMakeFiles/TCPImplementation.dir/Server/Server.cpp.o: CMakeFiles/TCPImplementation.dir/flags.make
CMakeFiles/TCPImplementation.dir/Server/Server.cpp.o: ../Server/Server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alaa/Desktop/TCPImplementation/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/TCPImplementation.dir/Server/Server.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TCPImplementation.dir/Server/Server.cpp.o -c /home/alaa/Desktop/TCPImplementation/Server/Server.cpp

CMakeFiles/TCPImplementation.dir/Server/Server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TCPImplementation.dir/Server/Server.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alaa/Desktop/TCPImplementation/Server/Server.cpp > CMakeFiles/TCPImplementation.dir/Server/Server.cpp.i

CMakeFiles/TCPImplementation.dir/Server/Server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TCPImplementation.dir/Server/Server.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alaa/Desktop/TCPImplementation/Server/Server.cpp -o CMakeFiles/TCPImplementation.dir/Server/Server.cpp.s

CMakeFiles/TCPImplementation.dir/Server/SelectiveRepeat.cpp.o: CMakeFiles/TCPImplementation.dir/flags.make
CMakeFiles/TCPImplementation.dir/Server/SelectiveRepeat.cpp.o: ../Server/SelectiveRepeat.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alaa/Desktop/TCPImplementation/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/TCPImplementation.dir/Server/SelectiveRepeat.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TCPImplementation.dir/Server/SelectiveRepeat.cpp.o -c /home/alaa/Desktop/TCPImplementation/Server/SelectiveRepeat.cpp

CMakeFiles/TCPImplementation.dir/Server/SelectiveRepeat.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TCPImplementation.dir/Server/SelectiveRepeat.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alaa/Desktop/TCPImplementation/Server/SelectiveRepeat.cpp > CMakeFiles/TCPImplementation.dir/Server/SelectiveRepeat.cpp.i

CMakeFiles/TCPImplementation.dir/Server/SelectiveRepeat.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TCPImplementation.dir/Server/SelectiveRepeat.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alaa/Desktop/TCPImplementation/Server/SelectiveRepeat.cpp -o CMakeFiles/TCPImplementation.dir/Server/SelectiveRepeat.cpp.s

CMakeFiles/TCPImplementation.dir/Client/Client.cpp.o: CMakeFiles/TCPImplementation.dir/flags.make
CMakeFiles/TCPImplementation.dir/Client/Client.cpp.o: ../Client/Client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alaa/Desktop/TCPImplementation/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/TCPImplementation.dir/Client/Client.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TCPImplementation.dir/Client/Client.cpp.o -c /home/alaa/Desktop/TCPImplementation/Client/Client.cpp

CMakeFiles/TCPImplementation.dir/Client/Client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TCPImplementation.dir/Client/Client.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alaa/Desktop/TCPImplementation/Client/Client.cpp > CMakeFiles/TCPImplementation.dir/Client/Client.cpp.i

CMakeFiles/TCPImplementation.dir/Client/Client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TCPImplementation.dir/Client/Client.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alaa/Desktop/TCPImplementation/Client/Client.cpp -o CMakeFiles/TCPImplementation.dir/Client/Client.cpp.s

CMakeFiles/TCPImplementation.dir/Client/SelectiveRepeat.cpp.o: CMakeFiles/TCPImplementation.dir/flags.make
CMakeFiles/TCPImplementation.dir/Client/SelectiveRepeat.cpp.o: ../Client/SelectiveRepeat.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alaa/Desktop/TCPImplementation/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/TCPImplementation.dir/Client/SelectiveRepeat.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TCPImplementation.dir/Client/SelectiveRepeat.cpp.o -c /home/alaa/Desktop/TCPImplementation/Client/SelectiveRepeat.cpp

CMakeFiles/TCPImplementation.dir/Client/SelectiveRepeat.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TCPImplementation.dir/Client/SelectiveRepeat.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alaa/Desktop/TCPImplementation/Client/SelectiveRepeat.cpp > CMakeFiles/TCPImplementation.dir/Client/SelectiveRepeat.cpp.i

CMakeFiles/TCPImplementation.dir/Client/SelectiveRepeat.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TCPImplementation.dir/Client/SelectiveRepeat.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alaa/Desktop/TCPImplementation/Client/SelectiveRepeat.cpp -o CMakeFiles/TCPImplementation.dir/Client/SelectiveRepeat.cpp.s

CMakeFiles/TCPImplementation.dir/Client/main.cpp.o: CMakeFiles/TCPImplementation.dir/flags.make
CMakeFiles/TCPImplementation.dir/Client/main.cpp.o: ../Client/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alaa/Desktop/TCPImplementation/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/TCPImplementation.dir/Client/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TCPImplementation.dir/Client/main.cpp.o -c /home/alaa/Desktop/TCPImplementation/Client/main.cpp

CMakeFiles/TCPImplementation.dir/Client/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TCPImplementation.dir/Client/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alaa/Desktop/TCPImplementation/Client/main.cpp > CMakeFiles/TCPImplementation.dir/Client/main.cpp.i

CMakeFiles/TCPImplementation.dir/Client/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TCPImplementation.dir/Client/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alaa/Desktop/TCPImplementation/Client/main.cpp -o CMakeFiles/TCPImplementation.dir/Client/main.cpp.s

CMakeFiles/TCPImplementation.dir/Server/main.cpp.o: CMakeFiles/TCPImplementation.dir/flags.make
CMakeFiles/TCPImplementation.dir/Server/main.cpp.o: ../Server/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alaa/Desktop/TCPImplementation/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/TCPImplementation.dir/Server/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TCPImplementation.dir/Server/main.cpp.o -c /home/alaa/Desktop/TCPImplementation/Server/main.cpp

CMakeFiles/TCPImplementation.dir/Server/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TCPImplementation.dir/Server/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alaa/Desktop/TCPImplementation/Server/main.cpp > CMakeFiles/TCPImplementation.dir/Server/main.cpp.i

CMakeFiles/TCPImplementation.dir/Server/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TCPImplementation.dir/Server/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alaa/Desktop/TCPImplementation/Server/main.cpp -o CMakeFiles/TCPImplementation.dir/Server/main.cpp.s

# Object files for target TCPImplementation
TCPImplementation_OBJECTS = \
"CMakeFiles/TCPImplementation.dir/main.cpp.o" \
"CMakeFiles/TCPImplementation.dir/Server/Server.cpp.o" \
"CMakeFiles/TCPImplementation.dir/Server/SelectiveRepeat.cpp.o" \
"CMakeFiles/TCPImplementation.dir/Client/Client.cpp.o" \
"CMakeFiles/TCPImplementation.dir/Client/SelectiveRepeat.cpp.o" \
"CMakeFiles/TCPImplementation.dir/Client/main.cpp.o" \
"CMakeFiles/TCPImplementation.dir/Server/main.cpp.o"

# External object files for target TCPImplementation
TCPImplementation_EXTERNAL_OBJECTS =

TCPImplementation: CMakeFiles/TCPImplementation.dir/main.cpp.o
TCPImplementation: CMakeFiles/TCPImplementation.dir/Server/Server.cpp.o
TCPImplementation: CMakeFiles/TCPImplementation.dir/Server/SelectiveRepeat.cpp.o
TCPImplementation: CMakeFiles/TCPImplementation.dir/Client/Client.cpp.o
TCPImplementation: CMakeFiles/TCPImplementation.dir/Client/SelectiveRepeat.cpp.o
TCPImplementation: CMakeFiles/TCPImplementation.dir/Client/main.cpp.o
TCPImplementation: CMakeFiles/TCPImplementation.dir/Server/main.cpp.o
TCPImplementation: CMakeFiles/TCPImplementation.dir/build.make
TCPImplementation: CMakeFiles/TCPImplementation.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alaa/Desktop/TCPImplementation/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable TCPImplementation"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TCPImplementation.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TCPImplementation.dir/build: TCPImplementation

.PHONY : CMakeFiles/TCPImplementation.dir/build

CMakeFiles/TCPImplementation.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TCPImplementation.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TCPImplementation.dir/clean

CMakeFiles/TCPImplementation.dir/depend:
	cd /home/alaa/Desktop/TCPImplementation/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alaa/Desktop/TCPImplementation /home/alaa/Desktop/TCPImplementation /home/alaa/Desktop/TCPImplementation/cmake-build-debug /home/alaa/Desktop/TCPImplementation/cmake-build-debug /home/alaa/Desktop/TCPImplementation/cmake-build-debug/CMakeFiles/TCPImplementation.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TCPImplementation.dir/depend

