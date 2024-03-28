#include<stdio.h>
#include<stdlib.h>
#include<Menu.h>
#include<string>


int Flag=0;

void Menu() {

    printf("|--------------------- 计算器 -----------------------|\n");
    printf("|                                                    |\n");
    printf("|------------------ 1：链栈实现 ---------------------|\n");
    printf("|------------------ 2：顺序实现 ---------------------|\n");
    printf("|------------------ 3：退    出 ---------------------|\n");
    printf("|                                                    |\n");
    printf("|--------------------- 计算器 -----------------------|\n");
    printf("请输入菜单功能（1-3）:");
    scanf("%d", &Flag);
}
int Back_Meun(){
    return Flag = 0;
}
int GetFlag(){
    return Flag;
}
void remind(){
    printf("输入算式以=和enter结尾\n");
}
