#include <stdio.h>
#include "funciones.h"

int main() {
    int opcion;
    int tiempoDisponible, recursosDisponibles;

    do {
        printf("\n- MENÚ -\n");
        printf("1. Agregar producto\n");
        printf("2. Editar producto\n");
        printf("3. Eliminar producto\n");
        printf("4. Mostrar productos\n");
        printf("5. Calcular tiempo y recursos necesarios\n");
        printf("6. Verificar si se puede cumplir demanda\n");
        printf("0. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);
        getchar();

        switch (opcion) {
            case 1: agregarProducto(); break;
            case 2: editarProducto(); break;
            case 3: eliminarProducto(); break;
            case 4: mostrarProductos(); break;
            case 5: {
                int totalTiempo = 0, totalRecursos = 0;
                calcularTotales(&totalTiempo, &totalRecursos);
                printf("Tiempo total requerido: %d\n", totalTiempo);
                printf("Recursos totales requeridos: %d\n", totalRecursos);
                break;
            }
            case 6:
                printf("Ingrese tiempo disponible: ");
                scanf("%d", &tiempoDisponible);
                printf("Ingrese recursos disponibles: ");
                scanf("%d", &recursosDisponibles);
                verificarViabilidad(tiempoDisponible, recursosDisponibles);
                break;
        }
    } while (opcion != 0);

    return 0;
}