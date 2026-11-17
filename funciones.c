#include<stdio.h>
#include<string.h>
#include<funciones.h>

float validarRangoFloat(float a, float b){

    float num;
    int val;

    do
    {
        val = scanf(" %f", &num);
        while((getchar()) != '\n');
        
        if (num < a || num > b || val != 1){
            printf("Error: el valor ingresado es incorrecto\n");
        }

    } while (num < a || num > b || val != 1);

    return num;
    
}

float validarRangoFloatMinimo(float a){

    float numMinimo;
    int val;

    do
    {
        val = scanf(" %f", &numMinimo);
        while((getchar()) != '\n');
        
        if (numMinimo < a || val != 1){
            printf("Error: el valor ingresado es incorrecto\n");
        }

    } while (numMinimo < a || val != 1);

    return numMinimo;
    
}

int validarRangoInt(int a){
    int num;
    int val, valido;
    int c;

    do
    {
        val = scanf(" %d", &num);
        valido = (val == 1);
        while((c = getchar()) != '\n' && c != EOF){
            valido = 0;
        };

        if (num < a || !valido){
            printf("Error: el valor ingresado es incorrecto\n");
        }

        if(c == EOF && !valido){
            return -1;
        }

    } while (num < a || !valido);

    return num;
}

int validarRangoIntMaxMin(int a, int b){
    int num;
    int val, valido;
    int c;

    do
    {
        val = scanf(" %d", &num);
        valido = (val == 1);
        while((c = getchar()) != '\n' && c != EOF){
            valido = 0;
        };

        if (num < a || num > b || !valido){
            printf("Error: el valor ingresado es incorrecto\n");
        }

        if(c == EOF && !valido){
            return -1;
        }

    } while (num < a || num > b || !valido);

    return num;
}

void leerCadenas(char *cadena, int n){

    if (fgets(cadena, n, stdin) != NULL) {
        
        int len = strcspn(cadena, "\n");
        
        if (cadena[len] == '\n') {
            cadena[len] = '\0';
        } else {
           
            while ((getchar()) != '\n');;
        }
    }
}

void registrarProducto(char nombres[5][20], float tiempoFabricacion[5], int recursosUnidad[5], int cantidadDemandada[5]){
    
    int resp;
    int contadorProductos = 0;
  
    do
    {
        printf("¿En que espacio desea registrar el producto? (0 - 4)\n");
        int i = validarRangoFloat(0, 4);
        int contador = 0, repetido = 0;
        char nombrePrueba[20];

        if (cantidadDemandada[i] == 0)
        {
            do
            {
                printf("Ingrese el nombre del producto numero %d:\n", i + 1);
                leerCadenas(nombrePrueba, 20);

                repetido = 0;

                for (int contador = 0; contador < 5; contador++)
                {
                    if (cantidadDemandada[contador] > 0 && strcasecmp(nombrePrueba,nombres[contador])==0){
                        printf("Ya existe un producto con el mismo nombre\n");
                        repetido = 1;
                    }
                }
            } while (repetido == 1);

            strcpy(nombres[i],nombrePrueba);
            
            
            printf("Ingrese el tiempo de fabricacion por unidad en minutos del producto numero %d:\n", i + 1);
            tiempoFabricacion[i] = validarRangoFloatMinimo(0);
            printf("Ingrese los recursos necesarios por unidad del producto numero %d:\n", i + 1);
            recursosUnidad[i] = validarRangoInt(1);
            printf("Ingrese la cantidad demandada del producto %d\n", i + 1);
            cantidadDemandada[i] = validarRangoInt(1);
            
        }
        else
        {
            printf("Error: el espacio seleccionado ya se encuentra ocupado\n");
        }
        
        contadorProductos = 0;
        
        for (int contador = 0; contador < 5; contador++)
        {
            if (cantidadDemandada[contador] > 0)
            {
                contadorProductos++;
            }
        }

        if (contadorProductos < 5){
            printf("¿Desea ingresar otro producto? (1.si / 2.no)\n");
            resp = validarRangoFloat(1,2);
        }
        else{
            printf("Se ha completado el registro de 5 productos\n");
            resp = 2;
        }

    } while (resp == 1);
}

void mostrarProductos(char nombres[5][20], float tiempoFabricacion[5], int recursosUnidad[5], int cantidadDemandada[5]){

    printf("==================================\n");
    printf("PRODUCTOS REGISTRADOS\n");
    printf("==================================\n");
    printf("\n");
    printf("%-30s %-20s %-10s %s\n", "Nombre", "Tiempo", "Recursos", "Demanda");

    for (int i = 0; i < 5; i++)
    {
        printf("%-30s %-20.2f %-10d %d\n", nombres[i], tiempoFabricacion[i], recursosUnidad[i], cantidadDemandada[i]);
    }
    
}

