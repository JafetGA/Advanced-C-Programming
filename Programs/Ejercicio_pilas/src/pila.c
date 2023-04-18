#include "../lib/pila.h"
int prec(char, char);

const int maxLen = 80;
char *expresion;

int main()
{
    expresion = (char *)malloc(maxLen * sizeof(char));

    printf("Ingrese una expresión Mátematica: ");
    scanf("%99[^\n]%*c", expresion);
    printf("La cadena ingresada es: %s\n", expresion);

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