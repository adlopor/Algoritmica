# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/p42loora/tercero/primer_cuatri/algoritmica/p2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/p42loora/tercero/primer_cuatri/algoritmica/p2/build

# Include any dependencies generated for this target.
include CMakeFiles/a.out.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/a.out.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/a.out.dir/flags.make

CMakeFiles/a.out.dir/main.cpp.o: CMakeFiles/a.out.dir/flags.make
CMakeFiles/a.out.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/p42loora/tercero/primer_cuatri/algoritmica/p2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/a.out.dir/main.cpp.o"
	/usr/local/opt/gcc-5.3.0-32/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/a.out.dir/main.cpp.o -c /home/p42loora/tercero/primer_cuatri/algoritmica/p2/main.cpp

CMakeFiles/a.out.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a.out.dir/main.cpp.i"
	/usr/local/opt/gcc-5.3.0-32/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/p42loora/tercero/primer_cuatri/algoritmica/p2/main.cpp > CMakeFiles/a.out.dir/main.cpp.i

CMakeFiles/a.out.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a.out.dir/main.cpp.s"
	/usr/local/opt/gcc-5.3.0-32/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/p42loora/tercero/primer_cuatri/algoritmica/p2/main.cpp -o CMakeFiles/a.out.dir/main.cpp.s

CMakeFiles/a.out.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/a.out.dir/main.cpp.o.requires

CMakeFiles/a.out.dir/main.cpp.o.provides: CMakeFiles/a.out.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/a.out.dir/build.make CMakeFiles/a.out.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/a.out.dir/main.cpp.o.provides

CMakeFiles/a.out.dir/main.cpp.o.provides.build: CMakeFiles/a.out.dir/main.cpp.o


CMakeFiles/a.out.dir/ClaseTiempo.cpp.o: CMakeFiles/a.out.dir/flags.make
CMakeFiles/a.out.dir/ClaseTiempo.cpp.o: ../ClaseTiempo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/p42loora/tercero/primer_cuatri/algoritmica/p2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/a.out.dir/ClaseTiempo.cpp.o"
	/usr/local/opt/gcc-5.3.0-32/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/a.out.dir/ClaseTiempo.cpp.o -c /home/p42loora/tercero/primer_cuatri/algoritmica/p2/ClaseTiempo.cpp

CMakeFiles/a.out.dir/ClaseTiempo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a.out.dir/ClaseTiempo.cpp.i"
	/usr/local/opt/gcc-5.3.0-32/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/p42loora/tercero/primer_cuatri/algoritmica/p2/ClaseTiempo.cpp > CMakeFiles/a.out.dir/ClaseTiempo.cpp.i

CMakeFiles/a.out.dir/ClaseTiempo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a.out.dir/ClaseTiempo.cpp.s"
	/usr/local/opt/gcc-5.3.0-32/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/p42loora/tercero/primer_cuatri/algoritmica/p2/ClaseTiempo.cpp -o CMakeFiles/a.out.dir/ClaseTiempo.cpp.s

CMakeFiles/a.out.dir/ClaseTiempo.cpp.o.requires:

.PHONY : CMakeFiles/a.out.dir/ClaseTiempo.cpp.o.requires

CMakeFiles/a.out.dir/ClaseTiempo.cpp.o.provides: CMakeFiles/a.out.dir/ClaseTiempo.cpp.o.requires
	$(MAKE) -f CMakeFiles/a.out.dir/build.make CMakeFiles/a.out.dir/ClaseTiempo.cpp.o.provides.build
.PHONY : CMakeFiles/a.out.dir/ClaseTiempo.cpp.o.provides

CMakeFiles/a.out.dir/ClaseTiempo.cpp.o.provides.build: CMakeFiles/a.out.dir/ClaseTiempo.cpp.o


CMakeFiles/a.out.dir/funciones.cpp.o: CMakeFiles/a.out.dir/flags.make
CMakeFiles/a.out.dir/funciones.cpp.o: ../funciones.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/p42loora/tercero/primer_cuatri/algoritmica/p2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/a.out.dir/funciones.cpp.o"
	/usr/local/opt/gcc-5.3.0-32/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/a.out.dir/funciones.cpp.o -c /home/p42loora/tercero/primer_cuatri/algoritmica/p2/funciones.cpp

