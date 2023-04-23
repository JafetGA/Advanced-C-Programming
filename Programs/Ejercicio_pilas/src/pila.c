#include <stdio.h>
#include <stdlib.h>

int profundidad(char *);
int prec(char, char);
void postfijo(char *);

const int maxLen = 80;
char *expresion;

int main()
{

    expresion = (char *)calloc(maxLen, sizeof(char));

    printf("Ingrese una expresión Matemática: ");
    scanf("%99[^\n]%*c", expresion);

    postfijo(expresion);
    //  printf("%d\n", prec('^', ')'));
    //  printf("%d\n", prec('*', ')'));
    //  printf("%d\n", prec('/', ')'));
    //  printf("%d\n", prec('+', ')'));
    //  printf("%d\n", prec('-', ')'));
    //  printf("%d\n", prec('(', ')'));
    //  printf("%d\n", prec(')', ')'));
    //  printf("%d\n", prec('(', '('));
    // system("pause");
    return 0;
}
