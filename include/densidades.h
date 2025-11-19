#ifndef DENSIDADES_H
#define DENSIDADES_H

// Densidad constante igual a 1
double densidad_constante(double x, double y, double z);

// Densidad lineal: ax + by + cz
double densidad_lineal(double x, double y, double z, double a, double b, double c);

// Densidad gaussiana: e^(-(x^2 + y^2 + z^2))
double densidad_gaussiana(double x, double y, double z);

#endif