CMakeFiles/a.out.dir/funciones.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a.out.dir/funciones.cpp.i"
	/usr/local/opt/gcc-5.3.0-32/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/p42loora/tercero/primer_cuatri/algoritmica/p2/funciones.cpp > CMakeFiles/a.out.dir/funciones.cpp.i

CMakeFiles/a.out.dir/funciones.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a.out.dir/funciones.cpp.s"
	/usr/local/opt/gcc-5.3.0-32/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/p42loora/tercero/primer_cuatri/algoritmica/p2/funciones.cpp -o CMakeFiles/a.out.dir/funciones.cpp.s

CMakeFiles/a.out.dir/funciones.cpp.o.requires:

.PHONY : CMakeFiles/a.out.dir/funciones.cpp.o.requires

CMakeFiles/a.out.dir/funciones.cpp.o.provides: CMakeFiles/a.out.dir/funciones.cpp.o.requires
	$(MAKE) -f CMakeFiles/a.out.dir/build.make CMakeFiles/a.out.dir/funciones.cpp.o.provides.build
.PHONY : CMakeFiles/a.out.dir/funciones.cpp.o.provides

CMakeFiles/a.out.dir/funciones.cpp.o.provides.build: CMakeFiles/a.out.dir/funciones.cpp.o


CMakeFiles/a.out.dir/funcionesMinimosCuadrados.cpp.o: CMakeFiles/a.out.dir/flags.make
CMakeFiles/a.out.dir/funcionesMinimosCuadrados.cpp.o: ../funcionesMinimosCuadrados.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/p42loora/tercero/primer_cuatri/algoritmica/p2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/a.out.dir/funcionesMinimosCuadrados.cpp.o"
	/usr/local/opt/gcc-5.3.0-32/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/a.out.dir/funcionesMinimosCuadrados.cpp.o -c /home/p42loora/tercero/primer_cuatri/algoritmica/p2/funcionesMinimosCuadrados.cpp

CMakeFiles/a.out.dir/funcionesMinimosCuadrados.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a.out.dir/funcionesMinimosCuadrados.cpp.i"
	/usr/local/opt/gcc-5.3.0-32/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/p42loora/tercero/primer_cuatri/algoritmica/p2/funcionesMinimosCuadrados.cpp > CMakeFiles/a.out.dir/funcionesMinimosCuadrados.cpp.i

CMakeFiles/a.out.dir/funcionesMinimosCuadrados.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a.out.dir/funcionesMinimosCuadrados.cpp.s"
	/usr/local/opt/gcc-5.3.0-32/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/p42loora/tercero/primer_cuatri/algoritmica/p2/funcionesMinimosCuadrados.cpp -o CMakeFiles/a.out.dir/funcionesMinimosCuadrados.cpp.s

CMakeFiles/a.out.dir/funcionesMinimosCuadrados.cpp.o.requires:

.PHONY : CMakeFiles/a.out.dir/funcionesMinimosCuadrados.cpp.o.requires

CMakeFiles/a.out.dir/funcionesMinimosCuadrados.cpp.o.provides: CMakeFiles/a.out.dir/funcionesMinimosCuadrados.cpp.o.requires
	$(MAKE) -f CMakeFiles/a.out.dir/build.make CMakeFiles/a.out.dir/funcionesMinimosCuadrados.cpp.o.provides.build
.PHONY : CMakeFiles/a.out.dir/funcionesMinimosCuadrados.cpp.o.provides

CMakeFiles/a.out.dir/funcionesMinimosCuadrados.cpp.o.provides.build: CMakeFiles/a.out.dir/funcionesMinimosCuadrados.cpp.o


CMakeFiles/a.out.dir/sistemaEcuaciones.cpp.o: CMakeFiles/a.out.dir/flags.make
CMakeFiles/a.out.dir/sistemaEcuaciones.cpp.o: ../sistemaEcuaciones.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/p42loora/tercero/primer_cuatri/algoritmica/p2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/a.out.dir/sistemaEcuaciones.cpp.o"
	/usr/local/opt/gcc-5.3.0-32/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/a.out.dir/sistemaEcuaciones.cpp.o -c /home/p42loora/tercero/primer_cuatri/algoritmica/p2/sistemaEcuaciones.cpp

