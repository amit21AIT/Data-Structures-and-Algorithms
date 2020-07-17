#include <bits/stdc++.h>
using namespace std;
#define MAX 100

template <class T>

class circularQueue{
	T data[MAX];
	int rear , front , sz;
public:	
	circularQueue(){
		rear = front = -1;
		sz = 0;
	}
	
	void enqueue(T val){
		
		 if((front == 0 && rear == MAX-1) || rear == (front-1)%(MAX-1))
		{
			cout<<"Queue is full\n";
			return ;
		}
		else if(front == -1)
		{
			rear = front = 0;
			data[rear] = val;
		}
		else if(rear == MAX-1 && front!=0)
		{	
			rear = 0;
			data[rear] = val;
		}
		else
			data[++rear] = val;
		cout<<"Element "<<val<<" Inserted\n";
		sz++;
	}
	
	void dequeue(){
		if(front == -1)
		{
			cout<<"Queue is empty\n";
			return ;
		}
		int val = data[front];
		
		if(rear == front){
			front = rear = -1;
		}
		else if(front==MAX-1)
			front = 0;
		else 
			front++;
			sz--;
		cout<<"Element "<<val<<" Deleted\n";
	}
	
	int size(){
		return sz;
	}
};

int main()
{
	circularQueue <int> q;
	q.enqueue(100);
	q.enqueue(200);
	cout<<"Size of the queue is "<<q.size()<<endl;
	q.dequeue();
}
