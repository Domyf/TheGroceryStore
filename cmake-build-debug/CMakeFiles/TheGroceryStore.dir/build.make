# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /mnt/c/Users/Domenico/Documents/GitHub/TheGroceryStore

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/Domenico/Documents/GitHub/TheGroceryStore/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/TheGroceryStore.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TheGroceryStore.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TheGroceryStore.dir/flags.make

CMakeFiles/TheGroceryStore.dir/src/direttore.c.o: CMakeFiles/TheGroceryStore.dir/flags.make
CMakeFiles/TheGroceryStore.dir/src/direttore.c.o: ../src/direttore.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/Domenico/Documents/GitHub/TheGroceryStore/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/TheGroceryStore.dir/src/direttore.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/TheGroceryStore.dir/src/direttore.c.o   -c /mnt/c/Users/Domenico/Documents/GitHub/TheGroceryStore/src/direttore.c

CMakeFiles/TheGroceryStore.dir/src/direttore.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TheGroceryStore.dir/src/direttore.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/Domenico/Documents/GitHub/TheGroceryStore/src/direttore.c > CMakeFiles/TheGroceryStore.dir/src/direttore.c.i

CMakeFiles/TheGroceryStore.dir/src/direttore.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TheGroceryStore.dir/src/direttore.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/Domenico/Documents/GitHub/TheGroceryStore/src/direttore.c -o CMakeFiles/TheGroceryStore.dir/src/direttore.c.s

CMakeFiles/TheGroceryStore.dir/src/direttore.c.o.requires:

.PHONY : CMakeFiles/TheGroceryStore.dir/src/direttore.c.o.requires

CMakeFiles/TheGroceryStore.dir/src/direttore.c.o.provides: CMakeFiles/TheGroceryStore.dir/src/direttore.c.o.requires
	$(MAKE) -f CMakeFiles/TheGroceryStore.dir/build.make CMakeFiles/TheGroceryStore.dir/src/direttore.c.o.provides.build
.PHONY : CMakeFiles/TheGroceryStore.dir/src/direttore.c.o.provides

CMakeFiles/TheGroceryStore.dir/src/direttore.c.o.provides.build: CMakeFiles/TheGroceryStore.dir/src/direttore.c.o


CMakeFiles/TheGroceryStore.dir/src/config.c.o: CMakeFiles/TheGroceryStore.dir/flags.make
CMakeFiles/TheGroceryStore.dir/src/config.c.o: ../src/config.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/Domenico/Documents/GitHub/TheGroceryStore/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/TheGroceryStore.dir/src/config.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/TheGroceryStore.dir/src/config.c.o   -c /mnt/c/Users/Domenico/Documents/GitHub/TheGroceryStore/src/config.c

CMakeFiles/TheGroceryStore.dir/src/config.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TheGroceryStore.dir/src/config.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/Domenico/Documents/GitHub/TheGroceryStore/src/config.c > CMakeFiles/TheGroceryStore.dir/src/config.c.i

CMakeFiles/TheGroceryStore.dir/src/config.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TheGroceryStore.dir/src/config.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/Domenico/Documents/GitHub/TheGroceryStore/src/config.c -o CMakeFiles/TheGroceryStore.dir/src/config.c.s

CMakeFiles/TheGroceryStore.dir/src/config.c.o.requires:

.PHONY : CMakeFiles/TheGroceryStore.dir/src/config.c.o.requires

CMakeFiles/TheGroceryStore.dir/src/config.c.o.provides: CMakeFiles/TheGroceryStore.dir/src/config.c.o.requires
	$(MAKE) -f CMakeFiles/TheGroceryStore.dir/build.make CMakeFiles/TheGroceryStore.dir/src/config.c.o.provides.build
.PHONY : CMakeFiles/TheGroceryStore.dir/src/config.c.o.provides

CMakeFiles/TheGroceryStore.dir/src/config.c.o.provides.build: CMakeFiles/TheGroceryStore.dir/src/config.c.o


CMakeFiles/TheGroceryStore.dir/src/utils.c.o: CMakeFiles/TheGroceryStore.dir/flags.make
CMakeFiles/TheGroceryStore.dir/src/utils.c.o: ../src/utils.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/Domenico/Documents/GitHub/TheGroceryStore/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/TheGroceryStore.dir/src/utils.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/TheGroceryStore.dir/src/utils.c.o   -c /mnt/c/Users/Domenico/Documents/GitHub/TheGroceryStore/src/utils.c