CMakeFiles/a.out.dir/sistemaEcuaciones.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a.out.dir/sistemaEcuaciones.cpp.i"
	/usr/local/opt/gcc-5.3.0-32/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/p42loora/tercero/primer_cuatri/algoritmica/p2/sistemaEcuaciones.cpp > CMakeFiles/a.out.dir/sistemaEcuaciones.cpp.i

CMakeFiles/a.out.dir/sistemaEcuaciones.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a.out.dir/sistemaEcuaciones.cpp.s"
	/usr/local/opt/gcc-5.3.0-32/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/p42loora/tercero/primer_cuatri/algoritmica/p2/sistemaEcuaciones.cpp -o CMakeFiles/a.out.dir/sistemaEcuaciones.cpp.s

CMakeFiles/a.out.dir/sistemaEcuaciones.cpp.o.requires:

.PHONY : CMakeFiles/a.out.dir/sistemaEcuaciones.cpp.o.requires

CMakeFiles/a.out.dir/sistemaEcuaciones.cpp.o.provides: CMakeFiles/a.out.dir/sistemaEcuaciones.cpp.o.requires
	$(MAKE) -f CMakeFiles/a.out.dir/build.make CMakeFiles/a.out.dir/sistemaEcuaciones.cpp.o.provides.build
.PHONY : CMakeFiles/a.out.dir/sistemaEcuaciones.cpp.o.provides

CMakeFiles/a.out.dir/sistemaEcuaciones.cpp.o.provides.build: CMakeFiles/a.out.dir/sistemaEcuaciones.cpp.o


# Object files for target a.out
a_out_OBJECTS = \
"CMakeFiles/a.out.dir/main.cpp.o" \
"CMakeFiles/a.out.dir/ClaseTiempo.cpp.o" \
"CMakeFiles/a.out.dir/funciones.cpp.o" \
"CMakeFiles/a.out.dir/funcionesMinimosCuadrados.cpp.o" \
"CMakeFiles/a.out.dir/sistemaEcuaciones.cpp.o"

# External object files for target a.out
a_out_EXTERNAL_OBJECTS =

a.out: CMakeFiles/a.out.dir/main.cpp.o
a.out: CMakeFiles/a.out.dir/ClaseTiempo.cpp.o
a.out: CMakeFiles/a.out.dir/funciones.cpp.o
a.out: CMakeFiles/a.out.dir/funcionesMinimosCuadrados.cpp.o
a.out: CMakeFiles/a.out.dir/sistemaEcuaciones.cpp.o
a.out: CMakeFiles/a.out.dir/build.make
a.out: CMakeFiles/a.out.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/p42loora/tercero/primer_cuatri/algoritmica/p2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable a.out"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/a.out.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/a.out.dir/build: a.out

.PHONY : CMakeFiles/a.out.dir/build

CMakeFiles/a.out.dir/requires: CMakeFiles/a.out.dir/main.cpp.o.requires
CMakeFiles/a.out.dir/requires: CMakeFiles/a.out.dir/ClaseTiempo.cpp.o.requires
CMakeFiles/a.out.dir/requires: CMakeFiles/a.out.dir/funciones.cpp.o.requires
CMakeFiles/a.out.dir/requires: CMakeFiles/a.out.dir/funcionesMinimosCuadrados.cpp.o.requires
CMakeFiles/a.out.dir/requires: CMakeFiles/a.out.dir/sistemaEcuaciones.cpp.o.requires

.PHONY : CMakeFiles/a.out.dir/requires

CMakeFiles/a.out.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/a.out.dir/cmake_clean.cmake
.PHONY : CMakeFiles/a.out.dir/clean

CMakeFiles/a.out.dir/depend:
	cd /home/p42loora/tercero/primer_cuatri/algoritmica/p2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/p42loora/tercero/primer_cuatri/algoritmica/p2 /home/p42loora/tercero/primer_cuatri/algoritmica/p2 /home/p42loora/tercero/primer_cuatri/algoritmica/p2/build /home/p42loora/tercero/primer_cuatri/algoritmica/p2/build /home/p42loora/tercero/primer_cuatri/algoritmica/p2/build/CMakeFiles/a.out.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/a.out.dir/depend

