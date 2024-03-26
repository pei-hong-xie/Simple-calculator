#ifndef __Link_List_H
#define __Link_List_H





typedef struct Node {
    double data;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
} Stack;


Stack* InitStack();
void push(Stack* s, double e);
int pop(Stack* s);
double GetTop(Stack* s);
void Delete(Stack* s);

























#endif // !__Link_List_H




