#include <stdio.h>
#include "../lib/Listas.h"

#define pausa system("pause")
#define cls system("cls")

int main()
{
    nodo *lista1 = NULL;
    char dato;

    lista1 = insert(lista1, 'J');
    lista1 = insert(lista1, 'A');
    lista1 = insert(lista1, 'F');
    lista1 = insert(lista1, 'E');
    lista1 = insert(lista1, 'T');

    imprimeLista(lista1);

    lista1 = insert1(lista1, 'I');
    lista1 = insert1(lista1, 'L');
    lista1 = insert1(lista1, 'E');

    imprimeLista(lista1);

    lista1 = insert(lista1, 'G');
    lista1 = insert(lista1, 'A');

    imprimeLista(lista1);

    lista1 = remueve(lista1, &dato);
    printf("Se elimino: %c\n", dato);
    imprimeLista(lista1);

    pausa;
    cls;
    return 0;
}