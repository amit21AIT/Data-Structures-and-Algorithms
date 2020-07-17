#include <iostream>
using namespace std;

template <class T>
class Node {
public:
	T data;
	Node<T> *next;
	Node(T val){
		data = val;
		next = NULL;
	}
	
};

template <class T>
class queue{
	Node<T> *head , *tail;
	int sz;
public:
	queue(){
		head = tail = NULL;
		sz = 0;
	}
	
	void enqueue(T val){
		if(head == NULL)
		{
			head = new Node<T>(val);
			tail = head;
		}
		else 
		{
			tail->next = new Node<T>(val);
			tail = tail->next;
		}
		sz++;
		cout<<"Element "<<val<<" Inserted\n";
	}
	
	void dequeue(){
		
		if(head == NULL)
			cout<<"Queue is empty\n";
		else
		{
			sz--;
			cout<<"Element "<<head->data<<" deleted\n";
			head = head->next;
		}
		
	}
	void front(){
		if(head == NULL)
			cout<<"The queue is empty\n";
		else 
			cout<<"The element at the front is "<<head->data<<endl;
	}
	int size(){
		return sz;
	}
	
};

int main()
{
	queue <int> q;
	q.enqueue(100);
	q.enqueue(200);
	cout<<"The size of the queue is "<<q.size()<<endl;
	q.front();
	q.dequeue();
}
