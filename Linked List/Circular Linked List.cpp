#include <bits/stdc++.h>
using namespace std;
// Basic implementation
class Node{
public:
	int data;
	Node *next;
	Node(int val){
		data = val;
		next = NULL;
	}
};

class CircularLL{
public:
	Node *head;
	
	CircularLL(){
		head = NULL;
	}
	
	void insert(int val){
		if(!head)
		{
			head = new Node(val);
			head->next = head;
			
		}
		else
		{
			Node *iterator = head;
			while(iterator->next != head)
				iterator = iterator->next;
			Node *newNode = new Node(val);
			newNode->next = head;
			iterator->next = newNode;
		}
	}
	
	void deleteNode(int pos)
	{
	 	if(pos == 0)
	 	{
	 		if(head->next == head)
	 		{
	 			head = NULL;
				 return;	
			}
	 		Node *iterator = head;
			while(iterator->next!=head)
			 	iterator = iterator->next;
			iterator->next = head->next;
			head = head->next;
			 	
		}
		else
		{
			Node *iterator = head;
			for(int i  = 0 ; i < pos-1 ; i++)
			iterator = iterator->next;
			
			if(iterator->next->next == head)
			{
				Node *temp = iterator->next;
				iterator->next = head;
				delete temp;
			}
			else
			{
				Node *temp = iterator->next;
				iterator->next = temp->next;
				delete temp;
			}
			
			
		}
	}
	
	void search(int val){
		Node *iterator = head;
		while(iterator->next != head)
		{
			if(iterator->data == val)
			{
				cout<<val<<" found in the linked list\n";
				return;
			}
			iterator = iterator->next;
		}
		cout<<val<<" not found in the linked list\n";
	}
	
	void print(){
		if(!head)
			return;
		Node *iterator = head;
		
		while(iterator->next != head){
			cout<<iterator->data<<" ";
			iterator = iterator->next;
		}
		cout<<iterator->data<<" ";
		cout<<endl;
	}
	
};

int main()
{
	CircularLL cll;
	cll.insert(10);
	cll.insert(20);
	cll.insert(30);
	cll.insert(90);
	cll.print();
	cll.deleteNode(90);
	cll.print();
	cll.search(10);
}
