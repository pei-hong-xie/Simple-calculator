#include <stdio.h>
#include <stdlib.h>
#include <SequenceList.h>
#include <cmp.h>
#include<Menu.h>
#define  MAX_SIZE 100

int InitStack_SequenceList(Stack_Se* s) {
	s->base = (double*)malloc(MAX_SIZE * sizeof(double));
	if (!s->base)
		return 0;
	s->top = s->base;
	s->stacksize = MAX_SIZE;
	return 1;
}

int push_SequenceList(Stack_Se* s, double e) {
	if (s->top - s->base == s->stacksize)
		return 0;
	*(s->top++) = e;
	return 1;
}

int pop_SequenceList(Stack_Se* s) {
	if (s->top == s->base)
		return 0;
	--(s->top);
	return 1;
}

double GetTop_SequenceList(Stack_Se s) {
	if (s.top != s.base)
		return *(s.top - 1);
	else {
		printf("计算式错误！！！\n");
		exit(-1);
	}
}

void Delete_SequenceList(Stack_Se* s) {
	free(s->base);
}



//顺序表计算
double Computer_SequenceList() {
	char ch;
	Stack_Se num, ope;
	InitStack_SequenceList(&num);
	InitStack_SequenceList(&ope);
	push_SequenceList(&ope, '=');

	int q = 1;
	double e, a, b, s;
	char c;

	ch = getchar();
	while (ch != '=' || GetTop_SequenceList(ope) != '=') {
		if (ch == '(') {
			q = 0;
		}
		if (ch == ')') {
			q = 1;
		}

		if (In(ch) == 0) {
			switch (cmp(GetTop_SequenceList(ope), ch)) {
			case '<':
				push_SequenceList(&ope, ch);
				scanf("%c", &ch);
				break;
			case '>':
				c = GetTop_SequenceList(ope);
				pop_SequenceList(&ope);
				a = GetTop_SequenceList(num);
				pop_SequenceList(&num);
				b = GetTop_SequenceList(num);
				pop_SequenceList(&num);
				push_SequenceList(&num, count(a, c, b));
				break;
			case '=':
				pop_SequenceList(&ope);
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
			push_SequenceList(&num, e);
		}
		if (ch == '=' && q == 0) {
			printf("计算式错误！！！\n");
			exit(-1);
		}
	}

	s = GetTop_SequenceList(num);
	pop_SequenceList(&ope);
	Delete_SequenceList(&num);
	Delete_SequenceList(&ope);
	return s;
}

void Ans_SequenceList(){
	printf("顺序栈实现:\n");
	remind();
	double ans1;
	ans1 = Computer_SequenceList();
	printf("%lf\n", ans1);
	Back_Meun();
}

