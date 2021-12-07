#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node(int data)
	{
		this->data = data;
		next = NULL;
	}
};

Node* takingInput()
{
	int data;
	cin >> data;
	Node* head = NULL;
	Node* tail = NULL;
	while (data != -1)
	{
		Node* newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = tail->next;
		}
		cin >> data;
	}
	return head;
}

void print(Node* head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
}

Node* linkedListIterative(Node* head)
{
	if (head == NULL)
		return head;
	Node* copy = head;
	Node* curr = copy;
	Node* nextTerm = NULL;
	Node* prev = NULL;
	while (curr != NULL )
	{
		nextTerm = curr->next;
		curr->next = prev;
		prev = curr;

	}
	return prev;
}

int main()
{
	Node* head = takingInput();
		print(head);
		head = linkedListIterative(head);
		print(head);
	return 0;
}