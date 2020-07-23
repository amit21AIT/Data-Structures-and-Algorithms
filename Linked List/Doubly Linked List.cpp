#include <bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node *next , *prev;
	Node(int val){
		data = val;
		next = prev = NULL;
	}
};
class DoublyLL{
public:
	Node *head;
	DoublyLL(){
		head = NULL;
	}
	void insert(int val)
	{
		if(!head){
			head = new Node(val);
		}
		else{
			Node *iterator = head;
			while(iterator->next)
				iterator = iterator->next;
			
			Node *newNode = new Node(val);
			newNode->prev = iterator;
			iterator->next = newNode;
			
		}
	}
	
	void print(){
		Node *iterator = head;
		while(iterator)
		{
			cout<<iterator->data<<" ";
			iterator = iterator->next;
		}
		cout<<endl;
	}
	
	void deleteNode(int val){
		
		if(head->data == val){
			Node *temp = head;
			head = head->next;
			if(head)
				head->prev = NULL;
			delete temp;
			
			return;
		}
			
		
		Node *iterator = head;
		while(iterator->next)
		{
			if(iterator->data == val)
			{
				Node *temp = iterator;
				iterator->prev->next = iterator->next;
				iterator->next->prev = iterator->prev;
				delete iterator;
				return;
			}
			iterator = iterator->next;
		}
		if(iterator->data == val)
		{
			iterator->prev->next = NULL;
			delete iterator;
		}
		
	}
	
	void search(int val){
		Node *iterator = head;
		while(iterator)
		{
			if(iterator->data == val)
			{
				cout<<val<<" found in linked list\n";
				return;
			}
			iterator = iterator->next;
		}
		cout<<val<<" not found in the linked list\n";
	}
};

int main()
{
	DoublyLL dll;
	dll.insert(10);
	dll.insert(20);
	dll.insert(30);
	dll.insert(90);
	dll.print();
	dll.deleteNode(90);
	dll.print();
	dll.search(10);
}
