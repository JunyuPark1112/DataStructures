
/*
file name: 스택연산(1).c
date: 2023-06-01
written by: 1815356 박준유
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define STACK_SIZE 100

typedef struct {
	char data[STACK_SIZE];
	int index;
}StackType;

void init(StackType* s) {
	s->index = -1;
}

int isFull(StackType* s) {
	if (s->index >= STACK_SIZE - 1) {
		return 1;
	}
	else return 0;
}

int isEmpty(StackType*s) {
	if (s->index == -1)
		return 1;
	else return 0;
}

void push(StackType *s, char item) {
	if (isFull(s)){
		printf("Stack is full\n");
		return;
	}
	s->data[++(s->index)] = item;
}

char pop(StackType *s) {
	if (isEmpty(s)){
		printf("Stack is empty\n");
		exit(1);
	}
	else return s->data[(s->index)--];
}


char peek(StackType*s) {
	if (isEmpty(s)) {
		printf("Stack is empty\n");
		exit(1);
	}
	else return s->data[s->index];
}

int prec(char ch) {
	switch (ch) {
	case'(': case')':return 0;
	case'+': case'-': return 1;
	case '*': case'/': return 2;
	}
	return -1;
}


int val2int(char* num, int* index) {
	char tmp[STACK_SIZE];
	int intval;
	int i, count=0;
	for (i=0; num[i] != ' '; i++) {
		tmp[i] = num[i];
	}
	tmp[i] = '\0';
	intval = atoi(tmp);
	count = *index;
	*index = count + i;
	return intval;
}



void infix2postfix(char* ix, char* px) {
	StackType s;
	init(&s);
	while (*ix != '\0') {
		if (*ix == '(') {
			push(&s, *ix);
			ix++;
		}// infix 가 끝날때까지 ~ 만약 '('만난 경우 stack 넣고 다음 문자로 
		else if (*ix == ')') {
			while (peek(&s) != '(') {
				*px++ = pop(&s);
				*px++ = ' ';
			}
			pop(&s); // ) 제거
			ix++;
		}
		else if (*ix >='0'&&*ix<='9') {
			while (*ix >= '0' && *ix <= '9') {
				*px++ = *ix++;
			}
			*px++ = ' ';
		}
		else if (*ix == '+' || *ix == '-' || *ix == '*' || *ix == '/') {
			while (!isEmpty(&s) && (prec(*ix) <= prec(peek(&s)))) {
				*px++ = pop(&s);
				*px++ = ' ';
			}
			push(&s, *ix);
			ix++;
		}
		else
			ix++;

	}
	while (!isEmpty(&s)) {
		*px++ = pop(&s);
		*px++ = ' ';
	}
	px--;
	*px = '\0';  //연산자 삽입 후 함께 삽입된 공백 삭제
} 


int post_evaluation(char exp[]) {
	char ch; StackType s;
	int op1, op2, num = 0;
	init(&s);

	for (int j = 0; exp[j]!='\0'; j++) {
		if (exp[j] == ' ')
			j++;
		ch = exp[j];
		if (ch != '+' && ch != '-' && ch != '*' && ch != '/') {
			num = val2int(&exp[j], &j);
			push(&s, num);
		}
		else {
			op2 = pop(&s); op1 = pop(&s);
			switch (ch) {
			case'+': push(&s, op1 + op2); break;
			case'-': push(&s, op1 - op2); break;
			case'*': push(&s, op1 * op2); break;
			case'/': push(&s, op1 / op2); break;
			}
		}
	}
	return pop(&s);
}



main() {
	char postfix[STACK_SIZE];
	char infix[STACK_SIZE] = "(3*(20+10))-(20/5+(4*2)/2)+8";
	infix2postfix(infix, postfix); 
	int answer= post_evaluation(postfix);
	printf("%d",answer);
}









