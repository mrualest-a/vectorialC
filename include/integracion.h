#ifndef INTEGRACION_H
#define INTEGRACION_H

// Tipo de funcion que representa una densidad
typedef double (*FuncionDensidad)(double, double, double);

// Estructura para guardar los limites de integracion
typedef struct {
    double xmin, xmax;
    double ymin, ymax;
    double zmin, zmax;
} Limites;

// Estructura para guardar el resultado: masa y centro de masa
typedef struct {
    double masa;
    double x_bar;
    double y_bar;
    double z_bar;
} ResultadoCentroMasa;

// Funcion que calcula masa y centro de masa usando Monte Carlo
ResultadoCentroMasa calcular_centro_masa(FuncionDensidad f, Limites lim, int n_muestras);

#endif
