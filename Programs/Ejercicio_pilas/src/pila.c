#include <stdio.h>
#include <stdlib.h>

int prec(char, char);
void postfijo(char *);

const int maxLen = 80;
char *expresion;

int main()
{

    expresion = (char *)calloc(maxLen, sizeof(char));

    printf("Ingrese una expresión Mátematica: ");
    scanf("%99[^\n]%*c", expresion);
    // printf("La cadena ingresada es: %s\n", expresion);

    postfijo(expresion);
    return 0;
}
