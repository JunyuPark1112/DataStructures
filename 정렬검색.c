
/*
file name: 정렬검색.c
date: 2023-05-31
written by: 1815356 박준유
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


typedef struct Node {
    int data;
    struct Node* link;
} Node;




Node* createNode(int num) //노드를 만드는 기능
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = num;
    newNode->link = NULL;
    return newNode;
}


//연결리스트에 노드를 연결하는 기능. 첫노드는 위치를 가리키는 포인터 모두 첫 노드를 가리키게 하고,
//이후에는 뒤로 노드 하나씩 연결하면서 전 노드의 링크 필드가 새 노드를 가리키게 함. 이후 새 노드를 last 포인터가 가리키게 이동.
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

//각 노드의 data 필드 내용 교환 
void swapNode(Node* a, Node* b)
{
    int tem = a->data;
    a->data = b->data;
    b->data = tem;
}

//start 포인터 받기.. 
/* 가장 앞 노드 toswap으로 고정, temp 포인터로 노드 순회하며 교환할 앞 노드와 비교하여 더 작은 노드를 발견한 경우 toswap과 data 필드 교환.
이후 temp탐색은 중단하고 toswap을 전진해야 하므로 반복문 이탈하여 다음 toswap과 temp로 탐색 재시작.
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


//head 포인터와 last 포인터를 받아서 중간에 있는 노드를 가리키는 포인터 p 반환
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

//마지막 노드의 포인터 리턴 
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
    //target이 없는 경우
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
        printf("정수를 입력하세요: ");
        scanf_s("%d", &num);
        head = addNode(head, num);
    }
    head = SelectionSort(head);
    printlist(head);

    printf("몇 번 검색할까요?: ");
    scanf_s("%d", &search);
    for (int i = 0; i < search; i++) {
        int n = 0;
        int count = 0;
        printf("어떤 정수를 찾을까요?: ");
        scanf_s("%d", &n);
        target = binarySearch(head, n);
        if (target != NULL) {
            ptr = head;
            if (ptr == target) {
                //count = 1;
                printf("True\n");
                printf("1번째에 있습니다.");
            }
            else if (ptr->link == target) {
                //count = 2;
                printf("True\n");
                printf("2번째에 있습니다.");
            }
            else {
                while (ptr != target && ptr->link != target && ptr != target) {
                    //count = 2;
                    ptr = ptr->link;
                    count++;
                }
                printf("True\n");
                printf("%d번째에 있습니다.", count + 2);

            }   
        }
        else {
            printf("False\n");
            printf("No Result in List!");
        }
    }

}


