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
CMAKE_SOURCE_DIR = /root/dungnd/http_server/htpp_server

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/dungnd/http_server/htpp_server/build

# Include any dependencies generated for this target.
include CMakeFiles/http_server.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/http_server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/http_server.dir/flags.make

CMakeFiles/http_server.dir/src/main.cpp.o: CMakeFiles/http_server.dir/flags.make
CMakeFiles/http_server.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/dungnd/http_server/htpp_server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/http_server.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/http_server.dir/src/main.cpp.o -c /root/dungnd/http_server/htpp_server/src/main.cpp

CMakeFiles/http_server.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/http_server.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/dungnd/http_server/htpp_server/src/main.cpp > CMakeFiles/http_server.dir/src/main.cpp.i

CMakeFiles/http_server.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/http_server.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/dungnd/http_server/htpp_server/src/main.cpp -o CMakeFiles/http_server.dir/src/main.cpp.s

CMakeFiles/http_server.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/http_server.dir/src/main.cpp.o.requires

CMakeFiles/http_server.dir/src/main.cpp.o.provides: CMakeFiles/http_server.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/http_server.dir/build.make CMakeFiles/http_server.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/http_server.dir/src/main.cpp.o.provides

CMakeFiles/http_server.dir/src/main.cpp.o.provides.build: CMakeFiles/http_server.dir/src/main.cpp.o


CMakeFiles/http_server.dir/src/Application.cpp.o: CMakeFiles/http_server.dir/flags.make
CMakeFiles/http_server.dir/src/Application.cpp.o: ../src/Application.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/dungnd/http_server/htpp_server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/http_server.dir/src/Application.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/http_server.dir/src/Application.cpp.o -c /root/dungnd/http_server/htpp_server/src/Application.cpp

CMakeFiles/http_server.dir/src/Application.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/http_server.dir/src/Application.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/dungnd/http_server/htpp_server/src/Application.cpp > CMakeFiles/http_server.dir/src/Application.cpp.i

CMakeFiles/http_server.dir/src/Application.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/http_server.dir/src/Application.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/dungnd/http_server/htpp_server/src/Application.cpp -o CMakeFiles/http_server.dir/src/Application.cpp.s

CMakeFiles/http_server.dir/src/Application.cpp.o.requires:

.PHONY : CMakeFiles/http_server.dir/src/Application.cpp.o.requires

CMakeFiles/http_server.dir/src/Application.cpp.o.provides: CMakeFiles/http_server.dir/src/Application.cpp.o.requires
	$(MAKE) -f CMakeFiles/http_server.dir/build.make CMakeFiles/http_server.dir/src/Application.cpp.o.provides.build
.PHONY : CMakeFiles/http_server.dir/src/Application.cpp.o.provides

CMakeFiles/http_server.dir/src/Application.cpp.o.provides.build: CMakeFiles/http_server.dir/src/Application.cpp.o


CMakeFiles/http_server.dir/src/IOEpoll.cpp.o: CMakeFiles/http_server.dir/flags.make
CMakeFiles/http_server.dir/src/IOEpoll.cpp.o: ../src/IOEpoll.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/dungnd/http_server/htpp_server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/http_server.dir/src/IOEpoll.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/http_server.dir/src/IOEpoll.cpp.o -c /root/dungnd/http_server/htpp_server/src/IOEpoll.cpp

CMakeFiles/http_server.dir/src/IOEpoll.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/http_server.dir/src/IOEpoll.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/dungnd/http_server/htpp_server/src/IOEpoll.cpp > CMakeFiles/http_server.dir/src/IOEpoll.cpp.i

CMakeFiles/http_server.dir/src/IOEpoll.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/http_server.dir/src/IOEpoll.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/dungnd/http_server/htpp_server/src/IOEpoll.cpp -o CMakeFiles/http_server.dir/src/IOEpoll.cpp.s

CMakeFiles/http_server.dir/src/IOEpoll.cpp.o.requires:

.PHONY : CMakeFiles/http_server.dir/src/IOEpoll.cpp.o.requires

CMakeFiles/http_server.dir/src/IOEpoll.cpp.o.provides: CMakeFiles/http_server.dir/src/IOEpoll.cpp.o.requires
	$(MAKE) -f CMakeFiles/http_server.dir/build.make CMakeFiles/http_server.dir/src/IOEpoll.cpp.o.provides.build
.PHONY : CMakeFiles/http_server.dir/src/IOEpoll.cpp.o.provides

CMakeFiles/http_server.dir/src/IOEpoll.cpp.o.provides.build: CMakeFiles/http_server.dir/src/IOEpoll.cpp.o


