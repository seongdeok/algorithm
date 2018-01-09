#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
public : 
	stack<int> newone;
	stack<int> oldone;
	MyQueue() {}
	~MyQueue() {};
	void add(int t){
		if( newone.empty()){
			while(!oldone.empty()) {
				newone.push(oldone.top());
				oldone.pop();
			}
		}
		newone.push(t);
	}
	int peek() {
		if( !newone.empty() ) {
			while(!newone.empty()) {
				oldone.push(newone.top());
				newone.pop();
			}
		}
		return oldone.top();
	}
	void remove() {
		peek();
		oldone.pop();
	}
};

int main() {
	MyQueue s;
	s.add(1);
	s.add(2);
	s.add(3);
	s.remove();
	cout << s.peek()<< endl;

}
