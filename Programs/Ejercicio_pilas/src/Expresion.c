#include "../lib/pila.h"
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

nodo *pila;
int profundidad(char *expresion)
{
    int i = 0;
    char symb, temp;
    bool equal = true;
    pila = NULL;
    while (expresion[i] != '\0')
    { // Carácter final de una cadena  '\0'
        symb = expresion[i];
        if (symb == '(' || symb == '{' || symb == '[')
        {
            pila = push(pila, symb);
        }
        if (symb == ')' || symb == '}' || symb == ']')
        {
            if (isEmpty(pila))
            {
                equal = false;
            }
            else
            {
                pila = pop(pila, &temp);
                if (symb == ')')
                    symb = '(';
                else if (symb == '}')
                    symb = '{';
                else
                    symb = '[';
                if (temp != symb)
                {
                    equal = false;
                }
                else
                {
                    equal = true;
                }
            }
        }
        i++;
    }
    if (!isEmpty(pila))
    {
        return equal;
    }
    return equal;
}
int prec(char op1, char op2)
{
    int jer1, jer2;
    switch (op1)
    {
    case '(':
    case '[':
    case '{':
        jer1 = -2;
        break;
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
    case ')':
    case ']':
    case '}':
        jer2 = -1;
        break;
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

    if (jer1 >= jer2)
    {
        return 1;
    }
    else
        return 0;
}

void postfijo(char *expresion)
{
    char symb, topSymb;
    char *postfijo;
    int i, j;
    pila = NULL;
    postfijo = (char *)calloc(strlen(expresion), sizeof(char));
    j = 0;
    i = 0;
    while (expresion[i] != '\0')
    {
        symb = expresion[i];
        if (isalnum(symb))
        {
            postfijo[j++] = symb;
        }
        else if (symb == '(' || symb == '[' || symb == '{')
        {
            pila = push(pila, symb);
        }
        else if (symb == ')' || symb == ']' || symb == '}')
        {
            char openSymb;
            if (symb == ')')
                openSymb = '(';
            else if (symb == ']')
                openSymb = '[';
            else if (symb == '}')
                openSymb = '{';

            while (!isEmpty(pila) && peek(pila) != openSymb)
            {
                pila = pop(pila, &topSymb);
                postfijo[j++] = topSymb;
            }
            if (!isEmpty(pila) && peek(pila) == openSymb)
                pila = pop(pila, &topSymb);
        }
        else
        {
            while (!isEmpty(pila) && prec(peek(pila), symb))
            {
                pila = pop(pila, &topSymb);
                postfijo[j++] = topSymb;
            }
            pila = push(pila, symb);
        }
        i++;
    }
    while (!isEmpty(pila))
    {
        pila = pop(pila, &topSymb);
        postfijo[j++] = topSymb;
    }
    postfijo[j] = '\0';
    printf("La expresión en postfijo es: %s\n", postfijo);
    PAUSA;
}