CMakeFiles/http_server.dir/src/EpollWorker.cpp.o: CMakeFiles/http_server.dir/flags.make
CMakeFiles/http_server.dir/src/EpollWorker.cpp.o: ../src/EpollWorker.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/dungnd/http_server/htpp_server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/http_server.dir/src/EpollWorker.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/http_server.dir/src/EpollWorker.cpp.o -c /root/dungnd/http_server/htpp_server/src/EpollWorker.cpp

CMakeFiles/http_server.dir/src/EpollWorker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/http_server.dir/src/EpollWorker.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/dungnd/http_server/htpp_server/src/EpollWorker.cpp > CMakeFiles/http_server.dir/src/EpollWorker.cpp.i

CMakeFiles/http_server.dir/src/EpollWorker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/http_server.dir/src/EpollWorker.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/dungnd/http_server/htpp_server/src/EpollWorker.cpp -o CMakeFiles/http_server.dir/src/EpollWorker.cpp.s

CMakeFiles/http_server.dir/src/EpollWorker.cpp.o.requires:

.PHONY : CMakeFiles/http_server.dir/src/EpollWorker.cpp.o.requires

CMakeFiles/http_server.dir/src/EpollWorker.cpp.o.provides: CMakeFiles/http_server.dir/src/EpollWorker.cpp.o.requires
	$(MAKE) -f CMakeFiles/http_server.dir/build.make CMakeFiles/http_server.dir/src/EpollWorker.cpp.o.provides.build
.PHONY : CMakeFiles/http_server.dir/src/EpollWorker.cpp.o.provides

CMakeFiles/http_server.dir/src/EpollWorker.cpp.o.provides.build: CMakeFiles/http_server.dir/src/EpollWorker.cpp.o


CMakeFiles/http_server.dir/src/IOSocketCli.cpp.o: CMakeFiles/http_server.dir/flags.make
CMakeFiles/http_server.dir/src/IOSocketCli.cpp.o: ../src/IOSocketCli.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/dungnd/http_server/htpp_server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/http_server.dir/src/IOSocketCli.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/http_server.dir/src/IOSocketCli.cpp.o -c /root/dungnd/http_server/htpp_server/src/IOSocketCli.cpp

CMakeFiles/http_server.dir/src/IOSocketCli.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/http_server.dir/src/IOSocketCli.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/dungnd/http_server/htpp_server/src/IOSocketCli.cpp > CMakeFiles/http_server.dir/src/IOSocketCli.cpp.i

CMakeFiles/http_server.dir/src/IOSocketCli.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/http_server.dir/src/IOSocketCli.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/dungnd/http_server/htpp_server/src/IOSocketCli.cpp -o CMakeFiles/http_server.dir/src/IOSocketCli.cpp.s

CMakeFiles/http_server.dir/src/IOSocketCli.cpp.o.requires:

.PHONY : CMakeFiles/http_server.dir/src/IOSocketCli.cpp.o.requires

CMakeFiles/http_server.dir/src/IOSocketCli.cpp.o.provides: CMakeFiles/http_server.dir/src/IOSocketCli.cpp.o.requires
	$(MAKE) -f CMakeFiles/http_server.dir/build.make CMakeFiles/http_server.dir/src/IOSocketCli.cpp.o.provides.build
.PHONY : CMakeFiles/http_server.dir/src/IOSocketCli.cpp.o.provides

CMakeFiles/http_server.dir/src/IOSocketCli.cpp.o.provides.build: CMakeFiles/http_server.dir/src/IOSocketCli.cpp.o


CMakeFiles/http_server.dir/src/IOSocketSrv.cpp.o: CMakeFiles/http_server.dir/flags.make
CMakeFiles/http_server.dir/src/IOSocketSrv.cpp.o: ../src/IOSocketSrv.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/dungnd/http_server/htpp_server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/http_server.dir/src/IOSocketSrv.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/http_server.dir/src/IOSocketSrv.cpp.o -c /root/dungnd/http_server/htpp_server/src/IOSocketSrv.cpp

CMakeFiles/http_server.dir/src/IOSocketSrv.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/http_server.dir/src/IOSocketSrv.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/dungnd/http_server/htpp_server/src/IOSocketSrv.cpp > CMakeFiles/http_server.dir/src/IOSocketSrv.cpp.i

CMakeFiles/http_server.dir/src/IOSocketSrv.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/http_server.dir/src/IOSocketSrv.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/dungnd/http_server/htpp_server/src/IOSocketSrv.cpp -o CMakeFiles/http_server.dir/src/IOSocketSrv.cpp.s

CMakeFiles/http_server.dir/src/IOSocketSrv.cpp.o.requires:

