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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/vanessa/Dropbox/Documents/Disciplinas/ED/Aulas/11-ArvoreB/arvore-b-disco

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/vanessa/Dropbox/Documents/Disciplinas/ED/Aulas/11-ArvoreB/arvore-b-disco/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/arvore-b-disco.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/arvore-b-disco.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/arvore-b-disco.dir/flags.make

CMakeFiles/arvore-b-disco.dir/arvore_b.c.o: CMakeFiles/arvore-b-disco.dir/flags.make
CMakeFiles/arvore-b-disco.dir/arvore_b.c.o: ../arvore_b.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/vanessa/Dropbox/Documents/Disciplinas/ED/Aulas/11-ArvoreB/arvore-b-disco/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/arvore-b-disco.dir/arvore_b.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/arvore-b-disco.dir/arvore_b.c.o   -c /Users/vanessa/Dropbox/Documents/Disciplinas/ED/Aulas/11-ArvoreB/arvore-b-disco/arvore_b.c

CMakeFiles/arvore-b-disco.dir/arvore_b.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/arvore-b-disco.dir/arvore_b.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/vanessa/Dropbox/Documents/Disciplinas/ED/Aulas/11-ArvoreB/arvore-b-disco/arvore_b.c > CMakeFiles/arvore-b-disco.dir/arvore_b.c.i

CMakeFiles/arvore-b-disco.dir/arvore_b.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/arvore-b-disco.dir/arvore_b.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/vanessa/Dropbox/Documents/Disciplinas/ED/Aulas/11-ArvoreB/arvore-b-disco/arvore_b.c -o CMakeFiles/arvore-b-disco.dir/arvore_b.c.s

CMakeFiles/arvore-b-disco.dir/arvore_b.c.o.requires:

.PHONY : CMakeFiles/arvore-b-disco.dir/arvore_b.c.o.requires

CMakeFiles/arvore-b-disco.dir/arvore_b.c.o.provides: CMakeFiles/arvore-b-disco.dir/arvore_b.c.o.requires
	$(MAKE) -f CMakeFiles/arvore-b-disco.dir/build.make CMakeFiles/arvore-b-disco.dir/arvore_b.c.o.provides.build
.PHONY : CMakeFiles/arvore-b-disco.dir/arvore_b.c.o.provides

CMakeFiles/arvore-b-disco.dir/arvore_b.c.o.provides.build: CMakeFiles/arvore-b-disco.dir/arvore_b.c.o


CMakeFiles/arvore-b-disco.dir/cliente.c.o: CMakeFiles/arvore-b-disco.dir/flags.make
CMakeFiles/arvore-b-disco.dir/cliente.c.o: ../cliente.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/vanessa/Dropbox/Documents/Disciplinas/ED/Aulas/11-ArvoreB/arvore-b-disco/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/arvore-b-disco.dir/cliente.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/arvore-b-disco.dir/cliente.c.o   -c /Users/vanessa/Dropbox/Documents/Disciplinas/ED/Aulas/11-ArvoreB/arvore-b-disco/cliente.c

CMakeFiles/arvore-b-disco.dir/cliente.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/arvore-b-disco.dir/cliente.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/vanessa/Dropbox/Documents/Disciplinas/ED/Aulas/11-ArvoreB/arvore-b-disco/cliente.c > CMakeFiles/arvore-b-disco.dir/cliente.c.i

CMakeFiles/arvore-b-disco.dir/cliente.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/arvore-b-disco.dir/cliente.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/vanessa/Dropbox/Documents/Disciplinas/ED/Aulas/11-ArvoreB/arvore-b-disco/cliente.c -o CMakeFiles/arvore-b-disco.dir/cliente.c.s

CMakeFiles/arvore-b-disco.dir/cliente.c.o.requires:

.PHONY : CMakeFiles/arvore-b-disco.dir/cliente.c.o.requires

CMakeFiles/arvore-b-disco.dir/cliente.c.o.provides: CMakeFiles/arvore-b-disco.dir/cliente.c.o.requires
	$(MAKE) -f CMakeFiles/arvore-b-disco.dir/build.make CMakeFiles/arvore-b-disco.dir/cliente.c.o.provides.build
.PHONY : CMakeFiles/arvore-b-disco.dir/cliente.c.o.provides

CMakeFiles/arvore-b-disco.dir/cliente.c.o.provides.build: CMakeFiles/arvore-b-disco.dir/cliente.c.o


