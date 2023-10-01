
/*
file name: ���ǵ�����.c
date: 2023-05-23
written by: 1815356 ������
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>


typedef struct element {
	char name[10];
}element;

typedef struct Node {
		element data;
		struct Node* link;
} Node;


Node* insert_node(Node* head, element person) {
	Node* p = (Node*)malloc(sizeof(Node));

	p->data = person;
	if (head == NULL) {
		head = p;
		p->link = head;
	}
	else {
		p->link = head->link;
		head->link = p;
	}
	return head;
} //�տ������� �ֱ� ������ 13��° ������� �Է�


Node* set_delete_node(Node* head, int n) { //�����ϰ��� �ϴ� ����� �ٷ� �ڿ� ������ ��ġ 
	if (n == 1) {
		return head;
	}
	else {
		Node* p = head->link; // 1�� ����
		for (int i = 1; i < n - 1; i++) {
			p = p->link;
		}
		return p;
	}
}

int Random_Number(){
	int random = rand() % 15; //0~14���� ��������
	return random + 1; //1~15�� �����ϰ� ��ȯ
}

Node* delete_node(Node* head, Node* p) { 
	Node* k = NULL; //������ ��带 ����ų ������ k 
	k = p->link; //������ ��� ����Ű��, p�� �����ϴ� ����� �ٷ� �� ���
	p->link = k->link; //����
	

	if (k == head) { //������ ��尡 13���� ��� head ������Ʈ
		head = p;
	}
	printf("���� ���: ");
	printf("%s", k->data.name);
	printf("\n");
	free(k);
	return head;
}


void print_list(Node* head) {
	Node* p=NULL;
	if (head == NULL) return;
	p = head->link;
	do {
		printf("%s ->", p->data.name);
		p = p->link;
	} while (p != head);
	printf("%s", p->data.name);
}


int main() {
	Node* head = NULL;
	Node* ptr = NULL;
	srand(time(NULL));
	element data;
	int start_num = 0;

	strcpy(data.name,"15.Park");
	head = insert_node(head, data);

	strcpy(data.name, "14.Seo");
	head = insert_node(head, data);

	strcpy(data.name, "13.Yang");
	head = insert_node(head, data);

	strcpy(data.name,"12.Won");
	head = insert_node(head, data);

	strcpy(data.name, "11.Oh");
	head = insert_node(head, data);

	strcpy(data.name, "10.Bae");
	head = insert_node(head, data);
	
	strcpy(data.name, "09.Shin");
	head = insert_node(head, data);

	strcpy(data.name,"08.Song");
	head = insert_node(head, data);

	strcpy(data.name,"07.Na");
	head = insert_node(head, data);

	strcpy(data.name,"06.Ku");
	head = insert_node(head, data);

	strcpy(data.name,"05.Jung");
	head = insert_node(head, data);

	strcpy(data.name,"04.Yoon");
	head = insert_node(head, data);

	strcpy(data.name,"03.Choi");
	head = insert_node(head, data);
	
	strcpy(data.name,"02.Lee");
	head = insert_node(head, data);

	strcpy(data.name,"01.Kim");
	head = insert_node(head, data);
	

	start_num = Random_Number();
	ptr = set_delete_node(head, start_num); //start_num �ٷ� �� ��带 ptr�� ����Ŵ

	for (int i = 0; i <= 11; i++) {
		head = delete_node(head, ptr);
		ptr = ptr->link;
		ptr = ptr->link;
		printf("���� �����: ");
		print_list(head);
		printf("\n");
	}
	
	
	print_list(head);

	return 0;
}