#include<stdio.h>
#include<stdlib.h>
//단일연결리스트 구조체 
typedef struct {
	int data;
	struct Node *next;
}Node;

Node *head;
//가장 앞 삽입
void addFront(Node *root, int data) {
	Node *node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = root->next;
	root->next = node;
}
//데이터 삭제
void removeFront(Node *root) {
	Node *front = root->next;
	root->next = front->next;
	free(front);
}
//메모리 할당 해제
void freeAll(Node *root) {
	Node *cur = head->next;
	while (cur != NULL) {
		Node *next = cur->next;
		free(cur);
		cur = next;
	}
}
//전체 연결리스트 출력
void showAll(Node *root) {
	Node *cur = head->next;
	while (cur != NULL) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
}

int main() {
	head = (Node*)malloc(sizeof(Node));
	/*
	Node *node1 = (Node*)malloc(sizeof(Node));
	node1->data = 1;
	Node *node2 = (Node*)malloc(sizeof(Node));
	node2->data = 2;
	head->next = node1;
	node1->next = node2;
	node2->next = NULL;
	Node *cur = head->next;
	while (cur != NULL) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
	*/

	head->next = NULL;
	addFront(head, 2);
	addFront(head, 1);
	addFront(head, 7);
	addFront(head, 9);
	addFront(head, 8);
	removeFront(head);
	showAll(head);
	freeAll(head);
	system("pause");
	return 0;
}