CMakeFiles/arvore-b-disco.dir/lista_clientes.c.o: CMakeFiles/arvore-b-disco.dir/flags.make
CMakeFiles/arvore-b-disco.dir/lista_clientes.c.o: ../lista_clientes.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/vanessa/Dropbox/Documents/Disciplinas/ED/Aulas/11-ArvoreB/arvore-b-disco/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/arvore-b-disco.dir/lista_clientes.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/arvore-b-disco.dir/lista_clientes.c.o   -c /Users/vanessa/Dropbox/Documents/Disciplinas/ED/Aulas/11-ArvoreB/arvore-b-disco/lista_clientes.c

CMakeFiles/arvore-b-disco.dir/lista_clientes.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/arvore-b-disco.dir/lista_clientes.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/vanessa/Dropbox/Documents/Disciplinas/ED/Aulas/11-ArvoreB/arvore-b-disco/lista_clientes.c > CMakeFiles/arvore-b-disco.dir/lista_clientes.c.i

CMakeFiles/arvore-b-disco.dir/lista_clientes.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/arvore-b-disco.dir/lista_clientes.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/vanessa/Dropbox/Documents/Disciplinas/ED/Aulas/11-ArvoreB/arvore-b-disco/lista_clientes.c -o CMakeFiles/arvore-b-disco.dir/lista_clientes.c.s

CMakeFiles/arvore-b-disco.dir/lista_clientes.c.o.requires:

.PHONY : CMakeFiles/arvore-b-disco.dir/lista_clientes.c.o.requires

CMakeFiles/arvore-b-disco.dir/lista_clientes.c.o.provides: CMakeFiles/arvore-b-disco.dir/lista_clientes.c.o.requires
	$(MAKE) -f CMakeFiles/arvore-b-disco.dir/build.make CMakeFiles/arvore-b-disco.dir/lista_clientes.c.o.provides.build
.PHONY : CMakeFiles/arvore-b-disco.dir/lista_clientes.c.o.provides

CMakeFiles/arvore-b-disco.dir/lista_clientes.c.o.provides.build: CMakeFiles/arvore-b-disco.dir/lista_clientes.c.o


CMakeFiles/arvore-b-disco.dir/lista_nos.c.o: CMakeFiles/arvore-b-disco.dir/flags.make
CMakeFiles/arvore-b-disco.dir/lista_nos.c.o: ../lista_nos.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/vanessa/Dropbox/Documents/Disciplinas/ED/Aulas/11-ArvoreB/arvore-b-disco/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/arvore-b-disco.dir/lista_nos.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/arvore-b-disco.dir/lista_nos.c.o   -c /Users/vanessa/Dropbox/Documents/Disciplinas/ED/Aulas/11-ArvoreB/arvore-b-disco/lista_nos.c

CMakeFiles/arvore-b-disco.dir/lista_nos.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/arvore-b-disco.dir/lista_nos.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/vanessa/Dropbox/Documents/Disciplinas/ED/Aulas/11-ArvoreB/arvore-b-disco/lista_nos.c > CMakeFiles/arvore-b-disco.dir/lista_nos.c.i

CMakeFiles/arvore-b-disco.dir/lista_nos.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/arvore-b-disco.dir/lista_nos.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/vanessa/Dropbox/Documents/Disciplinas/ED/Aulas/11-ArvoreB/arvore-b-disco/lista_nos.c -o CMakeFiles/arvore-b-disco.dir/lista_nos.c.s

CMakeFiles/arvore-b-disco.dir/lista_nos.c.o.requires:

.PHONY : CMakeFiles/arvore-b-disco.dir/lista_nos.c.o.requires

CMakeFiles/arvore-b-disco.dir/lista_nos.c.o.provides: CMakeFiles/arvore-b-disco.dir/lista_nos.c.o.requires
	$(MAKE) -f CMakeFiles/arvore-b-disco.dir/build.make CMakeFiles/arvore-b-disco.dir/lista_nos.c.o.provides.build
.PHONY : CMakeFiles/arvore-b-disco.dir/lista_nos.c.o.provides

CMakeFiles/arvore-b-disco.dir/lista_nos.c.o.provides.build: CMakeFiles/arvore-b-disco.dir/lista_nos.c.o


CMakeFiles/arvore-b-disco.dir/metadados.c.o: CMakeFiles/arvore-b-disco.dir/flags.make
CMakeFiles/arvore-b-disco.dir/metadados.c.o: ../metadados.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/vanessa/Dropbox/Documents/Disciplinas/ED/Aulas/11-ArvoreB/arvore-b-disco/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/arvore-b-disco.dir/metadados.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/arvore-b-disco.dir/metadados.c.o   -c /Users/vanessa/Dropbox/Documents/Disciplinas/ED/Aulas/11-ArvoreB/arvore-b-disco/metadados.c

