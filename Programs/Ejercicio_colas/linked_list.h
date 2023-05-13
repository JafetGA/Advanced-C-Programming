#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    int size;
} LinkedList;

// Crear una nueva lista ligada
LinkedList* linked_list_new() {
    LinkedList* list = (LinkedList*) malloc(sizeof(LinkedList));
    list->head = NULL;
    list->size = 0;
    return list;
}

// Agregar un elemento al final de la lista
void linked_list_add(LinkedList* list, int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if (list->head == NULL) {
        list->head = new_node;
    } else {
        Node* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }

    list->size++;
}

// Obtener el elemento en un índice particular
int linked_list_get(LinkedList* list, int index) {
    Node* current = list->head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}

// Eliminar el elemento en un índice particular
void linked_list_remove(LinkedList* list, int index) {
    if (index == 0) {
        Node* to_delete = list->head;
        list->head = list->head->next;
        free(to_delete);
    } else {
        Node* current = list->head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        Node* to_delete = current->next;
        current->next = current->next->next;
        free(to_delete);
    }

    list->size--;
}

// Obtener el tamaño de la lista
int linked_list_size(LinkedList* list) {
    return list->size;
}

// Liberar la lista
void linked_list_free(LinkedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    free(list);
}

#endif
