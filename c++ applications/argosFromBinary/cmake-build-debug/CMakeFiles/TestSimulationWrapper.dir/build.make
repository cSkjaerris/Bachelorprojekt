# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/casperskjaerris/Documents/DTU/6. Semester/Bachelorprojekt/c++ applications/argosFromBinary"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/casperskjaerris/Documents/DTU/6. Semester/Bachelorprojekt/c++ applications/argosFromBinary/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/TestSimulationWrapper.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TestSimulationWrapper.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TestSimulationWrapper.dir/flags.make

CMakeFiles/TestSimulationWrapper.dir/TestWrapper.cpp.o: CMakeFiles/TestSimulationWrapper.dir/flags.make
CMakeFiles/TestSimulationWrapper.dir/TestWrapper.cpp.o: ../TestWrapper.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/casperskjaerris/Documents/DTU/6. Semester/Bachelorprojekt/c++ applications/argosFromBinary/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TestSimulationWrapper.dir/TestWrapper.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TestSimulationWrapper.dir/TestWrapper.cpp.o -c "/Users/casperskjaerris/Documents/DTU/6. Semester/Bachelorprojekt/c++ applications/argosFromBinary/TestWrapper.cpp"

CMakeFiles/TestSimulationWrapper.dir/TestWrapper.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestSimulationWrapper.dir/TestWrapper.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/casperskjaerris/Documents/DTU/6. Semester/Bachelorprojekt/c++ applications/argosFromBinary/TestWrapper.cpp" > CMakeFiles/TestSimulationWrapper.dir/TestWrapper.cpp.i

CMakeFiles/TestSimulationWrapper.dir/TestWrapper.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestSimulationWrapper.dir/TestWrapper.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/casperskjaerris/Documents/DTU/6. Semester/Bachelorprojekt/c++ applications/argosFromBinary/TestWrapper.cpp" -o CMakeFiles/TestSimulationWrapper.dir/TestWrapper.cpp.s

# Object files for target TestSimulationWrapper
TestSimulationWrapper_OBJECTS = \
"CMakeFiles/TestSimulationWrapper.dir/TestWrapper.cpp.o"

# External object files for target TestSimulationWrapper
TestSimulationWrapper_EXTERNAL_OBJECTS =

TestSimulationWrapper: CMakeFiles/TestSimulationWrapper.dir/TestWrapper.cpp.o
TestSimulationWrapper: CMakeFiles/TestSimulationWrapper.dir/build.make
TestSimulationWrapper: libargosFromBinary.dylib
TestSimulationWrapper: /Users/casperskjaerris/Documents/cApp/Argos/lib/libargos3core_simulator.dylib
TestSimulationWrapper: /Users/casperskjaerris/Documents/cApp/Argos/lib/libargos3plugin_simulator_footbot.dylib
TestSimulationWrapper: /Users/casperskjaerris/Documents/cApp/Argos/lib/libargos3plugin_simulator_media.dylib
TestSimulationWrapper: /Users/casperskjaerris/Documents/cApp/Argos/lib/libargos3plugin_simulator_entities.dylib
TestSimulationWrapper: /Users/casperskjaerris/Documents/cApp/Argos/lib/libargos3plugin_simulator_genericrobot.dylib
TestSimulationWrapper: /Users/casperskjaerris/Documents/cApp/Argos/lib/libargos3plugin_simulator_dynamics2d.dylib
TestSimulationWrapper: /Users/casperskjaerris/Documents/cApp/Argos/lib/libargos3plugin_simulator_qtopengl.dylib
TestSimulationWrapper: /usr/local/lib/liblua5.3.dylib
TestSimulationWrapper: CMakeFiles/TestSimulationWrapper.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/casperskjaerris/Documents/DTU/6. Semester/Bachelorprojekt/c++ applications/argosFromBinary/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TestSimulationWrapper"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TestSimulationWrapper.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TestSimulationWrapper.dir/build: TestSimulationWrapper

.PHONY : CMakeFiles/TestSimulationWrapper.dir/build

CMakeFiles/TestSimulationWrapper.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TestSimulationWrapper.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TestSimulationWrapper.dir/clean

CMakeFiles/TestSimulationWrapper.dir/depend:
	cd "/Users/casperskjaerris/Documents/DTU/6. Semester/Bachelorprojekt/c++ applications/argosFromBinary/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/casperskjaerris/Documents/DTU/6. Semester/Bachelorprojekt/c++ applications/argosFromBinary" "/Users/casperskjaerris/Documents/DTU/6. Semester/Bachelorprojekt/c++ applications/argosFromBinary" "/Users/casperskjaerris/Documents/DTU/6. Semester/Bachelorprojekt/c++ applications/argosFromBinary/cmake-build-debug" "/Users/casperskjaerris/Documents/DTU/6. Semester/Bachelorprojekt/c++ applications/argosFromBinary/cmake-build-debug" "/Users/casperskjaerris/Documents/DTU/6. Semester/Bachelorprojekt/c++ applications/argosFromBinary/cmake-build-debug/CMakeFiles/TestSimulationWrapper.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/TestSimulationWrapper.dir/depend

