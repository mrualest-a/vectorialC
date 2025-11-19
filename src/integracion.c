#include <stdlib.h>
#include "../include/integracion.h"

// Calcula masa y centro de masa usando el metodo de Monte Carlo
// Genera puntos aleatorios dentro de la region y calcula el promedio
ResultadoCentroMasa calcular_centro_masa(FuncionDensidad f, Limites lim, int n_muestras) {
    ResultadoCentroMasa resultado;
    
    // Calcular el volumen de la region
    double volumen = (lim.xmax - lim.xmin) * 
                     (lim.ymax - lim.ymin) * 
                     (lim.zmax - lim.zmin);
    
    // Variables para acumular las sumas
    double suma_densidad = 0.0;
    double suma_x_densidad = 0.0;
    double suma_y_densidad = 0.0;
    double suma_z_densidad = 0.0;
    
    // Generar puntos aleatorios y evaluar la funcion
    for (int i = 0; i < n_muestras; i++) {
        // Generar punto aleatorio dentro de los limites
        double x = lim.xmin + ((double)rand() / RAND_MAX) * (lim.xmax - lim.xmin);
        double y = lim.ymin + ((double)rand() / RAND_MAX) * (lim.ymax - lim.ymin);
        double z = lim.zmin + ((double)rand() / RAND_MAX) * (lim.zmax - lim.zmin);
        
        // Evaluar la densidad en ese punto
        double densidad = f(x, y, z);
        
        // Acumular para calcular masa y momentos
        suma_densidad += densidad;
        suma_x_densidad += x * densidad;
        suma_y_densidad += y * densidad;
        suma_z_densidad += z * densidad;
    }
    
    // Calcular masa total usando Monte Carlo: V * promedio
    double masa = volumen * (suma_densidad / n_muestras);
    
    // Calcular momentos
    double momento_x = volumen * (suma_x_densidad / n_muestras);
    double momento_y = volumen * (suma_y_densidad / n_muestras);
    double momento_z = volumen * (suma_z_densidad / n_muestras);
    
    // Guardar resultados
    resultado.masa = masa;
    resultado.x_bar = momento_x / masa;
    resultado.y_bar = momento_y / masa;
    resultado.z_bar = momento_z / masa;
    
    return resultado;
}
