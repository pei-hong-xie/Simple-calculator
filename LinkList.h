#ifndef __Link_List_H
#define __Link_List_H





typedef struct Node {
    double data;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
} Stack;

Stack* InitStack_LinkList();
void push_LinkList(Stack* s, double e);
int pop_LinkList(Stack* s);
double GetTop_LinkList(Stack* s);
void Delete_LinkList(Stack* s);

void Ans_Link_List();

#endif // !__Link_List_H




