#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../lib/cola.h"

// Macros

#define NCAJEROS 8

void simularDia(int, int, int *);

typedef struct
{
    int tiempoAtencion;
    int tiempoCliente;
} Cajeros;

int main(void)
{
    int razonLlegada = 160;
    int numeroCajeros = 3;
    int tiempoAtencionCajero[] = {213, 155, 200};

    simularDia(razonLlegada, numeroCajeros, tiempoAtencionCajero);

    PAUSA;
    return 0;
}

void simularDia(int tiempoLlegada, int numeroCajeros, int *tiempoAtencionCajeros)
{
    srand(time(NULL));
    nodo *cola = NULL;
    Cajeros cajeros[NCAJEROS];
    int tiempoEspera = 0, totalClientes = 0, clientesAtendidos = 0;
    int colaVacia = 0;
    int llegaCliente = rand() % tiempoLlegada + 1;
    int getCliente;
    int segundo = 0;

    for (int i = 0; i < numeroCajeros; i++)
    {
        cajeros[i].tiempoAtencion = tiempoAtencionCajeros[i];
        cajeros[i].tiempoCliente = 0;
    }

    while (segundo <= 34200)
    {
        if (segundo == llegaCliente)
        {
            cola = insert(cola, totalClientes);
            totalClientes++;
            llegaCliente = segundo + (rand() % tiempoLlegada + 1);
        }
        for (int i = 0; i < numeroCajeros; i++)
        {
            if (cajeros[i].tiempoCliente > 0)
            {
                cajeros[i].tiempoCliente--;
            }
            else if (size(cola) > 0)
            {
                cajeros[i].tiempoCliente = rand() % cajeros[i].tiempoAtencion;
                cola = remueve(cola, &getCliente);
                tiempoEspera += segundo - getCliente;
                clientesAtendidos++;
            }
        }

        if (isEmpty(cola))
        {
            colaVacia++;
        }

        segundo++;
    }
    // Imprimir resultados
    printf("Inicio de Actividades 8:00\n");
    printf("Fin de Actividades 5:30\n");
    printf("Se atendieron %d Clientes\n", totalClientes);
    printf("Quedaron %d Clientes en cola de espera\n", size(cola));
    printf("El Cliente permanece en Promedio %d segundos en la cola.\n", tiempoEspera / totalClientes);
    printf("La cola estuvo vacía %d Veces\n", colaVacia);
}
