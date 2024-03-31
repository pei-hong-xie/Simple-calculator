#include <stdio.h>
#include <wchar.h>
#include <stdlib.h>
#include <string.h>
#include <cmp.h> // 包含比较函数的头文件
#include<LinkList.h> // 包含链表栈的头文件

char text_buffer[100];  // 用于存储读取的字符串

void Read_File(const char* filename) {
    FILE* file = fopen(filename, "r"); // 以只读模式打开文件
    if (file == NULL) {
        printf("无法打开文件 %s\n", filename);
        return;
    }

    while (fgets(text_buffer, sizeof(text_buffer), file) != NULL){
        // 删除换行符
        if (text_buffer[strlen(text_buffer) - 1] == '\n') {
            text_buffer[strlen(text_buffer) - 1] = '\0';
        }

        // 调用计算函数，传递字符字符串
        double result = computer_LinkList(text_buffer);

        printf("输入: %s\n", text_buffer);
        printf("结果: %lf\n", result);
    }
    fclose(file); // 关闭文件
}

