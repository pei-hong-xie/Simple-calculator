#ifndef __SequenceList_H
#define __SequenceList_H


#define extern MAX_SIZE 100

typedef struct {
	double* top;
	double* base;
	int stacksize;
} Stack_Se;

int InitStack_SequenceList(Stack_Se* s);
int push_SequenceList(Stack_Se* s, double e);
int pop_SequenceList(Stack_Se* s);
double GetTop_SequenceList(Stack_Se s);
void Delete_SequenceList(Stack_Se* s);
double Computer_SequenceList();
void Ans_SequenceList();
#endif 
