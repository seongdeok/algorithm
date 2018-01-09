#include <iostream>

using namespace std;

class Stack {
public :
	Stack() {
		array = new int[32];
		ptr = 0;
	};
	~Stack() {
		delete array;
	};
	void push(int val) {
		array[ptr++] = val;	
	}
	int pop() {
		return array[ptr--];
	}
	void print() {
		for(int i=0;i<ptr;i++)
			cout << array[i] << " , ";
		cout << endl;
	}

private :
	int* array;
	int ptr;
};

int main() {
	Stack s;
	s.push(1);
	s.push(3);
	s.push(5);
	s.pop();
	s.push(8);
	s.print();
}

