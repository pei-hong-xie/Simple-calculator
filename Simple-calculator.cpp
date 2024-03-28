#include<stdio.h>
#include<stdlib.h>
#include<Menu.h>
#include<string>
#include <SequenceList.h>
#include<LinkList.h>
#include <cmp.h>
int main() {
    Menu();
	while (1)
	{
		if (GetFlag()==0)
		{
			Menu();
		}else if(GetFlag() == 1){

			clearInputBuffer();
			Ans_Link_List();
		}
		if (GetFlag() == 2){
			clearInputBuffer();
			Ans_SequenceList();
		}
		else if (GetFlag() == 3) {
			break;
		}
		else if (GetFlag()<0|| GetFlag() >3) {
			printf("输入错误，请重新输入\n");
			Back_Meun();
		}

	}

    return 0;
}
