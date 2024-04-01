#include <stdio.h>
#include <stdlib.h>
#include <SequenceList.h> // 包含顺序栈的头文件
#include <cmp.h> // 包含比较函数的头文件
#include <Menu.h> // 包含菜单函数的头文件
#include <ctype.h>


#define  MAX_SIZE 100 // 定义栈的最大容量
extern char buffer[100];
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
double Computer_SequenceList(char* buffer) {
    char ch;
    Stack_Se num, ope;
    InitStack_SequenceList(&num); // 初始化数字栈
    InitStack_SequenceList(&ope); // 初始化操作符栈
    push_SequenceList(&ope, '='); // 先入栈一个等号作为结束符号

    int q = 1;
    double e, a, b, s;
    char c;

    int index = 0;
    ch = buffer[index]; // 初始化 ch
    while (ch != '\0' && (ch != '=' || GetTop_SequenceList(ope) != '=')) { // 直到遇到字符串结尾或者等号且操作符栈顶也为等号才结束循环
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
            push_SequenceList(&num, e); // 数字入栈
            continue;
        }
        else { // 如果是操作符
            switch (cmp(GetTop_SequenceList(ope), ch)) {
            case '<':
                push_SequenceList(&ope, ch);
                break;
            case '>':
                c = GetTop_SequenceList(ope);
                pop_SequenceList(&ope);
                a = GetTop_SequenceList(num);
                pop_SequenceList(&num);
                b = GetTop_SequenceList(num);
                pop_SequenceList(&num);
                push_SequenceList(&num, count(a, c, b));
                continue;
            case '=':
                pop_SequenceList(&ope);
                break;
            }
        }
        index++;
        ch = buffer[index];
    }
    if (ch != '=' && ch != '\n') { // 输入不以等号或换行符结尾，显示输入错误信息并结束程序
        printf("输入错误: 输入未完成\n");
        return -1;
        //exit(EXIT_FAILURE);
    }
    s = GetTop_SequenceList(num); // 获取计算结果
    pop_SequenceList(&ope);
    Delete_SequenceList(&num); // 释放内存
    Delete_SequenceList(&ope);
    return s; // 返回计算结果
}

// 调用顺序栈实现的计算函数，并输出结果
void Ans_SequenceList() {
    remind(); // 提示用户输入表达式
    double ans1;
    int index = 0; // 用于记录字符数组的当前索引位置
    // 循环读取每个字符，直到遇到换行符（Enter 键）
    fgets(buffer, sizeof(buffer), stdin); // 从标准输入中读取字符串
    ans1 = Computer_SequenceList(buffer);
    printf("%lf\n", ans1); // 输出结果
    Back_Meun(); // 返回菜单
}
