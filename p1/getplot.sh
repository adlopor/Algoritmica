#!/bin/bash

cat <<_end_ | gnuplot
set terminal postscript eps color
set output "grafico.eps"
set key right bottom
set xlabel "Time"
set ylabel "Iteration"
plot 'build/tiempos.txt' using 1:2 t "Datos columna tiempo real frente a iteraciones" w l, 'build/tiempos.txt' using 1:3 t "Datos columna tiempo estimado frente a iteraciones" w l 
_end_
