#include <stdio.h>
#include <string.h>
#include "funciones.h"

char nombres[MAX_PRODUCTOS][MAX_NOMBRE];
int tiempos[MAX_PRODUCTOS];
int recursos[MAX_PRODUCTOS];
int cantidades[MAX_PRODUCTOS];
int num_productos = 0;

void agregarProducto() {
    if (num_productos >= MAX_PRODUCTOS) {
        printf("Límite de productos alcanzado.\n");
        return;
    }

    printf("Nombre del producto: ");
    fgets(nombres[num_productos], MAX_NOMBRE, stdin);
    nombres[num_productos][strcspn(nombres[num_productos], "\n")] = '\0';

    printf("Tiempo de fabricación por unidad: ");
    scanf("%d", &tiempos[num_productos]);

    printf("Recursos necesarios por unidad: ");
    scanf("%d", &recursos[num_productos]);

    printf("Cantidad demandada: ");
    scanf("%d", &cantidades[num_productos]);
    getchar();

    num_productos++;
}

int buscarProducto(char nombre[]) {
    for (int i = 0; i < num_productos; i++) {
        if (strcmp(nombres[i], nombre) == 0) {
            return i;
        }
    }
    return -1;
}

void editarProducto() {
    char nombre[MAX_NOMBRE];
    printf("Ingrese el nombre del producto a editar: ");
    fgets(nombre, MAX_NOMBRE, stdin);
    nombre[strcspn(nombre, "\n")] = '\0';

    int pos = buscarProducto(nombre);
    if (pos == -1) {
        printf("Producto no encontrado.\n");
        return;
    }

    printf("Nuevo nombre: ");
    fgets(nombres[pos], MAX_NOMBRE, stdin);
    nombres[pos][strcspn(nombres[pos], "\n")] = '\0';

    printf("Nuevo tiempo de fabricación: ");
    scanf("%d", &tiempos[pos]);

    printf("Nuevos recursos por unidad: ");
    scanf("%d", &recursos[pos]);

    printf("Nueva cantidad demandada: ");
    scanf("%d", &cantidades[pos]);
    getchar();
}

void eliminarProducto() {
    char nombre[MAX_NOMBRE];
    printf("Ingrese el nombre del producto a eliminar: ");
    fgets(nombre, MAX_NOMBRE, stdin);
    nombre[strcspn(nombre, "\n")] = '\0';

    int pos = buscarProducto(nombre);
    if (pos == -1) {
        printf("Producto no encontrado.\n");
        return;
    }

    for (int i = pos; i < num_productos - 1; i++) {
        strcpy(nombres[i], nombres[i + 1]);
        tiempos[i] = tiempos[i + 1];
        recursos[i] = recursos[i + 1];
        cantidades[i] = cantidades[i + 1];
    }

    num_productos--;
    printf("Producto eliminado.\n");
}

void mostrarProductos() {
    printf("\nProductos ingresados:\n");
    for (int i = 0; i < num_productos; i++) {
        printf("Producto %d: %s, Tiempo: %d, Recursos: %d, Cantidad: %d\n",
               i + 1, nombres[i], tiempos[i], recursos[i], cantidades[i]);
    }
}

void calcularTotales(int* totalTiempo, int* totalRecursos) {
    *totalTiempo = 0;
    *totalRecursos = 0;
    for (int i = 0; i < num_productos; i++) {
        *totalTiempo += tiempos[i] * cantidades[i];
        *totalRecursos += recursos[i] * cantidades[i];
    }
}

void verificarViabilidad(int tiempoDisponible, int recursosDisponibles) {
    int totalTiempo = 0, totalRecursos = 0;
    calcularTotales(&totalTiempo, &totalRecursos);

    if (totalTiempo <= tiempoDisponible && totalRecursos <= recursosDisponibles) {
        printf("¡La producción es viable!\n");
    } else {
        printf("No es posible cumplir con la demanda.\n");
        if (totalTiempo > tiempoDisponible)
            printf("Tiempo requerido excede el disponible.\n");
        if (totalRecursos > recursosDisponibles)
            printf("Recursos requeridos exceden los disponibles.\n");
    }
}