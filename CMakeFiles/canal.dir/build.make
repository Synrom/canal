# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/synrom/lego/canal

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/synrom/lego/canal

# Include any dependencies generated for this target.
include CMakeFiles/canal.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/canal.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/canal.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/canal.dir/flags.make

CMakeFiles/canal.dir/canal.cpp.o: CMakeFiles/canal.dir/flags.make
CMakeFiles/canal.dir/canal.cpp.o: canal.cpp
CMakeFiles/canal.dir/canal.cpp.o: CMakeFiles/canal.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/synrom/lego/canal/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/canal.dir/canal.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/canal.dir/canal.cpp.o -MF CMakeFiles/canal.dir/canal.cpp.o.d -o CMakeFiles/canal.dir/canal.cpp.o -c /home/synrom/lego/canal/canal.cpp

CMakeFiles/canal.dir/canal.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/canal.dir/canal.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/synrom/lego/canal/canal.cpp > CMakeFiles/canal.dir/canal.cpp.i

CMakeFiles/canal.dir/canal.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/canal.dir/canal.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/synrom/lego/canal/canal.cpp -o CMakeFiles/canal.dir/canal.cpp.s

# Object files for target canal
canal_OBJECTS = \
"CMakeFiles/canal.dir/canal.cpp.o"

# External object files for target canal
canal_EXTERNAL_OBJECTS =

canal: CMakeFiles/canal.dir/canal.cpp.o
canal: CMakeFiles/canal.dir/build.make
canal: src/libstruct.a
canal: /usr/local/lib/libclang-cpp.so.13
canal: /usr/local/lib/libLLVMCore.a
canal: /usr/local/lib/libLLVMSupport.a
canal: /usr/local/lib/libclang-cpp.so.13
canal: /usr/local/lib/libLLVMCore.a
canal: /usr/local/lib/libLLVMBinaryFormat.a
canal: /usr/local/lib/libLLVMRemarks.a
canal: /usr/local/lib/libLLVMBitstreamReader.a
canal: /usr/local/lib/libLLVMSupport.a
canal: /usr/lib/x86_64-linux-gnu/libz.so
canal: /usr/local/lib/libLLVMDemangle.a
canal: /usr/local/lib/libLLVMBinaryFormat.a
canal: /usr/local/lib/libLLVMRemarks.a
canal: /usr/local/lib/libLLVMBitstreamReader.a
canal: /usr/local/lib/libLLVMSupport.a
canal: /usr/lib/x86_64-linux-gnu/libz.so
canal: /usr/lib/x86_64-linux-gnu/libtinfo.so
canal: /usr/local/lib/libLLVMDemangle.a
canal: CMakeFiles/canal.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/synrom/lego/canal/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable canal"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/canal.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/canal.dir/build: canal
.PHONY : CMakeFiles/canal.dir/build

CMakeFiles/canal.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/canal.dir/cmake_clean.cmake
.PHONY : CMakeFiles/canal.dir/clean

CMakeFiles/canal.dir/depend:
	cd /home/synrom/lego/canal && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/synrom/lego/canal /home/synrom/lego/canal /home/synrom/lego/canal /home/synrom/lego/canal /home/synrom/lego/canal/CMakeFiles/canal.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/canal.dir/depend
