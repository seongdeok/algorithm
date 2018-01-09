#include <iostream>
#include <stack>

using namespace std;

class SortStack {
public :
	stack<int> sorted;
	stack<int> revsorted;
	SortStack() {};
	~SortStack() {};
	void push(int p) {
		if(!sorted.empty()){
			while(!sorted.empty() && sorted.top() >= p) {
				revsorted.push(sorted.top());
				sorted.pop();
			}
			revsorted.push(p);
			while(!sorted.empty() ) {
				revsorted.push(sorted.top());
				sorted.pop();
			}

		}else {
			while(!revsorted.empty() && revsorted.top() <= p) {
				sorted.push(revsorted.top());
				revsorted.pop();
			}
			sorted.push(p);
			while(!revsorted.empty()) {
				sorted.push(revsorted.top());
				revsorted.pop();
			}
		}
	}

	void pop() {
		while( !sorted.empty() ) {
			revsorted.push(sorted.top());
			sorted.pop();
		}
		revsorted.pop();
	}

	int peek() {
		while( !sorted.empty() ) {
			revsorted.push(sorted.top());
			sorted.pop();
		}
		return revsorted.top();
	}
	int size() {
		return sorted.size() + revsorted.size();
	}
};

int main() {
	SortStack s;
	int nums[7] = { 3,2,4,5,1,9,7};
	for(int a : nums)
		s.push(a);
	int sz = s.size();
	s.pop();
	s.push(29);
	s.pop();
	s.push(15);
	while(sz--) {
		cout << s.peek() << endl;
		s.pop();
	}	
}

