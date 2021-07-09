#include <iostream>

class Node {
	int data;
	Node* next = NULL;
public:
	Node(int n)
		:data(n) {}

	void creatLinkList(Node*& head, int val);
	void display(Node* head);
	void missing_num(Node* head);
	void insert(Node*& head, int after, int num);
	void delete_num(Node*& head, int x);
	void reverse_link(Node*& head);
	void recurciveDisplay(Node*& head);
	Node* recursiveReverse(Node*& head);
};

void Node::recurciveDisplay(Node*& head) {
	if (head != NULL) {
		std::cout << head->data << " ";
		recurciveDisplay(head->next);
	}
}

void Node::creatLinkList(Node*& head, int val) {
	Node* n = new Node(val);
	if (head == NULL) {
		head = n;
		return;
	}
	else {
		Node* temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = n;
	}
}

void Node::reverse_link(Node*& head) {
	Node* prev = NULL;
	Node* prev_plus = NULL;
	Node* curr = head;
	while (curr != NULL) {
		prev = prev_plus;
		prev_plus = curr;
		curr = curr->next;
		prev_plus->next = prev;
	}
	head = prev_plus;
}

Node* Node::recursiveReverse(Node*& head) {
	if (head == NULL || head->next == NULL) {
		return head;
	}
	Node* NewList = recursiveReverse(head->next);
	head->next->next = head;
	head->next = NULL;
	return NewList;
}

void Node::display(Node* head) {
	std::cout << std::endl;
	while (head != NULL)
	{
		std::cout << head->data << " ";
		head = head->next;
	}
}

void Node::missing_num(Node* head) {
	int x = head->data;
	int k = 1;
	while (head != NULL)
	{
		if (x != head->data) {
			std::cout << k++ << " st Missing Number is: " << x++ << std::endl;
		}
		else {
			head = head->next;
			x++;
		}

	}
}

void Node::insert(Node*& head, int after, int num) {
	Node* n = new Node(num);
	if (head == NULL) {
		head = n;
		return;
	}
	if (after == 0) {
		Node* temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = n;
		return;
	}
	Node* temp = head;
	while (temp->data != after)
	{
		temp = temp->next;
	}
	Node* temp2 = temp->next;
	temp->next = n;
	temp->next->next = temp2;
}

void Node::delete_num(Node*& head, int x) {
	Node* temp = head;
	while (temp->next->data != x)
	{
		temp = temp->next;
	}
	Node* to_delete = temp->next;
	Node* n = temp->next->next;
	temp->next = n;
	delete to_delete;
}

int main()
{
	Node* head = NULL;
	int x;
	std::cout << "How many items you want to add: ";
	std::cin >> x;
	std::cout << "\n\nPlease add " << x << " items with space: ";
	for (int i = 0; i < x; i++) {
		int y;
		std::cin >> y;
		head->creatLinkList(head, y);
	}
	std::cout << std::endl;
	/*head->display(head);
	head->missing_num(head);
	head->insert(head, 0, 6);
	head->display(head);
	head->delete_num(head, 3);
	head->display(head);*/
	//head->reverse_link(head);
	Node* rhead = head->recursiveReverse(head);
	head->recurciveDisplay(rhead);
}