#ifndef __Link_List_H
#define __Link_List_H

// 定义一个结构体Node，表示栈的节点，包含一个double类型的数据和指向下一个节点的指针
typedef struct Node {
    double data;        // 节点中存储的数据
    struct Node* next; // 指向下一个节点的指针
} Node;

// 定义一个结构体Stack，表示栈，只包含一个指向栈顶节点的指针
typedef struct {
    Node* top;  // 指向栈顶节点的指针
} Stack;

Stack* InitStack_LinkList();
void push_LinkList(Stack* s, double e);
int pop_LinkList(Stack* s);
double GetTop_LinkList(Stack* s);
void Delete_LinkList(Stack* s);
double computer_LinkList(char* buffer);
void Ans_Link_List();

#endif // !__Link_List_H




