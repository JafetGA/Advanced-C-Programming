#if !defined(Header_pila)
#define Header_pila

#include <stdio.h>
#include <stdlib.h>

#define PAUSA system("pause")
#define UbPausa                                   \
    printf("Presiona Enter para continuar...\n"); \
    getchar()
#define UbClear system("clear")
#define CLS system("cls")

struct Nodo
{
    char info;
    struct Nodo *sig;
};

typedef struct Nodo nodo;

// Prototipos
nodo *push(nodo *, char);
nodo *pop(nodo *, char *);
int isEmpty(nodo *);
char peek(nodo *);
void imprimeStack(nodo *raiz);

nodo *push(nodo *peek, char dato)
{
    nodo *nuevo = NULL;
    nuevo = (nodo *)malloc(sizeof(nodo));
    if (nuevo == NULL)
    { // Prevenir overflow
    printf("Error: no hay memoria disponible \n");
        exit(1);
    }
    nuevo->info = dato;
    nuevo->sig = peek;

    peek = nuevo;
    return peek;
}

nodo *pop(nodo *peek, char *dato)
{
    nodo *recorre = NULL;
    nodo *first = NULL;
    // si la lista esta vacía
    if (peek == NULL)
    {
        printf("La lista esta vacía.\nNo hay nada que remover.\n");
        return NULL;
    } // previene el underflow
    recorre = peek;
    first = recorre->sig;
    recorre->sig = peek;
    *dato = recorre->info;
    peek = first;
    free(recorre);
    return peek;
}

int isEmpty(nodo *peek)
{
    if (peek == NULL)
        return 1;
    else
        return 0;
}

char peek(nodo *peek)
{

    if (peek == NULL)
    {
        printf("La lista esta vacía.\nNo hay nada que remover.\n");
        return '\0';
    }

    return peek->info;
}

void imprimeStack(nodo *peek)
{
    nodo *recorre = peek;
    while (recorre != NULL)
    {
        printf("| %c |", recorre->info);
        recorre = recorre->sig;
        putchar('\n');
    }
}

#endif // Header_pila