CMakeFiles/TheGroceryStore.dir/src/utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TheGroceryStore.dir/src/utils.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/Domenico/Documents/GitHub/TheGroceryStore/src/utils.c > CMakeFiles/TheGroceryStore.dir/src/utils.c.i

CMakeFiles/TheGroceryStore.dir/src/utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TheGroceryStore.dir/src/utils.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/Domenico/Documents/GitHub/TheGroceryStore/src/utils.c -o CMakeFiles/TheGroceryStore.dir/src/utils.c.s

CMakeFiles/TheGroceryStore.dir/src/utils.c.o.requires:

.PHONY : CMakeFiles/TheGroceryStore.dir/src/utils.c.o.requires

CMakeFiles/TheGroceryStore.dir/src/utils.c.o.provides: CMakeFiles/TheGroceryStore.dir/src/utils.c.o.requires
	$(MAKE) -f CMakeFiles/TheGroceryStore.dir/build.make CMakeFiles/TheGroceryStore.dir/src/utils.c.o.provides.build
.PHONY : CMakeFiles/TheGroceryStore.dir/src/utils.c.o.provides

CMakeFiles/TheGroceryStore.dir/src/utils.c.o.provides.build: CMakeFiles/TheGroceryStore.dir/src/utils.c.o


CMakeFiles/TheGroceryStore.dir/src/supermercato.c.o: CMakeFiles/TheGroceryStore.dir/flags.make
CMakeFiles/TheGroceryStore.dir/src/supermercato.c.o: ../src/supermercato.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/Domenico/Documents/GitHub/TheGroceryStore/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/TheGroceryStore.dir/src/supermercato.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/TheGroceryStore.dir/src/supermercato.c.o   -c /mnt/c/Users/Domenico/Documents/GitHub/TheGroceryStore/src/supermercato.c

CMakeFiles/TheGroceryStore.dir/src/supermercato.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TheGroceryStore.dir/src/supermercato.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/Domenico/Documents/GitHub/TheGroceryStore/src/supermercato.c > CMakeFiles/TheGroceryStore.dir/src/supermercato.c.i

CMakeFiles/TheGroceryStore.dir/src/supermercato.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TheGroceryStore.dir/src/supermercato.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/Domenico/Documents/GitHub/TheGroceryStore/src/supermercato.c -o CMakeFiles/TheGroceryStore.dir/src/supermercato.c.s

CMakeFiles/TheGroceryStore.dir/src/supermercato.c.o.requires:

.PHONY : CMakeFiles/TheGroceryStore.dir/src/supermercato.c.o.requires

CMakeFiles/TheGroceryStore.dir/src/supermercato.c.o.provides: CMakeFiles/TheGroceryStore.dir/src/supermercato.c.o.requires
	$(MAKE) -f CMakeFiles/TheGroceryStore.dir/build.make CMakeFiles/TheGroceryStore.dir/src/supermercato.c.o.provides.build
.PHONY : CMakeFiles/TheGroceryStore.dir/src/supermercato.c.o.provides

CMakeFiles/TheGroceryStore.dir/src/supermercato.c.o.provides.build: CMakeFiles/TheGroceryStore.dir/src/supermercato.c.o


CMakeFiles/TheGroceryStore.dir/src/sig_handling.c.o: CMakeFiles/TheGroceryStore.dir/flags.make
CMakeFiles/TheGroceryStore.dir/src/sig_handling.c.o: ../src/sig_handling.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/Domenico/Documents/GitHub/TheGroceryStore/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/TheGroceryStore.dir/src/sig_handling.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/TheGroceryStore.dir/src/sig_handling.c.o   -c /mnt/c/Users/Domenico/Documents/GitHub/TheGroceryStore/src/sig_handling.c

CMakeFiles/TheGroceryStore.dir/src/sig_handling.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TheGroceryStore.dir/src/sig_handling.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/Domenico/Documents/GitHub/TheGroceryStore/src/sig_handling.c > CMakeFiles/TheGroceryStore.dir/src/sig_handling.c.i

