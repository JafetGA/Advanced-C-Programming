#include "../lib/pila.h"
#include <string.h>

nodo *pila = NULL;

int prec(char op1, char op2)
{
    int jer1, jer2; // Valores jerarquicos
    switch (op1)
    {
    case '^':
        jer1 = 3;
        break;

    case '*':
    case '/':
        jer1 = 2;
        break;

    case '+':
    case '-':
        jer1 = 1;
        break;

    default:
        jer1 = 0;
        break;
    }

    switch (op2)
    {
    case '^':
        jer2 = 3;
        break;

    case '*':
    case '/':
        jer2 = 2;
        break;

    case '+':
    case '-':
        jer2 = 1;
        break;

    default:
        jer2 = 0;
        break;
    }

    return (jer1 >= jer2);
}

int esOperador(char dato)
{
    switch (dato)
    {
    case '^':
    case '*':
    case '/':
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}

void postfijo(char *expresion)
{
    // nodo *pila = NULL;
    int i = 0, j = 0;
    char postfijo[strlen(expresion)], symb, topSymb;

    for (i = 0; i < strlen(expresion); i++)
    {
        symb = expresion[i];
        if (symb == ' ' || symb == '\t')
        {
            continue;
        }
        else if (esOperador(symb))

        {
            while (!isEmpty(pila) && prec(peek(pila), symb))
            {
                pila = pop(pila, &topSymb);
                postfijo[j++] = topSymb;
            }
            pila = push(pila, symb);
        }
        else
        {
            postfijo[j++] = symb;
        }
    }
    while (!isEmpty(pila))
    {
        pila = pop(pila, &topSymb);
        postfijo[j++] = topSymb;
    }
    postfijo[j] = '\0';

    // Imprimir el resultado
    printf("La expresion en postfijo es: %s\n", postfijo);
    PAUSA;
    CLS;
}