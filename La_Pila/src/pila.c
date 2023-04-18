#include "../lib/pila.h"

int main()
{

    nodo *nombre = NULL;
    nombre = push(nombre, 'T');
    nombre = push(nombre, 'E');
    nombre = push(nombre, 'F');
    nombre = push(nombre, 'A');
    nombre = push(nombre, 'J');

    imprimeStack(nombre);

    PAUSA;
    CLS;
    return 0;
}