.PHONY : CMakeFiles/http_server.dir/src/IOSocketSrv.cpp.o.requires

CMakeFiles/http_server.dir/src/IOSocketSrv.cpp.o.provides: CMakeFiles/http_server.dir/src/IOSocketSrv.cpp.o.requires
	$(MAKE) -f CMakeFiles/http_server.dir/build.make CMakeFiles/http_server.dir/src/IOSocketSrv.cpp.o.provides.build
.PHONY : CMakeFiles/http_server.dir/src/IOSocketSrv.cpp.o.provides

CMakeFiles/http_server.dir/src/IOSocketSrv.cpp.o.provides.build: CMakeFiles/http_server.dir/src/IOSocketSrv.cpp.o


CMakeFiles/http_server.dir/src/EpollPool.cpp.o: CMakeFiles/http_server.dir/flags.make
CMakeFiles/http_server.dir/src/EpollPool.cpp.o: ../src/EpollPool.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/dungnd/http_server/htpp_server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/http_server.dir/src/EpollPool.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/http_server.dir/src/EpollPool.cpp.o -c /root/dungnd/http_server/htpp_server/src/EpollPool.cpp

CMakeFiles/http_server.dir/src/EpollPool.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/http_server.dir/src/EpollPool.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/dungnd/http_server/htpp_server/src/EpollPool.cpp > CMakeFiles/http_server.dir/src/EpollPool.cpp.i

CMakeFiles/http_server.dir/src/EpollPool.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/http_server.dir/src/EpollPool.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/dungnd/http_server/htpp_server/src/EpollPool.cpp -o CMakeFiles/http_server.dir/src/EpollPool.cpp.s

CMakeFiles/http_server.dir/src/EpollPool.cpp.o.requires:

.PHONY : CMakeFiles/http_server.dir/src/EpollPool.cpp.o.requires

CMakeFiles/http_server.dir/src/EpollPool.cpp.o.provides: CMakeFiles/http_server.dir/src/EpollPool.cpp.o.requires
	$(MAKE) -f CMakeFiles/http_server.dir/build.make CMakeFiles/http_server.dir/src/EpollPool.cpp.o.provides.build
.PHONY : CMakeFiles/http_server.dir/src/EpollPool.cpp.o.provides

CMakeFiles/http_server.dir/src/EpollPool.cpp.o.provides.build: CMakeFiles/http_server.dir/src/EpollPool.cpp.o


CMakeFiles/http_server.dir/src/HttpService.cpp.o: CMakeFiles/http_server.dir/flags.make
CMakeFiles/http_server.dir/src/HttpService.cpp.o: ../src/HttpService.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/dungnd/http_server/htpp_server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/http_server.dir/src/HttpService.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/http_server.dir/src/HttpService.cpp.o -c /root/dungnd/http_server/htpp_server/src/HttpService.cpp

CMakeFiles/http_server.dir/src/HttpService.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/http_server.dir/src/HttpService.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/dungnd/http_server/htpp_server/src/HttpService.cpp > CMakeFiles/http_server.dir/src/HttpService.cpp.i

CMakeFiles/http_server.dir/src/HttpService.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/http_server.dir/src/HttpService.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/dungnd/http_server/htpp_server/src/HttpService.cpp -o CMakeFiles/http_server.dir/src/HttpService.cpp.s

CMakeFiles/http_server.dir/src/HttpService.cpp.o.requires:

.PHONY : CMakeFiles/http_server.dir/src/HttpService.cpp.o.requires

CMakeFiles/http_server.dir/src/HttpService.cpp.o.provides: CMakeFiles/http_server.dir/src/HttpService.cpp.o.requires
	$(MAKE) -f CMakeFiles/http_server.dir/build.make CMakeFiles/http_server.dir/src/HttpService.cpp.o.provides.build
.PHONY : CMakeFiles/http_server.dir/src/HttpService.cpp.o.provides

CMakeFiles/http_server.dir/src/HttpService.cpp.o.provides.build: CMakeFiles/http_server.dir/src/HttpService.cpp.o


CMakeFiles/http_server.dir/src/HttpMessage.cpp.o: CMakeFiles/http_server.dir/flags.make
CMakeFiles/http_server.dir/src/HttpMessage.cpp.o: ../src/HttpMessage.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/dungnd/http_server/htpp_server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/http_server.dir/src/HttpMessage.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/http_server.dir/src/HttpMessage.cpp.o -c /root/dungnd/http_server/htpp_server/src/HttpMessage.cpp

CMakeFiles/http_server.dir/src/HttpMessage.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/http_server.dir/src/HttpMessage.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/dungnd/http_server/htpp_server/src/HttpMessage.cpp > CMakeFiles/http_server.dir/src/HttpMessage.cpp.i

