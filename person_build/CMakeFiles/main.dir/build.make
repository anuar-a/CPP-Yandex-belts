# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\Anuar\Downloads\cmake-3.14.3-win64-x64\cmake-3.14.3-win64-x64\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\Anuar\Downloads\cmake-3.14.3-win64-x64\cmake-3.14.3-win64-x64\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Anuar\eclipse-cpp\person

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Anuar\eclipse-cpp\person_build

# Include any dependencies generated for this target.
include CMakeFiles/main.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main.dir/flags.make

person.pb.h: C:/Users/Anuar/eclipse-cpp/person/person.proto
person.pb.h: C:/Users/Anuar/eclipse-cpp/protobuf/bin/protoc.exe
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=C:\Users\Anuar\eclipse-cpp\person_build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Running cpp protocol buffer compiler on person.proto"
	C:\Users\Anuar\eclipse-cpp\protobuf\bin\protoc.exe --cpp_out C:/Users/Anuar/eclipse-cpp/person_build -I C:/Users/Anuar/eclipse-cpp/person C:/Users/Anuar/eclipse-cpp/person/person.proto

person.pb.cc: person.pb.h
	@$(CMAKE_COMMAND) -E touch_nocreate person.pb.cc

CMakeFiles/main.dir/main.cpp.obj: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/main.cpp.obj: CMakeFiles/main.dir/includes_CXX.rsp
CMakeFiles/main.dir/main.cpp.obj: C:/Users/Anuar/eclipse-cpp/person/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Anuar\eclipse-cpp\person_build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/main.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\main.dir\main.cpp.obj -c C:\Users\Anuar\eclipse-cpp\person\main.cpp

CMakeFiles/main.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Anuar\eclipse-cpp\person\main.cpp > CMakeFiles\main.dir\main.cpp.i

CMakeFiles/main.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Anuar\eclipse-cpp\person\main.cpp -o CMakeFiles\main.dir\main.cpp.s

CMakeFiles/main.dir/person.pb.cc.obj: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/person.pb.cc.obj: CMakeFiles/main.dir/includes_CXX.rsp
CMakeFiles/main.dir/person.pb.cc.obj: person.pb.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Anuar\eclipse-cpp\person_build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/main.dir/person.pb.cc.obj"
	C:\PROGRA~1\MINGW-~1\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\main.dir\person.pb.cc.obj -c C:\Users\Anuar\eclipse-cpp\person_build\person.pb.cc

CMakeFiles/main.dir/person.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/person.pb.cc.i"
	C:\PROGRA~1\MINGW-~1\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Anuar\eclipse-cpp\person_build\person.pb.cc > CMakeFiles\main.dir\person.pb.cc.i

CMakeFiles/main.dir/person.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/person.pb.cc.s"
	C:\PROGRA~1\MINGW-~1\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Anuar\eclipse-cpp\person_build\person.pb.cc -o CMakeFiles\main.dir\person.pb.cc.s

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/main.cpp.obj" \
"CMakeFiles/main.dir/person.pb.cc.obj"

# External object files for target main
main_EXTERNAL_OBJECTS =

main.exe: CMakeFiles/main.dir/main.cpp.obj
main.exe: CMakeFiles/main.dir/person.pb.cc.obj
main.exe: CMakeFiles/main.dir/build.make
main.exe: C:/Users/Anuar/eclipse-cpp/protobuf/lib/libprotobuf.a
main.exe: CMakeFiles/main.dir/linklibs.rsp
main.exe: CMakeFiles/main.dir/objects1.rsp
main.exe: CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Anuar\eclipse-cpp\person_build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable main.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\main.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main.dir/build: main.exe

.PHONY : CMakeFiles/main.dir/build

CMakeFiles/main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\main.dir\cmake_clean.cmake
.PHONY : CMakeFiles/main.dir/clean

CMakeFiles/main.dir/depend: person.pb.h
CMakeFiles/main.dir/depend: person.pb.cc
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Anuar\eclipse-cpp\person C:\Users\Anuar\eclipse-cpp\person C:\Users\Anuar\eclipse-cpp\person_build C:\Users\Anuar\eclipse-cpp\person_build C:\Users\Anuar\eclipse-cpp\person_build\CMakeFiles\main.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main.dir/depend