CMakeFiles/TheGroceryStore.dir/src/sig_handling.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TheGroceryStore.dir/src/sig_handling.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/Domenico/Documents/GitHub/TheGroceryStore/src/sig_handling.c -o CMakeFiles/TheGroceryStore.dir/src/sig_handling.c.s

CMakeFiles/TheGroceryStore.dir/src/sig_handling.c.o.requires:

.PHONY : CMakeFiles/TheGroceryStore.dir/src/sig_handling.c.o.requires

CMakeFiles/TheGroceryStore.dir/src/sig_handling.c.o.provides: CMakeFiles/TheGroceryStore.dir/src/sig_handling.c.o.requires
	$(MAKE) -f CMakeFiles/TheGroceryStore.dir/build.make CMakeFiles/TheGroceryStore.dir/src/sig_handling.c.o.provides.build
.PHONY : CMakeFiles/TheGroceryStore.dir/src/sig_handling.c.o.provides

CMakeFiles/TheGroceryStore.dir/src/sig_handling.c.o.provides.build: CMakeFiles/TheGroceryStore.dir/src/sig_handling.c.o


CMakeFiles/TheGroceryStore.dir/src/af_unix_conn.c.o: CMakeFiles/TheGroceryStore.dir/flags.make
CMakeFiles/TheGroceryStore.dir/src/af_unix_conn.c.o: ../src/af_unix_conn.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/Domenico/Documents/GitHub/TheGroceryStore/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/TheGroceryStore.dir/src/af_unix_conn.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/TheGroceryStore.dir/src/af_unix_conn.c.o   -c /mnt/c/Users/Domenico/Documents/GitHub/TheGroceryStore/src/af_unix_conn.c

CMakeFiles/TheGroceryStore.dir/src/af_unix_conn.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TheGroceryStore.dir/src/af_unix_conn.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/Domenico/Documents/GitHub/TheGroceryStore/src/af_unix_conn.c > CMakeFiles/TheGroceryStore.dir/src/af_unix_conn.c.i

CMakeFiles/TheGroceryStore.dir/src/af_unix_conn.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TheGroceryStore.dir/src/af_unix_conn.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/Domenico/Documents/GitHub/TheGroceryStore/src/af_unix_conn.c -o CMakeFiles/TheGroceryStore.dir/src/af_unix_conn.c.s

CMakeFiles/TheGroceryStore.dir/src/af_unix_conn.c.o.requires:

.PHONY : CMakeFiles/TheGroceryStore.dir/src/af_unix_conn.c.o.requires

CMakeFiles/TheGroceryStore.dir/src/af_unix_conn.c.o.provides: CMakeFiles/TheGroceryStore.dir/src/af_unix_conn.c.o.requires
	$(MAKE) -f CMakeFiles/TheGroceryStore.dir/build.make CMakeFiles/TheGroceryStore.dir/src/af_unix_conn.c.o.provides.build
.PHONY : CMakeFiles/TheGroceryStore.dir/src/af_unix_conn.c.o.provides

CMakeFiles/TheGroceryStore.dir/src/af_unix_conn.c.o.provides.build: CMakeFiles/TheGroceryStore.dir/src/af_unix_conn.c.o


CMakeFiles/TheGroceryStore.dir/src/scfiles.c.o: CMakeFiles/TheGroceryStore.dir/flags.make
CMakeFiles/TheGroceryStore.dir/src/scfiles.c.o: ../src/scfiles.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/Domenico/Documents/GitHub/TheGroceryStore/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/TheGroceryStore.dir/src/scfiles.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/TheGroceryStore.dir/src/scfiles.c.o   -c /mnt/c/Users/Domenico/Documents/GitHub/TheGroceryStore/src/scfiles.c

CMakeFiles/TheGroceryStore.dir/src/scfiles.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TheGroceryStore.dir/src/scfiles.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/Domenico/Documents/GitHub/TheGroceryStore/src/scfiles.c > CMakeFiles/TheGroceryStore.dir/src/scfiles.c.i

CMakeFiles/TheGroceryStore.dir/src/scfiles.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TheGroceryStore.dir/src/scfiles.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/Domenico/Documents/GitHub/TheGroceryStore/src/scfiles.c -o CMakeFiles/TheGroceryStore.dir/src/scfiles.c.s

CMakeFiles/TheGroceryStore.dir/src/scfiles.c.o.requires:

