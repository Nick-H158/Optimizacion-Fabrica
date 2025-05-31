#ifndef FUNCIONES_H
#define FUNCIONES_H

#define MAX_PRODUCTOS 5
#define MAX_NOMBRE 50

extern char nombres[MAX_PRODUCTOS][MAX_NOMBRE];
extern int tiempos[MAX_PRODUCTOS];
extern int recursos[MAX_PRODUCTOS];
extern int cantidades[MAX_PRODUCTOS];
extern int num_productos;

void agregarProducto();
void editarProducto();
void eliminarProducto();
void mostrarProductos();
void calcularTotales(int* totalTiempo, int* totalRecursos);
void verificarViabilidad(int tiempoDisponible, int recursosDisponibles);
int buscarProducto(char nombre[]);

#endif