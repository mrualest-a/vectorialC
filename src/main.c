#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/densidades.h"
#include "../include/integracion.h"

// Funciones auxiliares para llamar a las densidades con parametros fijos
double usar_constante(double x, double y, double z) {
    return densidad_constante(x, y, z);
}

double usar_lineal(double x, double y, double z) {
    // Usamos a=1, b=1, c=1 para la densidad lineal
    return densidad_lineal(x, y, z, 1.0, 1.0, 1.0);
}

double usar_gaussiana(double x, double y, double z) {
    return densidad_gaussiana(x, y, z);
}

int main() {
    printf("========================================\n");
    printf("  CALCULO DE MASA Y CENTRO DE MASA\n");
    printf("========================================\n\n");
    
    // Pedir limites de integracion al usuario
    Limites lim;
    printf("Ingrese los limites de integracion:\n");
    printf("xmin: ");
    scanf("%lf", &lim.xmin);
    printf("xmax: ");
    scanf("%lf", &lim.xmax);
    printf("ymin: ");
    scanf("%lf", &lim.ymin);
    printf("ymax: ");
    scanf("%lf", &lim.ymax);
    printf("zmin: ");
    scanf("%lf", &lim.zmin);
    printf("zmax: ");
    scanf("%lf", &lim.zmax);
    
    // Pedir tipo de densidad
    int tipo_densidad;
    printf("\nSeleccione el tipo de densidad:\n");
    printf("1. Constante (rho = 1)\n");
    printf("2. Lineal (rho = x + y + z)\n");
    printf("3. Gaussiana (rho = e^(-(x^2 + y^2 + z^2)))\n");
    printf("Opcion: ");
    scanf("%d", &tipo_densidad);
    
    // Seleccionar la funcion de densidad correspondiente
    FuncionDensidad funcion_densidad;
    const char* nombre_densidad;
    
    if (tipo_densidad == 1) {
        funcion_densidad = usar_constante;
        nombre_densidad = "Constante";
    } else if (tipo_densidad == 2) {
        funcion_densidad = usar_lineal;
        nombre_densidad = "Lineal";
    } else if (tipo_densidad == 3) {
        funcion_densidad = usar_gaussiana;
        nombre_densidad = "Gaussiana";
    } else {
        printf("Opcion invalida.\n");
        return 1;
    }
    
    // Pedir numero de muestras para Monte Carlo
    int n_muestras;
    printf("\nIngrese el numero de muestras para Monte Carlo: ");
    scanf("%d", &n_muestras);
    
    if (n_muestras <= 0) {
        printf("El numero de muestras debe ser mayor que cero.\n");
        return 1;
    }
    
    // Inicializar semilla aleatoria
    srand(time(NULL));
    
    // Medir tiempo de ejecucion
    clock_t inicio = clock();
    
    // Calcular masa y centro de masa
    ResultadoCentroMasa resultado = calcular_centro_masa(funcion_densidad, lim, n_muestras);
    
    clock_t fin = clock();
    double tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;
    
    // Mostrar resultados en pantalla
    printf("\n========================================\n");
    printf("RESULTADOS:\n");
    printf("========================================\n");
    printf("Metodo: MonteCarlo\n");
    printf("Densidad: %s\n", nombre_densidad);
    printf("Muestras: %d\n", n_muestras);
    printf("\nMasa total (M): %.6f\n", resultado.masa);
    printf("Centro de masa:\n");
    printf("  x_bar: %.6f\n", resultado.x_bar);
    printf("  y_bar: %.6f\n", resultado.y_bar);
    printf("  z_bar: %.6f\n", resultado.z_bar);
    printf("\nTiempo de ejecucion: %.6f segundos\n", tiempo);
    printf("========================================\n");
    
    // Guardar resultados en archivo CSV
    FILE *archivo = fopen("resultados.csv", "a");
    if (archivo == NULL) {
        printf("\nError al abrir el archivo de resultados.\n");
        return 1;
    }
    
    // Si el archivo esta vacio, escribir encabezados
    fseek(archivo, 0, SEEK_END);
    if (ftell(archivo) == 0) {
        fprintf(archivo, "Metodo,Densidad,Nx,Ny,Nz,M,x_bar,y_bar,z_bar,Tiempo\n");
    }
    
    // Escribir los datos (Nx=n_muestras, Ny=0, Nz=0 para Monte Carlo)
    fprintf(archivo, "MonteCarlo,%s,%d,0,0,%.6f,%.6f,%.6f,%.6f,%.6f\n",
            nombre_densidad, n_muestras,
            resultado.masa, resultado.x_bar, resultado.y_bar, resultado.z_bar, tiempo);
    
    fclose(archivo);
    
    printf("\nResultados guardados en resultados.csv\n");
    
    return 0;
}
