#include<stdio.h>
#include<stdlib.h>
#include<LinkList.h> // 包含链表栈的头文件
#include <cmp.h> // 包含比较函数的头文件
#include<Menu.h> // 包含菜单函数的头文件
#include<string.h>
#include <ctype.h>


char buffer[100];
// 初始化链表栈
Stack* InitStack_LinkList() {
    Stack* s = (Stack*)malloc(sizeof(Stack));

    if (s == NULL) {
        printf("内存分配失败\n");
        exit(EXIT_FAILURE);
    }
    s->top = NULL;
    return s;
}

// 入栈操作
void push_LinkList(Stack* s, double e) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("内存分配失败\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = e;
    newNode->next = s->top;
    s->top = newNode;
}

// 出栈操作
int pop_LinkList(Stack* s) {
    if (s->top == NULL) {
        return 0; // 栈为空，出栈失败
    }
    Node* temp = s->top;
    s->top = s->top->next;
    free(temp);
    return 1; // 出栈成功
}

// 获取栈顶元素
double GetTop_LinkList(Stack* s) {
    if (s->top != NULL) {
        return s->top->data;
    }
    else {
        printf("栈为空\n");
        exit(EXIT_FAILURE);
    }
}

// 清空栈
void Delete_LinkList(Stack* s) {
    while (s->top != NULL) {
        pop_LinkList(s);
    }
    free(s);
}

// 使用链表栈实现的计算函数
double computer_LinkList(char* buffer) {
    char ch;
    Stack* num = InitStack_LinkList(); // 数字栈
    Stack* ope = InitStack_LinkList(); // 操作符栈
    push_LinkList(ope, '='); // 先入栈一个等号作为结束符号

    int q = 1;
    double e, a, b, s;
    char c;

    int index = 0;
    ch = buffer[index]; // 初始化 ch
    while (ch != '\0' && (ch != '=' || GetTop_LinkList(ope) != '=')) { // 直到遇到字符串结尾或者等号且操作符栈顶也为等号才结束循环
        if (isspace(ch)) { // 忽略空白字符
            index++;
            ch = buffer[index];
            continue;
        }

        if (ch == '(') {
            q = 0; // 遇到左括号，q置0
        }
        else if (ch == ')') {
            q = 1; // 遇到右括号，q置1
        }
        if (isspace(ch)) { // 如果是空白字符，直接读取下一个字符
            index++;
            ch = buffer[index];
            continue;
        }
        else if (isdigit(ch) || ch == '.') { // 如果ch是数字或小数点
            char cc[20];
            int i = 0;
            while (isdigit(ch) || ch == '.') { // 读取数字字符串
                cc[i++] = ch;
                index++;
                ch = buffer[index];
            }
            cc[i] = '\0';
            e = atof(cc); // 将字符数组转换为双精度浮点数
            push_LinkList(num, e); // 数字入栈
            continue;
        }
        else { // 如果是操作符
            switch (cmp(GetTop_LinkList(ope), ch)) {
            case '<':
                push_LinkList(ope, ch);
                break;
            case '>':
                c = GetTop_LinkList(ope);
                pop_LinkList(ope);
                a = GetTop_LinkList(num);
                pop_LinkList(num);
                b = GetTop_LinkList(num);
                pop_LinkList(num);
                push_LinkList(num, count(a, c, b));
                continue;
            case '=':
                pop_LinkList(ope);
                break;
            }
        }
        index++;
        ch = buffer[index];
    }
    if (ch != '=' && ch != '\n') { // 输入不以等号或换行符结尾，显示输入错误信息并结束程序
        printf("输入错误: 输入未完成\n");
        exit(EXIT_FAILURE);
    }
    s = GetTop_LinkList(num); // 获取计算结果
    pop_LinkList(ope);
    Delete_LinkList(num); // 释放内存
    Delete_LinkList(ope);
    return s; // 返回计算结果
}
// 调用链表栈实现的计算函数，并输出结果
void Ans_Link_List() {
    printf("链栈实现:\n");
    remind(); // 提示用户输入表达式
    double ans2;
    int index = 0; // 用于记录字符数组的当前索引位置
    // 循环读取每个字符，直到遇到换行符（Enter 键）
    fgets(buffer, sizeof(buffer), stdin); // 从标准输入中读取字符串
    ans2 = computer_LinkList(buffer);
    printf("%lf\n", ans2); // 输出结果
    Back_Meun(); // 返回菜单
}
