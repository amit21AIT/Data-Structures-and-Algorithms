#include <iostream>
using namespace std;

template <class T>

class node{
public:
	
	T data;
	node * next;

	node(T val){
		data = val;
		next = NULL;
	}
};
template <class T>

class stack{
	node <T> *head;
	int sz = 0;
	
public:
	
	stack(){
		head = NULL;
		sz = 0;
	}
	
	void push(T val){
		
		if(head == NULL)
			head = new node<T>(val);
		
		else {
			
			node <T>*newNode = new node<T>(val);
			newNode->next = head;
			head = newNode;
		}
		sz++;
		cout<<"Element "<<val<<" inserted\n";
	}
	
	void pop(){
		if(head == NULL)
			cout<<"Stack is empty\n";
		else {
			
			cout<<"Deleted element is "<<head->data<<endl;
			head = head->next;
			sz--;
		}
	}
	
	void top(){
		if(head == NULL)
			cout<<"Stack is empty\n";
		else
			cout<<"The top element is "<<head->data<<endl;
	}
	
	int size(){
		return sz;
	}
	
};

int main()
{
	stack <int> s;
	s.push(200);
	s.push(100);
	cout<<"Size of stack is "<<s.size()<<endl;
	s.pop();
	s.top();
}
