#include <bits/stdc++.h>
using namespace std;
// funtion implementation only
class Node {
public:
	int data;
	Node *next;
	Node(int val){
		data = val;
		next = NULL;
	}
};

Node *reverseListIterative(Node *head)
{
	Node *prev = NULL , *curr = head;
	while(curr)
	{
		Node *nextNode = curr->next;
		curr->next = prev;
		prev = curr;
		curr = nextNode;
	}
	return prev;
}

Node *reverseListRecursive(Node *head)
{
	if(!head || !head->next)
		return head;
	Node *newHead = reverseListRecursive(head->next);
	head->next->next = head;
	head->next = NULL;
	return newHead;	
	
}


