#include <iostream>
using namespace std;
#define MAX 100

template <class T>
class queue{
	T data[MAX];
	int front , rear;
public:
	queue(){
		rear = front = -1;
	}
	
	void enqueue(T val){
		if(rear == MAX)
			cout<<"Queue is full\n";
		else {
			data[++rear] = val;
			if(front==-1)
				front++;
			cout<<val<<" Inserted\n";
		}
	}
	
	void dequeue(){
		if(front==-1)
			cout<<"Queue is empty\n";
		else {
			cout<<"Element "<<data[front]<<" deleted\n";
			front++;
		}
		if(front>rear)
			front = rear = -1;
	}
	
	void Front(){
		if(front==-1)
			cout<<"Queue is empty\n";
		else 
			cout<<"The element at the front is "<<data[front]<<endl;
		
	}
	
	int size(){
		return rear-front+1;
	}
};

int main()
{
	queue <int> q;
	q.enqueue(100);
	q.enqueue(200);
	cout<<"The size of the queue is "<< q.size()<<endl;
	q.Front();
	q.dequeue();
}