CMakeFiles/arvore-b-disco.dir/metadados.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/arvore-b-disco.dir/metadados.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/vanessa/Dropbox/Documents/Disciplinas/ED/Aulas/11-ArvoreB/arvore-b-disco/metadados.c > CMakeFiles/arvore-b-disco.dir/metadados.c.i

CMakeFiles/arvore-b-disco.dir/metadados.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/arvore-b-disco.dir/metadados.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/vanessa/Dropbox/Documents/Disciplinas/ED/Aulas/11-ArvoreB/arvore-b-disco/metadados.c -o CMakeFiles/arvore-b-disco.dir/metadados.c.s

CMakeFiles/arvore-b-disco.dir/metadados.c.o.requires:

.PHONY : CMakeFiles/arvore-b-disco.dir/metadados.c.o.requires

CMakeFiles/arvore-b-disco.dir/metadados.c.o.provides: CMakeFiles/arvore-b-disco.dir/metadados.c.o.requires
	$(MAKE) -f CMakeFiles/arvore-b-disco.dir/build.make CMakeFiles/arvore-b-disco.dir/metadados.c.o.provides.build
.PHONY : CMakeFiles/arvore-b-disco.dir/metadados.c.o.provides

CMakeFiles/arvore-b-disco.dir/metadados.c.o.provides.build: CMakeFiles/arvore-b-disco.dir/metadados.c.o


CMakeFiles/arvore-b-disco.dir/no.c.o: CMakeFiles/arvore-b-disco.dir/flags.make
CMakeFiles/arvore-b-disco.dir/no.c.o: ../no.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/vanessa/Dropbox/Documents/Disciplinas/ED/Aulas/11-ArvoreB/arvore-b-disco/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/arvore-b-disco.dir/no.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/arvore-b-disco.dir/no.c.o   -c /Users/vanessa/Dropbox/Documents/Disciplinas/ED/Aulas/11-ArvoreB/arvore-b-disco/no.c

CMakeFiles/arvore-b-disco.dir/no.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/arvore-b-disco.dir/no.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/vanessa/Dropbox/Documents/Disciplinas/ED/Aulas/11-ArvoreB/arvore-b-disco/no.c > CMakeFiles/arvore-b-disco.dir/no.c.i

CMakeFiles/arvore-b-disco.dir/no.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/arvore-b-disco.dir/no.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/vanessa/Dropbox/Documents/Disciplinas/ED/Aulas/11-ArvoreB/arvore-b-disco/no.c -o CMakeFiles/arvore-b-disco.dir/no.c.s

CMakeFiles/arvore-b-disco.dir/no.c.o.requires:

.PHONY : CMakeFiles/arvore-b-disco.dir/no.c.o.requires

CMakeFiles/arvore-b-disco.dir/no.c.o.provides: CMakeFiles/arvore-b-disco.dir/no.c.o.requires
	$(MAKE) -f CMakeFiles/arvore-b-disco.dir/build.make CMakeFiles/arvore-b-disco.dir/no.c.o.provides.build
.PHONY : CMakeFiles/arvore-b-disco.dir/no.c.o.provides

CMakeFiles/arvore-b-disco.dir/no.c.o.provides.build: CMakeFiles/arvore-b-disco.dir/no.c.o


CMakeFiles/arvore-b-disco.dir/test_arvore_b.c.o: CMakeFiles/arvore-b-disco.dir/flags.make
CMakeFiles/arvore-b-disco.dir/test_arvore_b.c.o: ../test_arvore_b.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/vanessa/Dropbox/Documents/Disciplinas/ED/Aulas/11-ArvoreB/arvore-b-disco/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/arvore-b-disco.dir/test_arvore_b.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/arvore-b-disco.dir/test_arvore_b.c.o   -c /Users/vanessa/Dropbox/Documents/Disciplinas/ED/Aulas/11-ArvoreB/arvore-b-disco/test_arvore_b.c

CMakeFiles/arvore-b-disco.dir/test_arvore_b.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/arvore-b-disco.dir/test_arvore_b.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/vanessa/Dropbox/Documents/Disciplinas/ED/Aulas/11-ArvoreB/arvore-b-disco/test_arvore_b.c > CMakeFiles/arvore-b-disco.dir/test_arvore_b.c.i

CMakeFiles/arvore-b-disco.dir/test_arvore_b.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/arvore-b-disco.dir/test_arvore_b.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/vanessa/Dropbox/Documents/Disciplinas/ED/Aulas/11-ArvoreB/arvore-b-disco/test_arvore_b.c -o CMakeFiles/arvore-b-disco.dir/test_arvore_b.c.s

CMakeFiles/arvore-b-disco.dir/test_arvore_b.c.o.requires:

.PHONY : CMakeFiles/arvore-b-disco.dir/test_arvore_b.c.o.requires

