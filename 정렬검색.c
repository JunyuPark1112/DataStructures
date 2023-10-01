
/*
file name: ���İ˻�.c
date: 2023-05-31
written by: 1815356 ������
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


typedef struct Node {
    int data;
    struct Node* link;
} Node;




Node* createNode(int num) //��带 ����� ���
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = num;
    newNode->link = NULL;
    return newNode;
}


//���Ḯ��Ʈ�� ��带 �����ϴ� ���. ù���� ��ġ�� ����Ű�� ������ ��� ù ��带 ����Ű�� �ϰ�,
//���Ŀ��� �ڷ� ��� �ϳ��� �����ϸ鼭 �� ����� ��ũ �ʵ尡 �� ��带 ����Ű�� ��. ���� �� ��带 last �����Ͱ� ����Ű�� �̵�.
Node* addNode(Node* head, int num) {
    Node* temp = (Node*)malloc(sizeof(Node));
    Node* p;
    temp->data = num;
    temp->link = NULL;
    if (head == NULL) {
        head = temp;
        return head;
    }
    p = head;
    while (p->link != NULL) {
        p = p->link;
    }
    p->link = temp;
    return head;
}

//�� ����� data �ʵ� ���� ��ȯ 
void swapNode(Node* a, Node* b)
{
    int tem = a->data;
    a->data = b->data;
    b->data = tem;
}

//start ������ �ޱ�.. 
/* ���� �� ��� toswap���� ����, temp �����ͷ� ��� ��ȸ�ϸ� ��ȯ�� �� ���� ���Ͽ� �� ���� ��带 �߰��� ��� toswap�� data �ʵ� ��ȯ.
���� tempŽ���� �ߴ��ϰ� toswap�� �����ؾ� �ϹǷ� �ݺ��� ��Ż�Ͽ� ���� toswap�� temp�� Ž�� �����.
*/
Node* SelectionSort(Node* head)
{
    Node* toswap;
    Node* temp;
    toswap = head;

    while (toswap != NULL)
    {
        temp = toswap->link;
        while (temp != NULL) {
            if (toswap->data > temp->data) {
                swapNode(toswap, temp);
                continue;
            }
            temp = temp->link;
        }
        toswap = toswap->link;
    }
    return head;
}



void printlist(Node* head)
{
    Node* p;
    p = head;
    while (p != NULL)
    {
        printf("%d\n", p->data);
        p = p->link;
    }
}


//head �����Ϳ� last �����͸� �޾Ƽ� �߰��� �ִ� ��带 ����Ű�� ������ p ��ȯ
Node* middleNode(Node* head, Node* last)
{
  
    if (head == NULL) return NULL;

 
    Node* p1 = head;
    Node* p2 = head; 
    int c = 1;
    while (p1->link != last) {
        p1 = p1->link;
        c++;
    }c++;
   
    int mid =ceil(c/2);
    for (int i = 1; i < mid; i++) {
        p2 = p2->link;
    }

    return p2;
}

//������ ����� ������ ���� 
Node* lastNode(Node* head) {
    
    Node* last = head;
    while (last->link != NULL) {
        last = last->link;
 
    }last = last->link;

    return last;
}



Node* binarySearch(Node* head, int target)
{
    Node* start = head;
    Node* last = lastNode(head);


    while (last!=start) {
        Node* mid = middleNode(start, last);

        if (mid == NULL)
            return NULL;
        
        else if (mid->data == target) {
            return mid;
        }
       
        else if (mid->data < target)
            start = mid->link;
       
        else
            last = mid;
    }
    //target�� ���� ���
    return NULL;
}




int main()
{
    Node* head = NULL;
    Node* target = NULL;
    Node* ptr = NULL;
    int search = 0;
    

    for (int i = 0; i < 30; i++) {
        int num = 0;
        printf("������ �Է��ϼ���: ");
        scanf_s("%d", &num);
        head = addNode(head, num);
    }
    head = SelectionSort(head);
    printlist(head);

    printf("�� �� �˻��ұ��?: ");
    scanf_s("%d", &search);
    for (int i = 0; i < search; i++) {
        int n = 0;
        int count = 0;
        printf("� ������ ã�����?: ");
        scanf_s("%d", &n);
        target = binarySearch(head, n);
        if (target != NULL) {
            ptr = head;
            if (ptr == target) {
                //count = 1;
                printf("True\n");
                printf("1��°�� �ֽ��ϴ�.");
            }
            else if (ptr->link == target) {
                //count = 2;
                printf("True\n");
                printf("2��°�� �ֽ��ϴ�.");
            }
            else {
                while (ptr != target && ptr->link != target && ptr != target) {
                    //count = 2;
                    ptr = ptr->link;
                    count++;
                }
                printf("True\n");
                printf("%d��°�� �ֽ��ϴ�.", count + 2);

            }   
        }
        else {
            printf("False\n");
            printf("No Result in List!");
        }
    }

}


