#include "../lib/pila.h"
#include <string.h>
nodo *pila;
// int profundidad(char *expresion)
// {
//     pila = NULL;
//     char symb, temp;
//     int i = 0;
//     while (expresion[i] != '\0')
//     {
//         symb = expresion[i];
//         if (symb == '(' || symb == '[' || symb == '{')
//         {
//             pila = push(pila, symb);
//         }
//         else if (symb == ')' || symb == ']' || symb == '}')
//         {
//             if (isEmpty(pila))
//             {
//                 return 0;
//             }
//             else
//             {
//                 pila = pop(pila, &temp);
//                 if (symb == ')' && temp != '(')
//                 {
//                     return 0;
//                 }
//                 else if (symb == ']' && temp != '[')
//                 {
//                     return 0;
//                 }
//                 else if (symb == '}' && temp != '{')
//                 {
//                     return 0;
//                 }
//             }
//         }
//         i++;
//     }
//     if (!isEmpty(pila))
//     {
//         return 0;
//     }
//     else
//     {
//         return 1;
//     }
// }

int prec(char op1, char op2)
{
    int jer1, jer2;
    switch (op1)
    {
    case '(':
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
        if ((symb >= 'A' && symb <= 'Z') || (symb >= '0' && symb <= '9') || (symb >= 'a' && symb <= 'z'))
        {
            postfijo[j++] = symb;
        }
        else
        {
            if (isEmpty(pila) || symb == '(' || peek(pila) == '(')
                pila = push(pila, symb);
            else if (symb == ')')
            {
                while (!isEmpty(pila) && peek(pila) != '(')
                {
                    pila = pop(pila, &topSymb);
                    postfijo[j++] = topSymb;
                }
                if (!isEmpty(pila) && peek(pila) == '(')
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