.PHONY : CMakeFiles/TheGroceryStore.dir/src/scfiles.c.o.requires

CMakeFiles/TheGroceryStore.dir/src/scfiles.c.o.provides: CMakeFiles/TheGroceryStore.dir/src/scfiles.c.o.requires
	$(MAKE) -f CMakeFiles/TheGroceryStore.dir/build.make CMakeFiles/TheGroceryStore.dir/src/scfiles.c.o.provides.build
.PHONY : CMakeFiles/TheGroceryStore.dir/src/scfiles.c.o.provides

CMakeFiles/TheGroceryStore.dir/src/scfiles.c.o.provides.build: CMakeFiles/TheGroceryStore.dir/src/scfiles.c.o


CMakeFiles/TheGroceryStore.dir/src/queue.c.o: CMakeFiles/TheGroceryStore.dir/flags.make
CMakeFiles/TheGroceryStore.dir/src/queue.c.o: ../src/queue.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/Domenico/Documents/GitHub/TheGroceryStore/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/TheGroceryStore.dir/src/queue.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/TheGroceryStore.dir/src/queue.c.o   -c /mnt/c/Users/Domenico/Documents/GitHub/TheGroceryStore/src/queue.c

CMakeFiles/TheGroceryStore.dir/src/queue.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TheGroceryStore.dir/src/queue.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/Domenico/Documents/GitHub/TheGroceryStore/src/queue.c > CMakeFiles/TheGroceryStore.dir/src/queue.c.i

CMakeFiles/TheGroceryStore.dir/src/queue.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TheGroceryStore.dir/src/queue.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/Domenico/Documents/GitHub/TheGroceryStore/src/queue.c -o CMakeFiles/TheGroceryStore.dir/src/queue.c.s

CMakeFiles/TheGroceryStore.dir/src/queue.c.o.requires:

.PHONY : CMakeFiles/TheGroceryStore.dir/src/queue.c.o.requires

CMakeFiles/TheGroceryStore.dir/src/queue.c.o.provides: CMakeFiles/TheGroceryStore.dir/src/queue.c.o.requires
	$(MAKE) -f CMakeFiles/TheGroceryStore.dir/build.make CMakeFiles/TheGroceryStore.dir/src/queue.c.o.provides.build
.PHONY : CMakeFiles/TheGroceryStore.dir/src/queue.c.o.provides

CMakeFiles/TheGroceryStore.dir/src/queue.c.o.provides.build: CMakeFiles/TheGroceryStore.dir/src/queue.c.o


CMakeFiles/TheGroceryStore.dir/src/store.c.o: CMakeFiles/TheGroceryStore.dir/flags.make
CMakeFiles/TheGroceryStore.dir/src/store.c.o: ../src/store.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/Domenico/Documents/GitHub/TheGroceryStore/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/TheGroceryStore.dir/src/store.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/TheGroceryStore.dir/src/store.c.o   -c /mnt/c/Users/Domenico/Documents/GitHub/TheGroceryStore/src/store.c

CMakeFiles/TheGroceryStore.dir/src/store.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TheGroceryStore.dir/src/store.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/Domenico/Documents/GitHub/TheGroceryStore/src/store.c > CMakeFiles/TheGroceryStore.dir/src/store.c.i

CMakeFiles/TheGroceryStore.dir/src/store.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TheGroceryStore.dir/src/store.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/Domenico/Documents/GitHub/TheGroceryStore/src/store.c -o CMakeFiles/TheGroceryStore.dir/src/store.c.s

CMakeFiles/TheGroceryStore.dir/src/store.c.o.requires:

.PHONY : CMakeFiles/TheGroceryStore.dir/src/store.c.o.requires

CMakeFiles/TheGroceryStore.dir/src/store.c.o.provides: CMakeFiles/TheGroceryStore.dir/src/store.c.o.requires
	$(MAKE) -f CMakeFiles/TheGroceryStore.dir/build.make CMakeFiles/TheGroceryStore.dir/src/store.c.o.provides.build
.PHONY : CMakeFiles/TheGroceryStore.dir/src/store.c.o.provides

CMakeFiles/TheGroceryStore.dir/src/store.c.o.provides.build: CMakeFiles/TheGroceryStore.dir/src/store.c.o


