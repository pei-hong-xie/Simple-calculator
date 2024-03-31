#include <stdio.h>
#include <stdlib.h>
#include <SequenceList.h> // 包含顺序栈的头文件
#include <cmp.h> // 包含比较函数的头文件
#include <Menu.h> // 包含菜单函数的头文件
#define  MAX_SIZE 100 // 定义栈的最大容量

// 初始化顺序栈
int InitStack_SequenceList(Stack_Se* s) {
    s->base = (double*)malloc(MAX_SIZE * sizeof(double)); // 分配内存
    if (!s->base)
        return 0; // 内存分配失败
    s->top = s->base; // 初始化栈顶指针
    s->stacksize = MAX_SIZE; // 栈的最大容量
    return 1; // 初始化成功
}

// 入栈操作
int push_SequenceList(Stack_Se* s, double e) {
    if (s->top - s->base == s->stacksize) // 栈满
        return 0;
    *(s->top++) = e; // 元素入栈
    return 1; // 入栈成功
}

// 出栈操作
int pop_SequenceList(Stack_Se* s) {
    if (s->top == s->base) // 栈空
        return 0;
    --(s->top); // 栈顶指针减一
    return 1; // 出栈成功
}

// 获取栈顶元素
double GetTop_SequenceList(Stack_Se s) {
    if (s.top != s.base)
        return *(s.top - 1); // 返回栈顶元素
    else {
        printf("计算式错误！！！\n");
        exit(-1); // 栈空，出错退出
    }
}

// 清空栈
void Delete_SequenceList(Stack_Se* s) {
    free(s->base); // 释放内存
}

// 使用顺序栈实现的计算函数
double Computer_SequenceList() {
    char ch;
    Stack_Se num, ope;
    InitStack_SequenceList(&num); // 初始化数字栈
    InitStack_SequenceList(&ope); // 初始化操作符栈
    push_SequenceList(&ope, '='); // 先入栈一个等号作为结束符号

    int q = 1;
    double e, a, b, s;
    char c;

    ch = getchar(); // 读取第一个字符
    while (ch != '=' || GetTop_SequenceList(ope) != '=') { // 直到遇到等号且操作符栈顶也为等号才结束循环
        if (ch == '(') {
            q = 0;
        }
        if (ch == ')') {
            q = 1;
        }

        if (In(ch) == 0) { // 如果ch是数字或小数点
            switch (cmp(GetTop_SequenceList(ope), ch)) { // 比较栈顶操作符和当前操作符的优先级
            case '<':
                push_SequenceList(&ope, ch); // 当前操作符优先级高，入栈
                scanf("%c", &ch); // 读取下一个字符
                break;
            case '>':
                c = GetTop_SequenceList(ope); // 栈顶操作符
                pop_SequenceList(&ope); // 出栈
                a = GetTop_SequenceList(num); // 第二个操作数
                pop_SequenceList(&num); // 出栈
                b = GetTop_SequenceList(num); // 第一个操作数
                pop_SequenceList(&num); // 出栈
                push_SequenceList(&num, count(a, c, b)); // 计算结果入栈
                break;
            case '=':
                pop_SequenceList(&ope); // 当前操作符和栈顶操作符优先级相等，出栈
                scanf("%c", &ch); // 读取下一个字符
                break;
            }
        }
        if ((ch >= '0' && ch <= '9') || ch == '.') { // 如果ch是数字或小数点
            char cc[20];
            int i;
            for (i = 0; (ch >= '0' && ch <= '9') || ch == '.'; i++) {
                if ((ch >= '0' && ch <= '9') || ch == '.') {
                    cc[i] = ch;
                    scanf("%c", &ch); // 读取下一个字符
                }
            }
            cc[i] = '\0';
            e = atof(cc); // 将字符数组转换为双精度浮点数
            push_SequenceList(&num, e); // 数字入栈
        }
        if (ch == '=' && q == 0) { // 如果等号前有未闭合的左括号，表达式错误
            printf("计算式错误！！！\n");
            exit(-1);
        }
    }

    s = GetTop_SequenceList(num); // 获取计算结果
    pop_SequenceList(&ope);
    Delete_SequenceList(&num);
    Delete_SequenceList(&ope);
    return s; // 返回计算结果
}

// 调用顺序栈实现的计算函数，并输出结果
void Ans_SequenceList() {
    printf("顺序栈实现:\n");
    remind(); // 提示用户输入表达式
    double ans1;
    ans1 = Computer_SequenceList();
    printf("%lf\n", ans1); // 输出结果
    Back_Meun(); // 返回菜单
}
