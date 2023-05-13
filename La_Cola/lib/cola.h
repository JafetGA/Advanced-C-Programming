#include <stdio.h>
#include <stdlib.h>

#define PAUSA system("pause")
#define CLS system("cls")

struct Nodo
{
    char info;
    struct Nodo *sig;
};

typedef struct Nodo nodo;

// Prototipos
nodo *insert(nodo *, char);
nodo *remueve(nodo *, char *);
void imprimeCola(nodo *);

// Funciones para insertsar Nodos
nodo *insert(nodo *raiz, char dato)
{
    nodo *nuevo = NULL;
    nuevo = (nodo *)malloc(sizeof(nodo));
    if (nuevo == NULL)
    { // Prevenir el OverFlow
        printf("Error: no hay memoria disponible \n");
        exit(1); // mata al programa
    }

    nuevo->info = dato;
    nuevo->sig = NULL;
    if (raiz == NULL)
    {
        raiz = nuevo;
    }
    else
    {
        nodo *recorre = raiz;
        while (recorre->sig != NULL)
        {
            recorre = recorre->sig;
        }
        recorre->sig = nuevo;
    }
    return raiz;
}

nodo *remueve(nodo *raiz, char *dato)
{
    nodo *recorre = NULL;
    nodo *primero = NULL;
    // si la lista esta vacia
    if (raiz == NULL)
    {
        printf("La lista esta vacia.\nNo hay nada que remover.\n");
        return NULL;
    } // Prevenir el UnderFlow
    recorre = raiz;
    primero = recorre->sig;
    recorre->sig = raiz;
    *dato = recorre->info;
    raiz = primero;
    free(recorre);
    return raiz;
}

int isEmpty(nodo *raiz)
{
    if (raiz == NULL)
        return 1;
    else
        return 0;
}

void imprimeCola(nodo *raiz)
{
    nodo *recorre = raiz;
    while (recorre != NULL)
    {
        printf("| %c |", recorre->info);
        recorre = recorre->sig;
    }
    putchar('\n');
}
