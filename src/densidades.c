#include <math.h>
#include "../include/densidades.h"

// Densidad constante = 1
// Se usa para cuerpos homogeneos, como un bloque de metal uniforme
double densidad_constante(double x, double y, double z) {
    return 1.0;
}

// Densidad lineal: ax + by + cz
// Se usa cuando la densidad varia linealmente, por ejemplo en estructuras con gradiente de temperatura
double densidad_lineal(double x, double y, double z, double a, double b, double c) {
    return a * x + b * y + c * z;
}

// Densidad gaussiana: e^(-(x^2 + y^2 + z^2))
// Se usa para modelar distribuciones que decaen desde el origen, como nubes de gas
double densidad_gaussiana(double x, double y, double z) {
    return exp(-(x*x + y*y + z*z));
}
