#!/bin/bash
mkdir ejecutable
cp graf/*.png ejecutable/
cp graf/*.bmp ejecutable/
cp graf/escenarios/*.png ejecutable/
cp graf/tiles/*.png ejecutable/
cp auxiliares/* ejecutable/
if (c++ fuente/*.cpp -o ejecutable/itanq -g `sdl-config --cflags --libs` -lSDL_image  -DDEB) then
	echo "[Compilado correctamente, pulse intro para ejecutar]"
	read a
	cd ejecutable
	./itanq
fi