# Object files for target TheGroceryStore
TheGroceryStore_OBJECTS = \
"CMakeFiles/TheGroceryStore.dir/src/direttore.c.o" \
"CMakeFiles/TheGroceryStore.dir/src/config.c.o" \
"CMakeFiles/TheGroceryStore.dir/src/utils.c.o" \
"CMakeFiles/TheGroceryStore.dir/src/supermercato.c.o" \
"CMakeFiles/TheGroceryStore.dir/src/sig_handling.c.o" \
"CMakeFiles/TheGroceryStore.dir/src/af_unix_conn.c.o" \
"CMakeFiles/TheGroceryStore.dir/src/scfiles.c.o" \
"CMakeFiles/TheGroceryStore.dir/src/queue.c.o" \
"CMakeFiles/TheGroceryStore.dir/src/store.c.o"

# External object files for target TheGroceryStore
TheGroceryStore_EXTERNAL_OBJECTS =

TheGroceryStore: CMakeFiles/TheGroceryStore.dir/src/direttore.c.o
TheGroceryStore: CMakeFiles/TheGroceryStore.dir/src/config.c.o
TheGroceryStore: CMakeFiles/TheGroceryStore.dir/src/utils.c.o
TheGroceryStore: CMakeFiles/TheGroceryStore.dir/src/supermercato.c.o
TheGroceryStore: CMakeFiles/TheGroceryStore.dir/src/sig_handling.c.o
TheGroceryStore: CMakeFiles/TheGroceryStore.dir/src/af_unix_conn.c.o
TheGroceryStore: CMakeFiles/TheGroceryStore.dir/src/scfiles.c.o
TheGroceryStore: CMakeFiles/TheGroceryStore.dir/src/queue.c.o
TheGroceryStore: CMakeFiles/TheGroceryStore.dir/src/store.c.o
TheGroceryStore: CMakeFiles/TheGroceryStore.dir/build.make
TheGroceryStore: CMakeFiles/TheGroceryStore.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/Domenico/Documents/GitHub/TheGroceryStore/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking C executable TheGroceryStore"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TheGroceryStore.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TheGroceryStore.dir/build: TheGroceryStore

.PHONY : CMakeFiles/TheGroceryStore.dir/build

CMakeFiles/TheGroceryStore.dir/requires: CMakeFiles/TheGroceryStore.dir/src/direttore.c.o.requires
CMakeFiles/TheGroceryStore.dir/requires: CMakeFiles/TheGroceryStore.dir/src/config.c.o.requires
CMakeFiles/TheGroceryStore.dir/requires: CMakeFiles/TheGroceryStore.dir/src/utils.c.o.requires
CMakeFiles/TheGroceryStore.dir/requires: CMakeFiles/TheGroceryStore.dir/src/supermercato.c.o.requires
CMakeFiles/TheGroceryStore.dir/requires: CMakeFiles/TheGroceryStore.dir/src/sig_handling.c.o.requires
CMakeFiles/TheGroceryStore.dir/requires: CMakeFiles/TheGroceryStore.dir/src/af_unix_conn.c.o.requires
CMakeFiles/TheGroceryStore.dir/requires: CMakeFiles/TheGroceryStore.dir/src/scfiles.c.o.requires
CMakeFiles/TheGroceryStore.dir/requires: CMakeFiles/TheGroceryStore.dir/src/queue.c.o.requires
CMakeFiles/TheGroceryStore.dir/requires: CMakeFiles/TheGroceryStore.dir/src/store.c.o.requires

.PHONY : CMakeFiles/TheGroceryStore.dir/requires

CMakeFiles/TheGroceryStore.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TheGroceryStore.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TheGroceryStore.dir/clean

CMakeFiles/TheGroceryStore.dir/depend:
	cd /mnt/c/Users/Domenico/Documents/GitHub/TheGroceryStore/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/Domenico/Documents/GitHub/TheGroceryStore /mnt/c/Users/Domenico/Documents/GitHub/TheGroceryStore /mnt/c/Users/Domenico/Documents/GitHub/TheGroceryStore/cmake-build-debug /mnt/c/Users/Domenico/Documents/GitHub/TheGroceryStore/cmake-build-debug /mnt/c/Users/Domenico/Documents/GitHub/TheGroceryStore/cmake-build-debug/CMakeFiles/TheGroceryStore.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TheGroceryStore.dir/depend

