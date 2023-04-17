#include "../lib/pila.h"

const int maxLen = 100;
char *expresion;

int main()
{
    nodo *nombre = NULL;
    nombre = push(nombre, 'T');
    nombre = push(nombre, 'F');
    nombre = push(nombre, 'E');
    nombre = push(nombre, 'A');
    nombre = push(nombre, 'J');

    expresion = (char *)malloc(maxLen * sizeof(char));

    printf("Ingrese una cadena: ");
    scanf("%99[^\n]%*c", expresion);
    printf("La cadena ingresada es: %s\n", expresion);

    imprimeStack(nombre);

    UbPausa;
    UbClear;
    return 0;
}