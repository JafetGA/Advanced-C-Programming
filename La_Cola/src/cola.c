#include <stdio.h>
#include <stdlib.h>
#include "../lib/cola.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main()
{
	nodo *nombre = NULL;
	char dato;

	nombre = insert(nombre, 'J');
	nombre = insert(nombre, 'A');
	nombre = insert(nombre, 'F');
	nombre = insert(nombre, 'E');
	nombre = insert(nombre, 'T');
	imprimeCola(nombre);

	nombre = remueve(nombre, &dato);
	printf("De la cola salio: %c\n", dato);
	nombre = remueve(nombre, &dato);
	printf("De la cola salio: %c\n", dato);
	nombre = remueve(nombre, &dato);
	printf("De la cola salio: %c\n", dato);

	imprimeCola(nombre);

	PAUSA;
	return 0;
}