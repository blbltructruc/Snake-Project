#include "linkedlist.h"

Snake* initializeSnake() {
    Snake* snake = malloc(sizeof(snake));
    if (snake != NULL) {
        snake->head = NULL;
        snake->tail = NULL;
    }
    return snake;
}

void insertBeginning(Snake* snake, int x, int y) {

    if (snake->head == NULL) {
        Node* node = malloc(sizeof(Node));
        if (node != NULL) {
            node->next = (struct Node *)snake->tail;
            node->body.x = x;
            node->body.y = y;
            node->body.w = 25;
            node->body.h = 25;
            snake->head = node;
        }
        return;
    }

    else {
        Node* node = malloc(sizeof(Node));
        if (node != NULL) {
            node->body.x = x;
            node->body.y = y;
            node->body.w = 25;
            node->body.h = 25;
            node->next = (struct Node *)snake->head;
            snake->head = node;
        }
    }
}

void insertEnd(Snake* snake, int x, int y) {

    if (snake->tail == NULL) {
        Node* node = malloc(sizeof(Node));
        node->next = NULL;
        snake->head->next = (struct Node*)node;
        node->body.x = x;
        node->body.y = y;
        node->body.w = 25;
        node->body.h = 25;
        snake->tail = node;
    }

    else {
        Node* node = malloc(sizeof(Node));
        if (node != NULL) {
            node->next = NULL;
            node->body.x = x;
            node->body.y = y;
            node->body.w = 25;
            node->body.h = 25;
            snake->tail->next = (struct Node*)node;
            snake->tail = node;
        }
    }
}

void deleteBeginning(Snake* snake) {
    
    if (snake->head != NULL) {
        Node* temp = snake->head;
        snake->head = (Node*)snake->head->next;
        free(temp);
    }
}

void deleteEnd(Snake* snake) {
    if (snake->tail != NULL) {
        Node* temp = snake->head;
        while ((Node*)temp->next != snake->tail) {
            temp = (Node*)temp->next;
        }
        snake->tail = temp;
        free(temp);
    }
}
