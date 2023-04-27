#include <stdio.h>
#include <stdlib.h>

int profundidad(char *);
int prec(char, char);
void postfijo(char *);
float convierte(char);
float evalua(float, char, float);
float evaluarPostfijo(char *);

const int maxLen = 80;
char *expresion;

int main()
{

    expresion = (char *)calloc(maxLen, sizeof(char));

    printf("Ingrese una expresión Matemática: ");
    scanf("%99[^\n]%*c", expresion);

    if (profundidad(expresion))
    {
        postfijo(expresion);
    }

    return 0;
}
