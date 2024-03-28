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

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
