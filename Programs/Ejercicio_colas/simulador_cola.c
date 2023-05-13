#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Asegúrate de tener una implementación de lista ligada.
#include "linked_list.h"

#define OPENING_TIME 8*60*60 // 8:00 AM en segundos
#define CLOSING_TIME 17.5*60*60 // 5:30 PM en segundos
#define MAX_CASHIERS 8

// Estructura para guardar información de los cajeros
typedef struct {
    int service_time;
    int current_customer_time;
} Cashier;

// Función para simular el día de trabajo en el banco
void simulate_day(int arrival_rate, int num_cashiers, int* cashier_service_times) {
    srand(time(NULL));
    LinkedList* queue = linked_list_new();
    Cashier cashiers[MAX_CASHIERS];
    int total_wait_time = 0, total_customers = 0, total_served_customers = 0;
    int empty_queue_count = 0;
    int next_customer_arrival = rand() % arrival_rate;

    // Inicializar cajeros
    for (int i = 0; i < num_cashiers; i++) {
        cashiers[i].service_time = cashier_service_times[i];
        cashiers[i].current_customer_time = 0;
    }

    // Simulación
    for (int current_time = OPENING_TIME; current_time < CLOSING_TIME; current_time++) {
        // Llegada de cliente
        if (current_time == next_customer_arrival) {
            linked_list_add(queue, total_customers);
            total_customers++;
            next_customer_arrival = current_time + (rand() % arrival_rate);
        }

        // Atender clientes
        for (int i = 0; i < num_cashiers; i++) {
            if (cashiers[i].current_customer_time > 0) {
                cashiers[i].current_customer_time--;
            } else if (linked_list_size(queue) > 0) {
                cashiers[i].current_customer_time = rand() % cashiers[i].service_time;
                total_wait_time += current_time - linked_list_get(queue, 0);
                linked_list_remove(queue, 0);
                total_served_customers++;
            }
        }

        // Verificar si la cola está vacía
        if (linked_list_size(queue) == 0) {
            empty_queue_count++;
        }
    }

    // Imprimir resultados
    printf("Inicio de Actividades 8:00\n");
    printf("Fin de Actividades 5:30\n");
    printf("Se atendieron %d Clientes\n", total_served_customers);
    printf("Quedaron %d Clientes en cola de espera\n", linked_list_size(queue));
    printf("El Cliente permanece en Promedio %d segundos en la cola.\n", total_wait_time / total_customers);
    printf("La cola estuvo vacía %d Veces\n", empty_queue_count);

    linked_list_free(queue);
}

int main() {
    int arrival_rate = 160;
    int num_cashiers = 3;
    int cashier_service_times[] = {213, 155, 200};

    simulate_day(arrival_rate, num_cashiers, cashier_service_times);

    return 0;
}