CMakeFiles/arvore-b-disco.dir/test_arvore_b.c.o.provides: CMakeFiles/arvore-b-disco.dir/test_arvore_b.c.o.requires
	$(MAKE) -f CMakeFiles/arvore-b-disco.dir/build.make CMakeFiles/arvore-b-disco.dir/test_arvore_b.c.o.provides.build
.PHONY : CMakeFiles/arvore-b-disco.dir/test_arvore_b.c.o.provides

CMakeFiles/arvore-b-disco.dir/test_arvore_b.c.o.provides.build: CMakeFiles/arvore-b-disco.dir/test_arvore_b.c.o


# Object files for target arvore-b-disco
arvore__b__disco_OBJECTS = \
"CMakeFiles/arvore-b-disco.dir/arvore_b.c.o" \
"CMakeFiles/arvore-b-disco.dir/cliente.c.o" \
"CMakeFiles/arvore-b-disco.dir/lista_clientes.c.o" \
"CMakeFiles/arvore-b-disco.dir/lista_nos.c.o" \
"CMakeFiles/arvore-b-disco.dir/metadados.c.o" \
"CMakeFiles/arvore-b-disco.dir/no.c.o" \
"CMakeFiles/arvore-b-disco.dir/test_arvore_b.c.o"

# External object files for target arvore-b-disco
arvore__b__disco_EXTERNAL_OBJECTS =

arvore-b-disco: CMakeFiles/arvore-b-disco.dir/arvore_b.c.o
arvore-b-disco: CMakeFiles/arvore-b-disco.dir/cliente.c.o
arvore-b-disco: CMakeFiles/arvore-b-disco.dir/lista_clientes.c.o
arvore-b-disco: CMakeFiles/arvore-b-disco.dir/lista_nos.c.o
arvore-b-disco: CMakeFiles/arvore-b-disco.dir/metadados.c.o
arvore-b-disco: CMakeFiles/arvore-b-disco.dir/no.c.o
arvore-b-disco: CMakeFiles/arvore-b-disco.dir/test_arvore_b.c.o
arvore-b-disco: CMakeFiles/arvore-b-disco.dir/build.make
arvore-b-disco: CMakeFiles/arvore-b-disco.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/vanessa/Dropbox/Documents/Disciplinas/ED/Aulas/11-ArvoreB/arvore-b-disco/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking C executable arvore-b-disco"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/arvore-b-disco.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/arvore-b-disco.dir/build: arvore-b-disco

.PHONY : CMakeFiles/arvore-b-disco.dir/build

CMakeFiles/arvore-b-disco.dir/requires: CMakeFiles/arvore-b-disco.dir/arvore_b.c.o.requires
CMakeFiles/arvore-b-disco.dir/requires: CMakeFiles/arvore-b-disco.dir/cliente.c.o.requires
CMakeFiles/arvore-b-disco.dir/requires: CMakeFiles/arvore-b-disco.dir/lista_clientes.c.o.requires
CMakeFiles/arvore-b-disco.dir/requires: CMakeFiles/arvore-b-disco.dir/lista_nos.c.o.requires
CMakeFiles/arvore-b-disco.dir/requires: CMakeFiles/arvore-b-disco.dir/metadados.c.o.requires
CMakeFiles/arvore-b-disco.dir/requires: CMakeFiles/arvore-b-disco.dir/no.c.o.requires
CMakeFiles/arvore-b-disco.dir/requires: CMakeFiles/arvore-b-disco.dir/test_arvore_b.c.o.requires

.PHONY : CMakeFiles/arvore-b-disco.dir/requires

CMakeFiles/arvore-b-disco.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/arvore-b-disco.dir/cmake_clean.cmake
.PHONY : CMakeFiles/arvore-b-disco.dir/clean

CMakeFiles/arvore-b-disco.dir/depend:
	cd /Users/vanessa/Dropbox/Documents/Disciplinas/ED/Aulas/11-ArvoreB/arvore-b-disco/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/vanessa/Dropbox/Documents/Disciplinas/ED/Aulas/11-ArvoreB/arvore-b-disco /Users/vanessa/Dropbox/Documents/Disciplinas/ED/Aulas/11-ArvoreB/arvore-b-disco /Users/vanessa/Dropbox/Documents/Disciplinas/ED/Aulas/11-ArvoreB/arvore-b-disco/cmake-build-debug /Users/vanessa/Dropbox/Documents/Disciplinas/ED/Aulas/11-ArvoreB/arvore-b-disco/cmake-build-debug /Users/vanessa/Dropbox/Documents/Disciplinas/ED/Aulas/11-ArvoreB/arvore-b-disco/cmake-build-debug/CMakeFiles/arvore-b-disco.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/arvore-b-disco.dir/depend
