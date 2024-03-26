#include<stdio.h>
#include<stdlib.h>
#include<LinkList.h>


Stack* InitStack() {
    Stack* s = (Stack*)malloc(sizeof(Stack));

    if (s == NULL) {
        printf("ÄÚ´æ·ÖÅäÊ§°Ü\n");
        exit(EXIT_FAILURE);
    }
    s->top = NULL;
    return s;
}

void push(Stack* s, double e) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("ÄÚ´æ·ÖÅäÊ§°Ü\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = e;
    newNode->next = s->top;
    s->top = newNode;
}

int pop(Stack* s) {
    if (s->top == NULL) {
        return 0;
    }
    Node* temp = s->top;
    s->top = s->top->next;
    free(temp);
    return 1;
}

double GetTop(Stack* s) {
    if (s->top != NULL) {
        return s->top->data;
    }
    else {
        printf("Õ»Îª¿Õ\n");
        exit(EXIT_FAILURE);
    }
}

void Delete(Stack* s) {
    while (s->top != NULL) {
        pop(s);
    }
    free(s);
}



