/*
Integrantes: Camila Torres, 
Fecha de entrega: 15/11/2026
Descripción del programa: Una fábrica de componentes electrónicos necesita optimizar 
su producción para cumplir con la demanda de cinco productos distintos.
Cada producto tiene un tiempo de fabricación específico y requiere una cantidad fija de recursos.
El equipo de ingeniería ha identificado que la línea de producción tiene limitaciones de tiempo 
y recursos que deben ser tomadas en cuenta.
*/

#include <stdio.h>
#include<funciones.h>

int main (int argc, char *argv[]) {

    char nombres[5][20] = {{'-'}, {'-'}, {'-'}, {'-'}, {'-'}};
    float tiempoFabricacion[5] = {0.0}, tiempoTotal = 0;
    int recursosUnidad[5] = {0}, cantidadDemandada[5] = {0};
    int opc, respuesta, modificar = 0, encontrar = 0, calculoProduccion = 0, recursosTotales = 0;

    do
    {
        printf("Seleccione una opcion:\n");
        printf("1. Registrar productos\n");
        printf("2. Mostrar productos\n");
        printf("3. Editar producto\n");
        printf("4. Eliminar producto\n");
        printf("5. Calcular produccion\n");
        printf("6. Verificar la capacidad de produccion\n");
        printf("7. Salir del programa\n");
        printf(">>");
        opc = validarRangoFloat(1,7);

        switch (opc)
        {
        case 1:
            registrarProducto(nombres, tiempoFabricacion, recursosUnidad, cantidadDemandada);

            break;
        case 2:
            mostrarProductos(nombres, tiempoFabricacion, recursosUnidad, cantidadDemandada);

            break;
        case 3:

            buscarProducto(nombres, &modificar, &encontrar);

            if (encontrar == 1){
                editarProducto(nombres, tiempoFabricacion, recursosUnidad, cantidadDemandada, modificar);
            }
            else{
                printf("No se puede modificar un producto que no existe\n");
            }

            break;
        case 4:
            buscarProducto(nombres, &modificar, &encontrar);

            if (encontrar == 1){
                eliminarProducto(nombres, tiempoFabricacion, recursosUnidad, cantidadDemandada, modificar); 
            }
            else{
                printf("No se puede eliminar un producto que no existe\n");
            }

            break;
        case 5:
            calcularProduccion(nombres, tiempoFabricacion, recursosUnidad, cantidadDemandada, &tiempoTotal, &recursosTotales, &calculoProduccion);

            break;
        case 6:
            if (calculoProduccion == 1){
                verificarCapacidadProduccion(tiempoTotal, recursosTotales);
            }
            else{
                printf("No se puede verificar la capacidad de produccion sin antes calcular la produccion\n");
            }

            break;

        default:
            printf("========================================\n");
            printf("GRACIAS POR UTILIZAR ESTE PROGRAMA\n");
            printf("========================================\n");

            break;
        }
        
        if (opc == 7){
            respuesta = 2;
        }
        else{
            printf("¿Desea seleccionar otra opcion?: (1.si / 2.no)\n");
            respuesta = validarRangoFloat(1,2);
        }

    } while (respuesta == 1);
    

    return 0;
}
