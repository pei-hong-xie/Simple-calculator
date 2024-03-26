#include<stdio.h>
#include<stdlib.h>
#include<cmp.h>
#include<Linklist.h>


char m[7][7] = {
    {'>', '>', '<', '<', '<', '>', '>'},
    {'>', '>', '<', '<', '<', '>', '>'},
    {'>', '>', '>', '>', '<', '>', '>'},
    {'>', '>', '>', '>', '<', '>', '>'},
    {'<', '<', '<', '<', '<', '=', '#'},
    {'>', '>', '>', '>', '#', '>', '>'},
    {'<', '<', '<', '<', '<', '#', '='},
};



int In(char ch) {
    switch (ch) {
    case '+': return 0;
    case '-': return 0;
    case '*': return 0;
    case '/': return 0;
    case '(': return 0;
    case ')': return 0;
    case '=': return 0;
    }
    return 1;
}

char cmp(char a, char b) {
    int i = 0, j = 0;
    switch (a) {
    case'+': i = 0; break;
    case'-': i = 1; break;
    case'*': i = 2; break;
    case'/': i = 3; break;
    case'(': i = 4; break;
    case')': i = 5; break;
    case'=': i = 6; break;
    }

    switch (b) {
    case'+': j = 0; break;
    case'-': j = 1; break;
    case'*': j = 2; break;
    case'/': j = 3; break;
    case'(': j = 4; break;
    case')': j = 5; break;
    case'=': j = 6; break;
    }
    return m[i][j];
}

double count(double a, char c, double b) {
    double s;
    switch (c) {
    case '+':
        s = b + a; break;
    case '-':
        s = b - a; break;
    case '*':
        s = b * a; break;
    case '/':
        if (a == 0) {
            printf("¼ÆËãÊ½´íÎó£¡£¡£¡\n");
            exit(EXIT_FAILURE);
        }
        s = b / a; break;
    }
    return s;
}

double computer() {
    char ch;
    Stack* num = InitStack();
    Stack* ope = InitStack();
    push(ope, '=');

    int q = 1;
    double e, a, b, s;
    char c;

    scanf("%c", &ch);
    while (ch != '=' || GetTop(ope) != '=') {
        if (ch == '(') {
            q = 0;
        }
        if (ch == ')') {
            q = 1;
        }

        if (In(ch) == 0) {
            switch (cmp(GetTop(ope), ch)) {
            case '<':
                push(ope, ch);
                scanf("%c", &ch);
                break;
            case '>':
                c = GetTop(ope);
                pop(ope);
                a = GetTop(num);
                pop(num);
                b = GetTop(num);
                pop(num);
                push(num, count(a, c, b));
                break;
            case '=':
                pop(ope);
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
            push(num, e);
        }
        if (ch == '=' && q == 0) {
            printf("¼ÆËãÊ½´íÎó£¡£¡£¡\n");
            exit(EXIT_FAILURE);
        }
    }

    s = GetTop(num);
    pop(ope);
    Delete(num);
    Delete(ope);
    return s;
}