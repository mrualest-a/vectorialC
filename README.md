Cálculo de masa y centro de masa usando integración triple

Este proyecto es para la materia de Cálculo Vectorial. La idea es calcular la masa total y el centro de masa de un cuerpo en 3D cuando la densidad no es necesariamente constante. Como resolver la integral triple a mano es complicado, aquí se usa un método numérico (en este caso Monte Carlo) para aproximar el resultado.

¿Qué hace el programa?

El programa le pide al usuario los límites de la región rectangular (xmin, xmax, etc.), el tipo de densidad que quiere usar y cuántas muestras quiere generar. Después calcula:

La masa total

El centro de masa (x̄, ȳ, z̄)

El tiempo que tardó el cálculo

Y guarda todo en un archivo CSV.

¿Cómo está organizado?

El proyecto está dividido así:

src/main.c: Aquí está el programa principal.

src/integracion.c: Implementación del método de Monte Carlo.

src/densidades.c: Las funciones de densidad.

include/*.h: Los encabezados.

Makefile: Para compilar todo más fácil.

La idea era que el proyecto fuera modular, así que cada parte tiene su archivo.

Densidades incluidas

Se implementaron tres modelos de densidad:

Constante (ρ = 1):
Como un material completamente homogéneo.

Lineal (ρ = a·x + b·y + c·z):
Útil cuando la densidad cambia según la posición.

Gaussiana (ρ = e^{-(x² + y² + z²)}):
Normal en fenómenos donde la densidad se concentra más en el centro.

Cada función está comentada dentro del código.

¿Cómo se usa?

Compilar el proyecto con el Makefile:
make

Ejecutar el programa:
./triple_integral

Ingresar:

Los límites de integración

El tipo de densidad

El método (aquí se usa Monte Carlo)

El número de muestras

El programa crea un archivo llamado resultados.csv con los valores calculados.

Sobre Monte Carlo

El método básicamente genera puntos aleatorios dentro de la región y calcula un promedio. Entre más puntos uses, más se acerca al valor real (pero también tarda más).

Notas

Para probar el programa, una buena opción es usar la densidad constante en un cubo 1×1×1.
Debería dar una masa cerca de 1 y un centro de masa cercano a (0.5, 0.5, 0.5).

Los resultados pueden variar un poco en cada ejecución porque se usan números aleatorios.