void buscarProducto(char nombres[5][20], int *modificar, int *encontrar){
    
    char nombreBuscar[20];

    *encontrar = 0;
    
    printf("Ingrese el nombre del producto:\n");
    leerCadenas(nombreBuscar,20);

    for (int i = 0; i < 5; i++)
    {
        if (strcasecmp(nombreBuscar,nombres[i])==0){
            *modificar = i;
            *encontrar = 1;
            break;
        }
    }

    if (*encontrar == 1){
        printf("El producto se ha encontrado correctamente\n");
    }
    else{
        printf("El producto ingresado no existe\n");
    }
}

void editarProducto(char nombres[5][20], float tiempoFabricacion[5], int recursosUnidad[5], int cantidadDemandada[5], int modificar){
    
    int opc;
    
    printf("¿Que desea modificar?\n");
    printf("1. Nombre del producto\n");
    printf("2. Tiempo de fabricacion por unidad\n");
    printf("3. Recursos necesarios por unidad\n");
    printf("4. Cantidad demandada\n");
    printf(">>");
    opc = validarRangoFloat(1,4);

    switch (opc)
    {
    case 1:
        printf("Ingrese el nombre\n");
        leerCadenas(nombres[modificar],20);
        printf("El cambio se ha realizado con exito\n");

        break;
    case 2:
        printf("Ingrese el tiempo de fabricacion por unidad en minutos\n");
        tiempoFabricacion[modificar] = validarRangoFloatMinimo(0);
        printf("El cambio se ha realizado con exito\n");

        break;
    case 3:
        printf("Ingrese la cantidad de recursos necesarios por unidad\n");
        recursosUnidad[modificar] = validarRangoInt(1);
        printf("El cambio se ha realizado con exito\n");
        
        break;
    case 4:
        printf("Ingrese la cantidad demandada\n");
        cantidadDemandada[modificar] = validarRangoInt(1);
        printf("El cambio se ha realizado con exito\n");

        break;
    }
}

void eliminarProducto(char nombres[5][20], float tiempoFabricacion[5], int recursosUnidad[5], int cantidadDemandada[5], int modificar){
    
    int resp = 0;
    
    printf("¿Esta seguro de eliminar el producto?: (1.si / 2.no)\n");
    resp = validarRangoFloat(1,2);

    if (resp == 1){
        strcpy(nombres[modificar],"-");
        tiempoFabricacion[modificar] = 0;
        recursosUnidad[modificar] = 0;
        cantidadDemandada[modificar] = 0;

        printf("El producto se elimino correctamente\n");
    }
    else{
        printf("Se cancelo la eliminacion del producto\n");
    }
}

void calcularProduccion(char nombres[5][20], float tiempoFabricacion[5], int recursosUnidad[5], int cantidadDemandada[5], float *tiempoTotal, int *recursosTotales, int *calculoProduccion){

    *tiempoTotal = 0;
    *recursosTotales = 0;
    *calculoProduccion = 0;

    printf("%-30s %-15s %s\n", "Producto", "Tiempo", "Recursos");

    for (int i = 0; i < 5; i++)
    {
        if (cantidadDemandada[i] != 0){
            float calculoTiempo = tiempoFabricacion[i]*cantidadDemandada[i];

            *tiempoTotal += calculoTiempo;

            int calculoRecursos = recursosUnidad[i]*cantidadDemandada[i];

            *recursosTotales += calculoRecursos;

            printf("%-30s %-15.2f %d\n", nombres[i], calculoTiempo, calculoRecursos);
        }
    }

    printf("Tiempo total:%.2f\n", *tiempoTotal);
    printf("Recursos totales:%d\n", *recursosTotales);

    *calculoProduccion = 1;
}

void verificarCapacidadProduccion(float tiempoTotal, int recursosTotales){
    
    float tiempoDisponible;
    int recursosDisponibles;

    printf("Ingrese el tiempo de produccion disponible en minutos\n");
    tiempoDisponible = validarRangoFloatMinimo(0);
    printf("Ingrese la cantidad de recursos disponibles\n");
    recursosDisponibles = validarRangoInt(0);

    printf("%-25s %s\n", "Tiempo necesario", "Tiempo disponible");
    printf("%-25.2f %.2f\n", tiempoTotal, tiempoDisponible);
    printf("%-25s %s\n", "Recursos necesarios", "Recursos disponibles");
    printf("%-25d %d\n", recursosTotales, recursosDisponibles);

    if (tiempoTotal <= tiempoDisponible && recursosTotales <= recursosDisponibles){
        printf("Estado: SUFICIENTE\n");
    }
    else{
        printf("Estado: INSUFICIENTE\n");
    }
}