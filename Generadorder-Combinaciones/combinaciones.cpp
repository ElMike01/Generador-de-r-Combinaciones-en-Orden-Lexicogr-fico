//
// Created by joans on 12/04/2025.
//

#include "combinaciones.hpp"

// Función para calcular el coeficiente binomial C(n,r)
unsigned long long calcularCoeficienteBinomial(const int n, int r) {
    if (r > n - r) {
        r = n - r; // Optimización: C(n,r) = C(n,n-r)
    }

    unsigned long long resultado = 1;
    for (int i = 1; i <= r; ++i) {
        resultado *= (n - (i - 1));
        resultado /= i;
    }

    return resultado;
}

// Función para validar la entrada del usuario
bool validarEntrada(int& n, int& r) {
    std::cout << "Ingrese el valor de n (tamano del conjunto base): ";
    if (!(std::cin >> n) || n < 1) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Error: n debe ser un numero entero mayor o igual a 1." << std::endl;
        return false;
    }

    std::cout << "Ingrese el valor de r (tamano de las combinaciones): ";
    if (!(std::cin >> r) || r < 0 || r > n) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Error: r debe ser un numero entero no negativo y no puede ser mayor que n." << std::endl;
        return false;
    }

    return true;
}

// Función recursiva para generar todas las r-combinaciones
void generarCombinacionesRecursivo(std::ofstream& archivo, std::vector<int>& combinacion,
                                  const int start, const int n, const int r, const int index, unsigned long long& contador) {
    // Si hemos completado una r-combinación
    if (index == r) {
        // Escribir la combinación al archivo
        for (int i = 0; i < r; ++i) {
            archivo << combinacion[i];
            if (i < r - 1) {
                archivo << ",";
            }
        }
        archivo << std::endl;

        // Incrementar el contador
        contador++;
        return;
    }

    // Generar las combinaciones recursivamente
    for (int i = start; i <= n; ++i) {
        combinacion[index] = i;
        generarCombinacionesRecursivo(archivo, combinacion, i + 1, n, r, index + 1, contador);
    }
}

// Func ión para generar combinaciones y guardarlas en un archivo CSV
std::string generarCombinaciones(const int n, const int r) {
    const std::string nombreArchivo = "combinaciones.csv";
    std::ofstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo para escribir." << std::endl;
        return "";
    }

    std::vector<int> combinacion(r);
    unsigned long long contador = 0;

    generarCombinacionesRecursivo(archivo, combinacion, 1, n, r, 0, contador);
    archivo.close();

    std::cout << "Se generaron " << contador << " combinaciones y se guardaron en " << nombreArchivo << std::endl;
    return std::filesystem::absolute(nombreArchivo).string();
}