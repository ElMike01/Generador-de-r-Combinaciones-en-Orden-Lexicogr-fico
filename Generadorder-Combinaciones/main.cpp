#include "combinaciones.hpp"

int main() {
    int n, r;

    // Validar la entrada del usuario
    if (!validarEntrada(n, r)) {
        return 1; // Salir si la entrada no es válida
    }

    // Generar combinaciones y obtener la ruta del archivo
    if (const std::string rutaArchivo = generarCombinaciones(n, r); !rutaArchivo.empty()) {
        std::cout << "Las combinaciones se han guardado en: " << rutaArchivo << std::endl;
    }

    return 0;
}