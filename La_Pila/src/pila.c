#include "../lib/pila.h"
int prec(char, char);

const int maxLen = 80;
char *expresion;

int main()
{
    expresion = (char *)malloc(maxLen * sizeof(char));

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

int prec(char op1, char op2)
{
    switch (op1)
    {
    case '^':

        break;

    default:
        break;
    }
}