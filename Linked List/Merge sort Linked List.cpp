#include <bits/stdc++.h>
using namespace std;
class Node {
public:
	int data;
	Node *next;
	Node(int val){
		data = val;
		next = NULL;
	}
};

void print(Node *head)
{
	while(head)
	{
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
	
}

void splitLinkedList(Node** leftHalf , Node ** rightHalf , Node *head)
{
	Node * slowptr = head , *fastptr = head->next;
	while(fastptr)
	{
		fastptr = fastptr->next;
		if(fastptr)
		{			
			slowptr = slowptr->next;
			fastptr = fastptr->next;
		}
	}
	*leftHalf = head;
	*rightHalf = slowptr->next;
	slowptr->next = NULL;
	
}

Node * merge(Node *leftHalf , Node *rightHalf)
{
	if(!leftHalf)
		return rightHalf;
	if(!rightHalf)
		return leftHalf;
	
	if(leftHalf->data <= rightHalf->data)
	{
		Node *head = leftHalf;
		head->next = merge(leftHalf->next , rightHalf);
		return head;
	}
	else 
	{
		Node *head = rightHalf;
		head->next = merge(leftHalf , rightHalf->next);
		return head;
	}
	
}

void mergeSortLL(Node **headRef){
	Node *head = *headRef;
	if(!head || !head->next)
		return;
		
	Node *leftHalf , *rightHalf;
	splitLinkedList(&leftHalf , &rightHalf , head);
	
	mergeSortLL(&leftHalf);
	mergeSortLL(&rightHalf);
	
	*headRef = merge(leftHalf,rightHalf);

}

int main()
{
	Node *head ;
	head = new Node(20);
	head->next = new Node(12);
	head->next->next = new Node(24);
	head->next->next->next = new Node(11);
	cout<<"Linked List before sorting : ";
	print(head);
	mergeSortLL(&head);
	cout<<"Linked List after sorting : ";
	print(head);
}




