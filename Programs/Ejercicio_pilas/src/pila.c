#include <stdio.h>
#include <stdlib.h>

int profundidad(char *);
int prec(char, char);
char *postfijo(char *);
float convierte(char);
float evalua(float, char, float);
float evaluarPostfijo(char *);

const int maxLen = 80;
char *expresion;

int main()
{
    expresion = (char *)calloc(maxLen, sizeof(char));

    while (1)
    {
        printf("Ingrese una expresión Matemática: ");
        scanf("%99[^\n]%*c", expresion);

        if (profundidad(expresion))
        {

            printf("%f\n", evaluarPostfijo(postfijo(expresion)));
        }
        system("pause");
    }
    return 0;
}
