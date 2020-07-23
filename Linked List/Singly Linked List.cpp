#include <bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node *next;
	Node(int val)
	{
		data = val;
		next = NULL;
	}
	Node()
	{
		next = NULL;
	}
};

class SinglyLL{
public:
	Node *head;
	SinglyLL()
	{
		head = NULL;
	}
	void insert(int val)
	{
		if(!head)
			head =  new Node(val);
		else 
		{
			Node *iterator = head;
			
			while(iterator->next)
				iterator = iterator->next;
				
			iterator->next = new Node(val);
		
		}
		
	}
	
	bool search(int val)
	{
		Node *iterator = head;
		while(iterator)
		{
			if(iterator->data == val)
				return true;
			iterator = iterator->next;
		}
		return false;
	}
	
	void erase (int val){
		
		if( head && head->data == val)
		{
			Node *temp = head;
			head = head->next;
			delete temp;
		}
		else
		{
			Node *iterator = head;
			while(iterator->next)
			{
				if(iterator->next->data == val)
				{
					Node *temp = iterator->next;
					iterator->next = iterator->next->next;
					delete temp;
					return;
				}
				iterator = iterator->next;
			}
		}
		
	}
	
	
	void printLL()
	{
		Node *iterator = head;
		cout<<"The elements in the linked list are : ";
		while(iterator)
		{
			cout<<iterator->data<<" ";
			iterator = iterator->next;
		}
		cout<<endl;
	}
	
	
	
};

int main(){
	
	SinglyLL list;
	list.insert(10);
	list.insert(20);
	list.insert(49);
	list.insert(23);
	list.printLL();
	list.erase(20);
	list.printLL();
	if(list.search(20))
		cout<<"20 found in the linked list\n";
	if(list.search(23))
		cout<<"23 found in the linked list\n";
	
}
