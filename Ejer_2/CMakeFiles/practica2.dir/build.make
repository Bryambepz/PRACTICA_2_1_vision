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
CMAKE_SOURCE_DIR = /home/bryepz/Documents/VISION/PRACTICA_2_1/Ejer_2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bryepz/Documents/VISION/PRACTICA_2_1/Ejer_2

# Include any dependencies generated for this target.
include CMakeFiles/practica2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/practica2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/practica2.dir/flags.make

CMakeFiles/practica2.dir/practica2.cpp.o: CMakeFiles/practica2.dir/flags.make
CMakeFiles/practica2.dir/practica2.cpp.o: practica2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bryepz/Documents/VISION/PRACTICA_2_1/Ejer_2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/practica2.dir/practica2.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/practica2.dir/practica2.cpp.o -c /home/bryepz/Documents/VISION/PRACTICA_2_1/Ejer_2/practica2.cpp

CMakeFiles/practica2.dir/practica2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/practica2.dir/practica2.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bryepz/Documents/VISION/PRACTICA_2_1/Ejer_2/practica2.cpp > CMakeFiles/practica2.dir/practica2.cpp.i

CMakeFiles/practica2.dir/practica2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/practica2.dir/practica2.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bryepz/Documents/VISION/PRACTICA_2_1/Ejer_2/practica2.cpp -o CMakeFiles/practica2.dir/practica2.cpp.s

# Object files for target practica2
practica2_OBJECTS = \
"CMakeFiles/practica2.dir/practica2.cpp.o"

# External object files for target practica2
practica2_EXTERNAL_OBJECTS =

practica2: CMakeFiles/practica2.dir/practica2.cpp.o
practica2: CMakeFiles/practica2.dir/build.make
practica2: /usr/local/lib/libopencv_gapi.so.4.6.0
practica2: /usr/local/lib/libopencv_highgui.so.4.6.0
practica2: /usr/local/lib/libopencv_ml.so.4.6.0
practica2: /usr/local/lib/libopencv_objdetect.so.4.6.0
practica2: /usr/local/lib/libopencv_photo.so.4.6.0
practica2: /usr/local/lib/libopencv_stitching.so.4.6.0
practica2: /usr/local/lib/libopencv_video.so.4.6.0
practica2: /usr/local/lib/libopencv_videoio.so.4.6.0
practica2: /usr/local/lib/libopencv_imgcodecs.so.4.6.0
practica2: /usr/local/lib/libopencv_dnn.so.4.6.0
practica2: /usr/local/lib/libopencv_calib3d.so.4.6.0
practica2: /usr/local/lib/libopencv_features2d.so.4.6.0
practica2: /usr/local/lib/libopencv_flann.so.4.6.0
practica2: /usr/local/lib/libopencv_imgproc.so.4.6.0
practica2: /usr/local/lib/libopencv_core.so.4.6.0
practica2: CMakeFiles/practica2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bryepz/Documents/VISION/PRACTICA_2_1/Ejer_2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable practica2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/practica2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/practica2.dir/build: practica2

.PHONY : CMakeFiles/practica2.dir/build

CMakeFiles/practica2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/practica2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/practica2.dir/clean

CMakeFiles/practica2.dir/depend:
	cd /home/bryepz/Documents/VISION/PRACTICA_2_1/Ejer_2 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bryepz/Documents/VISION/PRACTICA_2_1/Ejer_2 /home/bryepz/Documents/VISION/PRACTICA_2_1/Ejer_2 /home/bryepz/Documents/VISION/PRACTICA_2_1/Ejer_2 /home/bryepz/Documents/VISION/PRACTICA_2_1/Ejer_2 /home/bryepz/Documents/VISION/PRACTICA_2_1/Ejer_2/CMakeFiles/practica2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/practica2.dir/depend

