Abrir un terminal en esta carpeta e introducir las siguientes sentencias:
mkdir build
cd build
cmake ..
make
cd ..

A continuación se copia el fichero SistemaMonetario.txt en la carpeta build:
cp SistemaMonetario.txt build/

Por último, se ejecuta desde la carpeta build el ejecutable:
cd build
./a.out
