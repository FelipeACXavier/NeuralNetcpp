# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_SOURCE_DIR = /home/felipe_xavier/Projects/NeuralNetcpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/felipe_xavier/Projects/NeuralNetcpp

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/felipe_xavier/Projects/NeuralNetcpp/CMakeFiles /home/felipe_xavier/Projects/NeuralNetcpp/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/felipe_xavier/Projects/NeuralNetcpp/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named main.cpp

# Build rule for target.
main.cpp: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 main.cpp
.PHONY : main.cpp

# fast build rule for target.
main.cpp/fast:
	$(MAKE) -f CMakeFiles/main.cpp.dir/build.make CMakeFiles/main.cpp.dir/build
.PHONY : main.cpp/fast

Matrix.o: Matrix.cpp.o

.PHONY : Matrix.o

# target to build an object file
Matrix.cpp.o:
	$(MAKE) -f CMakeFiles/main.cpp.dir/build.make CMakeFiles/main.cpp.dir/Matrix.cpp.o
.PHONY : Matrix.cpp.o

Matrix.i: Matrix.cpp.i

.PHONY : Matrix.i

# target to preprocess a source file
Matrix.cpp.i:
	$(MAKE) -f CMakeFiles/main.cpp.dir/build.make CMakeFiles/main.cpp.dir/Matrix.cpp.i
.PHONY : Matrix.cpp.i

Matrix.s: Matrix.cpp.s

.PHONY : Matrix.s

# target to generate assembly for a file
Matrix.cpp.s:
	$(MAKE) -f CMakeFiles/main.cpp.dir/build.make CMakeFiles/main.cpp.dir/Matrix.cpp.s
.PHONY : Matrix.cpp.s

NeuralNet.o: NeuralNet.cpp.o

.PHONY : NeuralNet.o

# target to build an object file
NeuralNet.cpp.o:
	$(MAKE) -f CMakeFiles/main.cpp.dir/build.make CMakeFiles/main.cpp.dir/NeuralNet.cpp.o
.PHONY : NeuralNet.cpp.o

NeuralNet.i: NeuralNet.cpp.i

.PHONY : NeuralNet.i

# target to preprocess a source file
NeuralNet.cpp.i:
	$(MAKE) -f CMakeFiles/main.cpp.dir/build.make CMakeFiles/main.cpp.dir/NeuralNet.cpp.i
.PHONY : NeuralNet.cpp.i

NeuralNet.s: NeuralNet.cpp.s

.PHONY : NeuralNet.s

# target to generate assembly for a file
NeuralNet.cpp.s:
	$(MAKE) -f CMakeFiles/main.cpp.dir/build.make CMakeFiles/main.cpp.dir/NeuralNet.cpp.s
.PHONY : NeuralNet.cpp.s

Neuron.o: Neuron.cpp.o

.PHONY : Neuron.o

# target to build an object file
Neuron.cpp.o:
	$(MAKE) -f CMakeFiles/main.cpp.dir/build.make CMakeFiles/main.cpp.dir/Neuron.cpp.o
.PHONY : Neuron.cpp.o

Neuron.i: Neuron.cpp.i

.PHONY : Neuron.i

# target to preprocess a source file
Neuron.cpp.i:
	$(MAKE) -f CMakeFiles/main.cpp.dir/build.make CMakeFiles/main.cpp.dir/Neuron.cpp.i
.PHONY : Neuron.cpp.i

Neuron.s: Neuron.cpp.s

.PHONY : Neuron.s

# target to generate assembly for a file
Neuron.cpp.s:
	$(MAKE) -f CMakeFiles/main.cpp.dir/build.make CMakeFiles/main.cpp.dir/Neuron.cpp.s
.PHONY : Neuron.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... main.cpp"
	@echo "... Matrix.o"
	@echo "... Matrix.i"
	@echo "... Matrix.s"
	@echo "... NeuralNet.o"
	@echo "... NeuralNet.i"
	@echo "... NeuralNet.s"
	@echo "... Neuron.o"
	@echo "... Neuron.i"
	@echo "... Neuron.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

