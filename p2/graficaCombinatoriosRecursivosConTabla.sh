#!/bin/bash

#	File: 	graficaCombinatoriosRecursivosConTabla.sh
#	Author:	Adrián López Ortiz
#	From:	Algorítmica. Práctica 2


cat << _end_ | gnuplot
set terminal postscript eps color
set output "combinatoriosRecursivosConTabla.eps"
set key right bottom
set xlabel "Eje X"
set ylabel "Eje Y"
plot 'combinatoriosRecursivosConTabla.txt' using 1:2 t "Tiempo real" w l,'combinatoriosRecursivosConTabla.txt' using 1:3 t "Tiempo estimado" w l
_end_
