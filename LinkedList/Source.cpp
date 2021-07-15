#include <iostream>

class Node {
	int data;
	Node* next, * last;
public:
	Node* head;
	Node(int val = 0)
		:data(val) {
		head = next = last = NULL;
	}

	void createList() {
		std::cout << "Enter size of List: ";
		int x; std::cin >> x;
		while (x--)
		{
			int y; std::cin >> y;
			Node* n = new Node(y);
			if (!head) {
				head = last = n;
			}
			else {
				last->next = n;
				last = last->next;
			}
		}std::cout << std::endl;
	}
	void display(Node* h)
	{
		while (h)
		{
			std::cout << h->data << " ";
			h = h->next;
		}std::cout << std::endl;
	}
	void insertAtlast(int val) {
		Node* n = new Node(val);
		last->next = n;
		last = last->next;
	}
	void recDisplay(Node* h) {
		if (h) {
			std::cout << h->data << " ";
			recDisplay(h->next);
		}
	}
	void countNode(Node* h) {
		int x = 0;
		while (h)
		{
			x++;
			h = h->next;
		}
		std::cout << "No of Nodes are: " << x << std::endl;
	}
	int sum(Node* h) {
		if (!h->next)
		{
			return h->data;
		}
		return h->data + sum(h->next);
	}
	int max_ele(Node* h) {
		int max = INT_MIN;
		while (h)
		{
			max = (max > h->data) ? max : h->data;
			h = h->next;
		}
		return max;
	}
	bool search_Node(Node* h, int num) {
		if(!h){
			return false;
		}
		else if (h->data == num) {
			return true;
		}
		search_Node(h->next, num);
	}
	void insert_Node_pos(Node*& h, int val, int pos) {
		Node* n = new Node(val);
		if (!pos) {
			n->next = h;
			h = n;
		}
		else {
			Node* temp = h;
			while (--pos)
			{
				if (temp->next) {
					temp = temp->next;
				}
				else {
					std::cout << "Position out of range!!!\n";
					return;
				}
			}
			n->next = temp->next;
			temp->next = n;
		}
	}
	void deleteNode(int pos)
	{
		if (!pos) {
			Node* to_del = head;
			head = head->next;
			to_del->next = NULL;
			delete to_del;
		}
		else {
			Node* temp = head;
			while (--pos)
			{
				if (temp->next) {
					temp = temp->next;
				}
				else {
					std::cout << "No Node Present to delete at this pos!!\n";
					return;
				}
			}
			if (temp->next) {
				Node* to_del = temp->next;
				temp->next = to_del->next;
				delete to_del;
			}
			else {
				std::cout << "No Node Present to delete at this pos!!\n";
				return;
			}
		}
	}
	Node* insertAtBegining(Node* h, int x) {
		Node* n = new Node(x);
		n->next = h;
		h = n;
		return h;
	}
	Node* insertAtEnd(Node* head, int x) {
		Node* n = new Node(x);
		if (!head) {
			return n;
		}
		else {
			Node* temp = head;
			while (temp->next) {
				temp = temp->next;
			}
			temp->next = n;
			return head;
		}
	}
	bool is_sorted(Node*& h) {
		if (!h || !h->next) {
			return true;
		}
		else {
			return ((h->data < h->next->data) && is_sorted(h->next));
		}
	}
};

int main()
{
	Node n;
	n.createList();
	n.display(n.head);
	n.deleteNode(6);
	n.display(n.head);

	std::cin.get();
	return 0;
}