# Generador de r-Combinaciones en Orden Lexicográfico

Este programa en C++ genera todas las r-combinaciones posibles del conjunto {1, 2, ..., n} en orden lexicográfico y las guarda en un archivo CSV.

## Autor
[Joan Antonio Lazaro Silva]

## Requisitos del Sistema
- Compilador C++ que soporte C++17 o superior
- Sistema operativo: Windows, Linux o macOS

## Instrucciones de Compilación y Ejecución

### En Linux/macOS:
```bash
g++ -std=c++17 main.cpp -o combinaciones
./combinaciones
```

### En Windows (con MinGW):
```bash
g++ -std=c++17 main.cpp -o combinaciones.exe
combinaciones.exe
```

### En Windows (con MSVC):
```bash
cl /EHsc /std:c++17 main.cpp
main.exe
```

## Explicación del Algoritmo

El algoritmo implementado utiliza un enfoque recursivo para generar todas las r-combinaciones posibles del conjunto {1, 2, ..., n} en orden lexicográfico.

### Algoritmo de Generación de Combinaciones

1. **Función principal**: `generarCombinacionesRecursivo` que recibe:
   - Un vector para almacenar la combinación actual
   - Un índice de inicio
   - Los valores de n y r
   - Un índice actual
   - Un contador de combinaciones generadas

2. **Caso base**: Cuando el índice actual es igual a r, hemos completado una combinación válida. Se escribe la combinación en el archivo y se incrementa el contador.

3. **Caso recursivo**: Para cada valor desde el valor de inicio hasta n:
   - Se asigna el valor actual a la posición del índice en la combinación
   - Se llama recursivamente a la función con el valor de inicio incrementado y el índice incrementado
   
4. **Tratamiento de casos especiales**: Para r = 0, se genera una única combinación (conjunto vacío).

### Orden Lexicográfico

El orden lexicográfico es un ordenamiento similar al orden alfabético pero aplicado a secuencias numéricas. En el contexto de las r-combinaciones:

1. Las combinaciones se ordenan de menor a mayor considerando cada elemento de izquierda a derecha.
2. Una combinación A precede a una combinación B si el primer elemento en el que difieren, A tiene un valor menor que B.

Ejemplo para n=4, r=2:
- 1,2
- 1,3
- 1,4
- 2,3
- 2,4
- 3,4

El algoritmo garantiza este orden lexicográfico al generar las combinaciones de forma recursiva, partiendo siempre de los elementos menores y avanzando hacia los mayores.

### Cálculo del Coeficiente Binomial C(n,r)

Para calcular el número teórico de combinaciones, se implementa la función `calcularCoeficienteBinomial` que utiliza la fórmula:

C(n,r) = n! / (r! * (n-r)!)

Para evitar desbordamientos al calcular factoriales grandes, se utiliza una optimización:

```cpp
C(n,r) = (n * (n-1) * ... * (n-r+1)) / (r * (r-1) * ... * 1)
```

Además, se aplica la propiedad C(n,r) = C(n,n-r) para reducir el número de operaciones cuando r > n/2.

## Validación de Entrada

El programa implementa las siguientes validaciones para la entrada del usuario:

- `n` debe ser un entero mayor o igual a 1 (n >= 1)
- `r` debe ser un entero mayor o igual a 0 (r >= 0)
- `r` no puede ser mayor que n (r <= n)

Si la entrada no cumple con estas validaciones, se muestra un mensaje de error y se solicita al usuario que ingrese valores válidos.

## Formato de Salida

El programa genera un archivo CSV con nombre `combinaciones_n{valor_n}_r{valor_r}.csv` donde:

1. Cada línea representa una r-combinación
2. Los elementos dentro de cada combinación están separados por comas
3. Las combinaciones se ordenan lexicográficamente

Ejemplo de contenido para n=4, r=2:
```
1,2
1,3
1,4
2,3
2,4
3,4
```

## Verificación C(n,r)

El programa realiza una verificación comparando:
1. El número de combinaciones generadas por el algoritmo
2. El valor teórico calculado mediante la fórmula del coeficiente binomial C(n,r)

Al finalizar la ejecución, muestra si ambos valores coinciden, confirmando la correcta implementación del algoritmo.
