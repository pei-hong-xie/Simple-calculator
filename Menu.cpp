#include<stdio.h>
#include<stdlib.h>
#include<Menu.h>
#include<string>
#include <SequenceList.h>
#include<LinkList.h>
#include <cmp.h>
#include<file.h>


int Flag=0;
int File_Flag=0;
void Menu() {

    printf("|------------------- 计算器 ------------------|\n");
    printf("|                                             |\n");
    printf("|---------------- 1：链栈实现 ----------------|\n");
    printf("|---------------- 2：顺序实现 ----------------|\n");
    printf("|---------------- 3：文件操作  ---------------|\n");
    printf("|---------------- 4：退    出 ----------------|\n");
    printf("|                                             |\n");
    printf("|------------------- 计算器 ------------------|\n");
    printf("请输入菜单功能（1-4）:");
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

int Back_FileMeun() {
    return File_Flag = 0;
}

int GetFlag_FileMeun(){
    return File_Flag;
}


void File_Meun() {
    printf("|---------------- 1：默认测试集 ----------------|\n");
    printf("|---------------- 2：输入测试集 ----------------|(请使用绝对路径或位于Simple-calculator下的相对路径)\n");
    printf("|---------------- 3：返      回 ----------------|\n");
    printf("请输入菜单功能（1-3）:");
    scanf("%d", &File_Flag);
}

char filename[100];

void file_Meun_Init(){
    File_Meun();
    switch (GetFlag_FileMeun()){
    case 0:
        File_Meun();
        break;
    case 1:
        Read_File("F:/Soft_Project/数据结构/链表顺序表整合/test.txt");
        break;
    case 2:
        printf("请输入文件地址：");
        scanf("%s", filename);
        // 调用处理文件的函数
        Read_File(filename);

        break;
    case 3:
        break;
    default:
        printf("输入错误，请重新输入\n");
        Back_FileMeun();
        break;
    }
    getchar();
    getchar();
}




void Meun_init() {
    Menu();
    switch (GetFlag()) {
    case 0:
        Menu();
        break;
    case 1:
        clearInputBuffer();
        Ans_Link_List();
        break;
    case 2:
        clearInputBuffer();
        Ans_SequenceList();
        break;
    case 3:
        file_Meun_Init();
        Back_Meun();
        break;
    case 4:
        exit(EXIT_FAILURE);
        break;
    default:
        printf("输入错误，请重新输入\n");
        Back_Meun();
        break;
    }
    printf("按ENTER键继续...");
    getchar();
    system("cls");
}