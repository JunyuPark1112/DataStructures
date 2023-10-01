
/*
file name: 스택연산(2).c
date: 2023-06-01
written by: 1815356 박준유
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct stackNode {  //리스트 노드 구조 설정
	int data;
	struct stackNode* link;
}stackNode;

typedef struct Stack {  //공백 연결 스택 생성: Stack 
	stackNode* top;
}Stack;

void init(Stack* list) {
	list->top = NULL;
}

int isEmpty(Stack* list) {
	if (list->top == NULL) {
		return 1;
	}
	else
		return 0;
}

void push(Stack* list, int data) {
	stackNode* temp;
	temp = (stackNode*)malloc(sizeof(stackNode));
	temp->data = data;
	temp->link = list->top;
	list->top = temp;
}

int  pop(Stack*list) {
	stackNode* temp;
	int data;
	temp = list->top;
	if (temp == NULL) {
		printf("Stack is empty\n");
		exit(1);
	}
	else {
		data = temp->data;
		list->top = temp->link;
		free(temp);
		return data;
	}
}

int peek(Stack* list) {
	int data;
	if (list == NULL) {
		printf("Stack is empty\n");
		exit(1);
	}
	else {
		data = list->top->data;
		return data;
	}
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
	char tmp[100];
	int intval;
	int i, count = 0;
	for (i = 0; num[i] != ' '; i++) {
		tmp[i] = num[i];
	}
	tmp[i] = '\0';
	intval = atoi(tmp);
	count = *index;
	*index = count + i;
	return intval;
}


void infix2postfix(char* ix, char* px) {
	Stack s;
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
		else if (*ix >= '0' && *ix <= '9') {
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
	char ch; Stack s;
	int op1, op2, num = 0;
	init(&s);

	for (int j = 0; exp[j] != '\0'; j++) {
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
	char postfix[100];
	char infix[100] = "2*(10+15*3-5)+((30/3-(4/2)*3)+8)+6";
	infix2postfix(infix, postfix);
	int answer = post_evaluation(postfix);
	printf("%d", answer);
}


