#include <iostream>
#include <vector>

using namespace std;

struct LinkedList{
	int val;
	LinkedList* next;
};
LinkedList* makeList(vector<int>& v) {
	LinkedList* head = nullptr;
	LinkedList* before = nullptr;
	for(int i=0;i<v.size();i++) {
		LinkedList* cur = new LinkedList;
		cur->val = v[i];
		cur->next = nullptr;
		if(before) {
			before->next = cur;
		} else {
			head = cur;
		}
		before = cur;
	}
	return head;
}

LinkedList* deleteNode(LinkedList* head , int idx) {
	LinkedList* before = nullptr;
	LinkedList* cur = head;
	for(int i=0;i<idx;i++) {
		if(cur){
			before = cur;
			cur = cur->next;
		} else {
			return head;
		}
	}
	if(cur == nullptr) return head;
	if(before) {
		before->next = cur->next;
		delete cur;
		return head;
	} else {
		LinkedList* ret = cur->next;
		delete cur;
		return ret;
	}
			
}
LinkedList* insertNode(LinkedList* head, int idx, int val) {
	LinkedList* before = nullptr;
	LinkedList* cur = head;
	for(int i=0;i<idx;i++) {
		if(cur) {
			before = cur;
			cur = cur->next;
		} else {
			return head;
		}
	}
	if(cur == nullptr) return head;
	LinkedList* newone = new LinkedList;
	newone->val = val;
	if(before) {
		before->next = newone;
		newone->next = cur;
		return head;
	} else {
		newone->next = cur->next;
		delete cur;
		return newone;
	}
}
void print(LinkedList* head) {
	LinkedList* cur = head;
	while(cur) {
		cout << cur->val << ",";
		cur = cur->next;
	}
	cout << endl;
}

class Stack {
public : 
	Stack() {};
	~Stack() {};
	int pop() {
		if(head) {
			LinkedList* del = head;
			head = head->next;
			int ret = del->val;
			delete del;
			return ret;
		} else {
			return -1;
		}

	}
	void push(int val) {
		LinkedList* ins = new LinkedList;
		ins->val = val;
		ins->next = head;
		head = ins;
	}
private :
	int cnt = 0;
	LinkedList* head = nullptr;
};

int main() {
	vector<int> v{1,3,6,8,9,11};
	LinkedList* head = makeList(v);
	head = deleteNode(head, 6);
	print(head);
//	head = insertNode(head, 3, 99);
//	print(head);
	Stack st;
	st.push(1);
	st.push(2);
	st.push(3);
	cout << st.pop() << endl;
	cout << st.pop() << endl;
	cout << st.pop() << endl;
}
