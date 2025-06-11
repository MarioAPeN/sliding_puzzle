#include<stdio.h>
#include<stdlib.h>
#include<SDL2/SDL.h>

#include"sliding_puzzle.h"

/*

Inicia el juego: Pantalla de bienvenida.
    Selecciona el tamaño de la cuadricula

Bucle principal:
    Se genera el espacio necesario para almacenar la cuadricula del juego
        La unidad base por pieza sería
            -Coordenadas de la pieza (area de la imagen que corresponde a una sola
            pieza del rompecabezas)
            -Id de la pieza: identificador númerico de la pieza. Se utilizará para
            verificar la presencia de ciclos.

            
Según lo que he estudiado:

Para inicializar el tablero, basta con mezclar un arreglo de n valores, donde
cada valor está en el rango de 0 a n-1. Para esto, se requiere un algoritmo de
aleatorización.

Se elige el algoritmo Knuth (Fisher-Yates) por su facilidad de implementación:

-- To shuffle an array a of n elements (indices 0..n-1):
for i from n−1 down to 1 do
     j ← random integer such that 0 ≤ j ≤ i
     exchange a[j] and a[i]

Según el articulo en Wikipedia, este puede inducir un sesgo por módulo si la
semilla del generador de números aleatorios no es divisible entre n. Para la 
presente aplicación no es necesario preocuparse por este sesgo (digo, es un
juego), pero para la implementación del algoritmo se planea incluir alguna
solución con tal de hacer que el código sea re-utilizable
*/

int main(void)
{
    printf("Hello world!\n");
    return 0;
}