#pragma once
#include <iostream>

struct Node {
	int data;
	Node* next;
};
typedef Node* node;
struct LinkedList {
	node Head;
	node Tail;
};

/// ==========================================================================
/// Khởi tạo List và Node thuộc List

void createList(LinkedList& a) {
	a.Head = NULL;
	a.Tail = NULL;
}
node createNode(int x) {
	node tmp = new Node();
	tmp->data = x;
	tmp->next = NULL;
	return tmp;
}
/// Thao tác truy vấn với dữ liệu trên List
void printList(LinkedList a) {
	node temp = a.Head;
	while (temp != NULL) {
		std::cout << temp->data << " ";
		temp = temp->next;
	}
	std::cout << std::endl;
}
int lengthList(LinkedList a) {
	int count = 0;
	node tmp = a.Head;
	while (tmp != NULL) {
		count++;
		tmp = tmp->next;
	}
	return count;
}
bool isEmpty(LinkedList a) {
	return a.Head == NULL;
}
/// ==========================================================================
/// Thao tác thêm Node cho List
void insertFirst(LinkedList& a, int x) {
	if (a.Head == NULL) {
		node tmp = createNode(x);
		a.Head = tmp;
		a.Tail = tmp;
	}
	else {
		node tmp = createNode(x);
		tmp->next = a.Head;
		a.Head = tmp;
	}
}
void insertLast(LinkedList& a, int x) {
	if (a.Head == NULL) {
		node tmp = createNode(x);
		a.Head = tmp;
		a.Tail = tmp;
	}
	else {
		node tmp = createNode(x);
		a.Tail->next = tmp;
		a.Tail = tmp;
	}
}
void insertN(LinkedList& a, int x, int n) {
	int _lengthList = lengthList(a);
	if (n < 0 || n > _lengthList) {
		return;
	}
	if (n == 0) {
		insertFirst(a, x);
	}
	else if (n == _lengthList) {
		insertLast(a, x);
	}
	else {
		int count = 0;
		node tmp = a.Head;
		while (count < n - 1) {
			count++;
			tmp = tmp->next;
		}
		node tmp2 = createNode(x);
		tmp2->next = (tmp->next);
		tmp->next = tmp2;
	}

}
/// Thao tác xóa Node trên List
void deleteFirst(LinkedList& a) {
	if (a.Head == NULL) return;
	node tmp = a.Head->next;
	delete a.Head;
	a.Head = tmp;
}
void deleteLast(LinkedList& a) {
	if (a.Head == NULL) return;
	node tmp = a.Head;
	while (tmp->next != a.Tail) {
		tmp = tmp->next;
	}
	delete a.Tail;
	a.Tail = tmp;
	tmp->next = NULL;
}
void deleteN(LinkedList& a, int n) {
	int _lengthList = lengthList(a);
	if (n < 0 || n >= _lengthList) return;
	if (n == 0) {
		deleteFirst(a);
		return;
	}
	if (n == _lengthList) {
		deleteLast(a);
		return;
	}
	int count = 0;
	node tmp = a.Head;
	while (count < n - 2) {
		tmp = tmp->next;
		count++;
	}
	node tmp2 = tmp->next;
	tmp->next = tmp2->next;
	delete tmp2;
}
