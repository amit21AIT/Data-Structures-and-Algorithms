#include <iostream>
using namespace std;
#define MAX 100

template <class T> 
class stack{
	T data[MAX];
	int stackPointer;
public:
	stack(){
		stackPointer = -1;
	}

	
	void push(T value){
		if(stackPointer==MAX)
			cout<<"Stack is full\n";
			
		else {
			data[++stackPointer] = value;
			cout<<value<<" was inserted\n";
		}
	}	
	
	void top(){
		if(stackPointer==-1)
			cout<<"Stack is empty\n";
			
		else 
			cout<<"The element at the top is "<<data[stackPointer]<<endl;
	}
	
	void pop(){
		if(stackPointer==-1)
			cout<<"Stack is empty\n";
			
		else {
			cout<<"Deleted element is "<<data[stackPointer]<<endl;
			stackPointer--;		
		}			
	}
	
	int size(){
		return stackPointer+1;
	}

		
};

int main()
{
	stack <int> s;
	s.push(100);
	s.push(200);
	cout<<"Size of stack is "<<s.size()<<endl;
	s.top();
	s.pop();
}
