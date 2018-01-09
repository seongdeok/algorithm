#include <iostream>
#include <algorithm>

using namespace std;

class Stack {
public :
	Stack() {
		array = new int[32];
		mini = new int[32];
		ptr = 0;
	};
	~Stack() {
		delete array;
	};
	void push(int val) {
		if(ptr >= 31)
			return;
		array[ptr] = val;
		if(ptr == 0)
			mini[ptr] = val;
		else
			mini[ptr] = min( mini[ptr -1] , val);
		ptr++;
	}
	int pop() {
		if(ptr == 0)	
			return -1;
		return array[ptr--];
	}
	void print() {
		for(int i=0;i<ptr;i++)
			cout << array[i] << " , ";
		cout << endl;
	}
	int getMin() {
		if(ptr == 0)	
			return -1;
		return mini[ptr-1];
	}

private :
	int* array;
	int* mini;
	int ptr;
};

int main() {
	Stack s;
	s.push(4);
	cout << s.getMin() << endl;
	s.push(3);
	cout << s.getMin() << endl;
	s.push(1);
	cout << s.getMin() << endl;
	s.pop();
	cout << s.getMin() << endl;
	s.push(8);
	cout << s.getMin() << endl;
	s.print();
}

