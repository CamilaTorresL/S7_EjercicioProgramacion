/*
Integrantes: Camila Torres, 
Fecha de entrega: 15/11/2026
*/

#include <stdio.h>
#include "funciones.h"
#include <string.h>

int main (int argc, char *argv[]) {

    char nombresInsumos[5][40] = {"-", "-", "-", "-", "-"}, unidadMedida[5][20] = {"-", "-", "-", "-", "-"}, proveedor[5][40] = {"-", "-", "-", "-", "-"};
    char caducidad[5][20] = {{0}}, tratamientos[5][40] = {"-", "-", "-", "-", "-"}, insumosTratamientos[5][5][40], tipoPresentacion[5][20] = {{0}};
    float stockMinimo[5] = {0}, cantidadInsumo[5] = {0}, cantidadesTratamientos[5][5] = {0};
    int opc, modificar = 0, encontrar = 0, modalidadesTratamientos[5][5] = {0}, cantidadInsumosTratamiento[5] = {0};
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            strcpy(insumosTratamientos[i][j], "-");
        }
    }

    printf("==================================================================\n");
    printf("                 CLINICA ODONTOLOGICA                             \n");
    printf("Sistema de Gestion de Inventario y Planificacion de Insumos\n");
    printf("==================================================================\n");

    do {
        printf("Seleccione una opcion:\n");
        printf("1. Gestion de inventario\n");
        printf("2. Gestion de tratamientos y recetas\n");
        printf("3. Calcular capacidad para realizar tratamientos\n");
        printf("4. Salir del programa\n");
        printf(">> ");
        opc = validarRangoIntMaxMin(1, 4);

        switch (opc){
        case 1:
            administrarInventario(&encontrar, &modificar, nombresInsumos, unidadMedida, proveedor, stockMinimo, tipoPresentacion, cantidadInsumo, caducidad, insumosTratamientos);
            break;

        case 2:
            gestionTratamientos(tratamientos, nombresInsumos, unidadMedida, stockMinimo, insumosTratamientos, cantidadesTratamientos, modalidadesTratamientos, cantidadInsumosTratamiento);
            break;

        case 3:
            capacidadTratamientos(tratamientos, nombresInsumos, unidadMedida, stockMinimo, tipoPresentacion, cantidadInsumo, caducidad, insumosTratamientos, cantidadesTratamientos, modalidadesTratamientos, cantidadInsumosTratamiento);
            break;

        case 4:
            printf("========================================\n");
            printf("GRACIAS POR UTILIZAR ESTE PROGRAMA\n");
            printf("========================================\n");
            break;
        }
        
    } while (opc != 4);

    return 0;
}