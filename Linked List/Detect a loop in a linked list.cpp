#include <bits/stdc++.h>
using namespace std;
//Only function implementation
class Node {
public:
	int data;
	Node *next;
	Node(int val){
		data = val;
		next = NULL;
	}
};
// returns true if the linked List has a loop
bool detectLoop(Node *head)
{
	if(!head)
		return false;
	Node *slowptr = head;
	Node *fastprt = head;
	
	while(fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		
		if(slow == fast)
			return true;
	}
	
	return false;
	
}
// to  find the node value where the loop starts
Node* loopStartIndex(Node *head){
	Node *slowptr = head;
	Node *fastprt = head;
	
	while(fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		
		if(slow == fast)
			break;
	}
	
	if(slow != fast)
		return NULL;   // No loop
		
	fastptr = head;
	while(slowptr != fastptr)
	{
		slowptr = slowptr->next;
		fastptr = fastptr->next;
	}
	return slowptr;
	
}
