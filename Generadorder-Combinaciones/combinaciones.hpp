//
// Created by joans on 12/04/2025.
//

#ifndef COMBINACIONES_HPP
#define COMBINACIONES_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <filesystem>

// Calcula el coeficiente binomial C(n, r).
// n: tamaño del conjunto base.
// r: tamaño de las combinaciones.
// Retorna el número de combinaciones posibles (C(n, r)).
unsigned long long calcularCoeficienteBinomial(int n, int r);

// Valida la entrada del usuario para los valores de n y r.
// n: referencia al tamaño del conjunto base (debe ser >= 1).
// r: referencia al tamaño de las combinaciones (debe ser >= 0 y <= n).
// Retorna true si la entrada es válida, false en caso contrario.
bool validarEntrada(int& n, int& r);

// Genera todas las r-combinaciones de un conjunto de tamaño n
// y las escribe en un archivo CSV.
// archivo: flujo de salida para escribir las combinaciones.
// combinacion: vector que almacena la combinación actual.
// start: valor inicial para la generación de combinaciones (debe ser >= 1).
// n: tamaño del conjunto base.
// r: tamaño de las combinaciones.
// index: índice actual en la combinación (debe ser < r).
// contador: referencia al contador de combinaciones generadas (se incrementa al encontrar una combinación).
void generarCombinacionesRecursivo(std::ofstream& archivo, std::vector<int>& combinacion,
                                  int start, int n, int r, int index, unsigned long long& contador);

// Genera combinaciones y las guarda en un archivo CSV.
// n: tamaño del conjunto base.
// r: tamaño de las combinaciones.
// Retorna la ruta absoluta del archivo generado.
std::string generarCombinaciones(int n, int r);

#endif // COMBINACIONES_HPP