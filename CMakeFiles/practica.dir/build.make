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
CMAKE_SOURCE_DIR = /home/bryepz/Documents/VISION/PRACTICA_2_1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bryepz/Documents/VISION/PRACTICA_2_1

# Include any dependencies generated for this target.
include CMakeFiles/practica.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/practica.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/practica.dir/flags.make

CMakeFiles/practica.dir/practica.cpp.o: CMakeFiles/practica.dir/flags.make
CMakeFiles/practica.dir/practica.cpp.o: practica.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bryepz/Documents/VISION/PRACTICA_2_1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/practica.dir/practica.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/practica.dir/practica.cpp.o -c /home/bryepz/Documents/VISION/PRACTICA_2_1/practica.cpp

CMakeFiles/practica.dir/practica.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/practica.dir/practica.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bryepz/Documents/VISION/PRACTICA_2_1/practica.cpp > CMakeFiles/practica.dir/practica.cpp.i

CMakeFiles/practica.dir/practica.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/practica.dir/practica.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bryepz/Documents/VISION/PRACTICA_2_1/practica.cpp -o CMakeFiles/practica.dir/practica.cpp.s

# Object files for target practica
practica_OBJECTS = \
"CMakeFiles/practica.dir/practica.cpp.o"

# External object files for target practica
practica_EXTERNAL_OBJECTS =

practica: CMakeFiles/practica.dir/practica.cpp.o
practica: CMakeFiles/practica.dir/build.make
practica: /usr/local/lib/libopencv_gapi.so.4.6.0
practica: /usr/local/lib/libopencv_highgui.so.4.6.0
practica: /usr/local/lib/libopencv_ml.so.4.6.0
practica: /usr/local/lib/libopencv_objdetect.so.4.6.0
practica: /usr/local/lib/libopencv_photo.so.4.6.0
practica: /usr/local/lib/libopencv_stitching.so.4.6.0
practica: /usr/local/lib/libopencv_video.so.4.6.0
practica: /usr/local/lib/libopencv_videoio.so.4.6.0
practica: /usr/local/lib/libopencv_imgcodecs.so.4.6.0
practica: /usr/local/lib/libopencv_dnn.so.4.6.0
practica: /usr/local/lib/libopencv_calib3d.so.4.6.0
practica: /usr/local/lib/libopencv_features2d.so.4.6.0
practica: /usr/local/lib/libopencv_flann.so.4.6.0
practica: /usr/local/lib/libopencv_imgproc.so.4.6.0
practica: /usr/local/lib/libopencv_core.so.4.6.0
practica: CMakeFiles/practica.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bryepz/Documents/VISION/PRACTICA_2_1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable practica"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/practica.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/practica.dir/build: practica

.PHONY : CMakeFiles/practica.dir/build

CMakeFiles/practica.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/practica.dir/cmake_clean.cmake
.PHONY : CMakeFiles/practica.dir/clean

CMakeFiles/practica.dir/depend:
	cd /home/bryepz/Documents/VISION/PRACTICA_2_1 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bryepz/Documents/VISION/PRACTICA_2_1 /home/bryepz/Documents/VISION/PRACTICA_2_1 /home/bryepz/Documents/VISION/PRACTICA_2_1 /home/bryepz/Documents/VISION/PRACTICA_2_1 /home/bryepz/Documents/VISION/PRACTICA_2_1/CMakeFiles/practica.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/practica.dir/depend

