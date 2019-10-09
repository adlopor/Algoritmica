/*	Abrir un terminal en esta carpeta e introducir las siguientes sentencias:	*/

mkdir build			//Crea una carpeta de nombre 'build'.
cd build				//Accedemos a la carpeta
cmake ..				//Hacemos 'cmake..' para generar el Makefile dentro de la carpeta 'build' a través de los datos obtenidos del archivo CMakeLists.txt que se ecuentra en la 					  carpeta principal
make					//Hacemos 'make' para que compile y linke los archivos necesarios para generar el ejecutable y genera este último.
./a.out				//Por último, ejecutamos el archivo ejecutable de la práctica.