CMakeFiles/http_server.dir/src/HttpMessage.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/http_server.dir/src/HttpMessage.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/dungnd/http_server/htpp_server/src/HttpMessage.cpp -o CMakeFiles/http_server.dir/src/HttpMessage.cpp.s

CMakeFiles/http_server.dir/src/HttpMessage.cpp.o.requires:

.PHONY : CMakeFiles/http_server.dir/src/HttpMessage.cpp.o.requires

CMakeFiles/http_server.dir/src/HttpMessage.cpp.o.provides: CMakeFiles/http_server.dir/src/HttpMessage.cpp.o.requires
	$(MAKE) -f CMakeFiles/http_server.dir/build.make CMakeFiles/http_server.dir/src/HttpMessage.cpp.o.provides.build
.PHONY : CMakeFiles/http_server.dir/src/HttpMessage.cpp.o.provides

CMakeFiles/http_server.dir/src/HttpMessage.cpp.o.provides.build: CMakeFiles/http_server.dir/src/HttpMessage.cpp.o


# Object files for target http_server
http_server_OBJECTS = \
"CMakeFiles/http_server.dir/src/main.cpp.o" \
"CMakeFiles/http_server.dir/src/Application.cpp.o" \
"CMakeFiles/http_server.dir/src/IOEpoll.cpp.o" \
"CMakeFiles/http_server.dir/src/EpollWorker.cpp.o" \
"CMakeFiles/http_server.dir/src/IOSocketCli.cpp.o" \
"CMakeFiles/http_server.dir/src/IOSocketSrv.cpp.o" \
"CMakeFiles/http_server.dir/src/EpollPool.cpp.o" \
"CMakeFiles/http_server.dir/src/HttpService.cpp.o" \
"CMakeFiles/http_server.dir/src/HttpMessage.cpp.o"

# External object files for target http_server
http_server_EXTERNAL_OBJECTS =

http_server: CMakeFiles/http_server.dir/src/main.cpp.o
http_server: CMakeFiles/http_server.dir/src/Application.cpp.o
http_server: CMakeFiles/http_server.dir/src/IOEpoll.cpp.o
http_server: CMakeFiles/http_server.dir/src/EpollWorker.cpp.o
http_server: CMakeFiles/http_server.dir/src/IOSocketCli.cpp.o
http_server: CMakeFiles/http_server.dir/src/IOSocketSrv.cpp.o
http_server: CMakeFiles/http_server.dir/src/EpollPool.cpp.o
http_server: CMakeFiles/http_server.dir/src/HttpService.cpp.o
http_server: CMakeFiles/http_server.dir/src/HttpMessage.cpp.o
http_server: CMakeFiles/http_server.dir/build.make
http_server: CMakeFiles/http_server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/dungnd/http_server/htpp_server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable http_server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/http_server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/http_server.dir/build: http_server

.PHONY : CMakeFiles/http_server.dir/build

CMakeFiles/http_server.dir/requires: CMakeFiles/http_server.dir/src/main.cpp.o.requires
CMakeFiles/http_server.dir/requires: CMakeFiles/http_server.dir/src/Application.cpp.o.requires
CMakeFiles/http_server.dir/requires: CMakeFiles/http_server.dir/src/IOEpoll.cpp.o.requires
CMakeFiles/http_server.dir/requires: CMakeFiles/http_server.dir/src/EpollWorker.cpp.o.requires
CMakeFiles/http_server.dir/requires: CMakeFiles/http_server.dir/src/IOSocketCli.cpp.o.requires
CMakeFiles/http_server.dir/requires: CMakeFiles/http_server.dir/src/IOSocketSrv.cpp.o.requires
CMakeFiles/http_server.dir/requires: CMakeFiles/http_server.dir/src/EpollPool.cpp.o.requires
CMakeFiles/http_server.dir/requires: CMakeFiles/http_server.dir/src/HttpService.cpp.o.requires
CMakeFiles/http_server.dir/requires: CMakeFiles/http_server.dir/src/HttpMessage.cpp.o.requires

.PHONY : CMakeFiles/http_server.dir/requires

CMakeFiles/http_server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/http_server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/http_server.dir/clean

CMakeFiles/http_server.dir/depend:
	cd /root/dungnd/http_server/htpp_server/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/dungnd/http_server/htpp_server /root/dungnd/http_server/htpp_server /root/dungnd/http_server/htpp_server/build /root/dungnd/http_server/htpp_server/build /root/dungnd/http_server/htpp_server/build/CMakeFiles/http_server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/http_server.dir/depend

