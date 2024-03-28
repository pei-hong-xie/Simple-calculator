#include<stdio.h>
#include<stdlib.h>
#include<LinkList.h>
#include <cmp.h>
#include<Menu.h>
Stack* InitStack_LinkList() {
    Stack* s = (Stack*)malloc(sizeof(Stack));

    if (s == NULL) {
        printf("ÄÚ´æ·ÖÅäÊ§°Ü\n");
        exit(EXIT_FAILURE);
    }
    s->top = NULL;
    return s;
}

void push_LinkList(Stack* s, double e) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("ÄÚ´æ·ÖÅäÊ§°Ü\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = e;
    newNode->next = s->top;
    s->top = newNode;
}

int pop_LinkList(Stack* s) {
    if (s->top == NULL) {
        return 0;
    }
    Node* temp = s->top;
    s->top = s->top->next;
    free(temp);
    return 1;
}

double GetTop_LinkList(Stack* s) {
    if (s->top != NULL) {
        return s->top->data;
    }
    else {
        printf("Õ»Îª¿Õ\n");
        exit(EXIT_FAILURE);
    }
}

void Delete_LinkList(Stack* s) {
    while (s->top != NULL) {
        pop_LinkList(s);
    }
    free(s);
}

double computer_LinkList() {
    char ch;
    Stack* num = InitStack_LinkList();
    Stack* ope = InitStack_LinkList();
    push_LinkList(ope, '=');

    int q = 1;
    double e, a, b, s;
    char c;

    scanf("%c", &ch);
    while (ch != '=' || GetTop_LinkList(ope) != '=') {
        if (ch == '(') {
            q = 0;
        }
        if (ch == ')') {
            q = 1;
        }

        if (In(ch) == 0) {
            switch (cmp(GetTop_LinkList(ope), ch)) {
            case '<':
                push_LinkList(ope, ch);
                scanf("%c", &ch);
                break;
            case '>':
                c = GetTop_LinkList(ope);
                pop_LinkList(ope);
                a = GetTop_LinkList(num);
                pop_LinkList(num);
                b = GetTop_LinkList(num);
                pop_LinkList(num);
                push_LinkList(num, count(a, c, b));
                break;
            case '=':
                pop_LinkList(ope);
                scanf("%c", &ch);
                break;
            }
        }
        if ((ch >= '0' && ch <= '9') || ch == '.') {
            char cc[20];
            int i;
            for (i = 0; (ch >= '0' && ch <= '9') || ch == '.'; i++) {
                if ((ch >= '0' && ch <= '9') || ch == '.') {
                    cc[i] = ch;
                    scanf("%c", &ch);
                }
            }
            cc[i] = '\0';
            e = atof(cc);
            push_LinkList(num, e);
        }
        if (ch == '=' && q == 0) {
            printf("¼ÆËãÊ½´íÎó£¡£¡£¡\n");
            exit(EXIT_FAILURE);
        }
    }

    s = GetTop_LinkList(num);
    pop_LinkList(ope);
    Delete_LinkList(num);
    Delete_LinkList(ope);
    return s;
}

void Ans_Link_List() {
    printf("Á´Õ»ÊµÏÖ:\n");
     remind();
    double ans2;
    ans2 = computer_LinkList();
    printf("%lf\n", ans2);
    Back_Meun();
}
