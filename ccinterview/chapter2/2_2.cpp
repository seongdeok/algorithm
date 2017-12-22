#include <iostream>
#include <vector>
using namespace std;

struct LinkedList {
	int val;
	LinkedList* next;
};

LinkedList* makeList(vector<int>& v) {
	LinkedList* head = nullptr;
	LinkedList* before = nullptr;
	for(auto elem : v){
		LinkedList* cur = new LinkedList;
		cur->val = elem;
		cur->next = nullptr;
		if(head){
			before->next = cur;
			before = cur;
		} else {
			head = cur;
			before = cur;
		}
	}
	return head;
}

LinkedList* getKth(LinkedList* head, int kth) {
	int cnt = 0;
	LinkedList* temp = head;
	while(temp != nullptr) {
		cnt++;
		temp = temp->next;
	}
	temp = head;
	cnt -= kth - 1;
	while(cnt-- > 0) {
		temp = temp->next;
	}
	return temp;
}
int main() {
	vector<int> v { 1,2,3,4,5,6,7,8,9,10};
	LinkedList* head = makeList(v);
	LinkedList* kth = getKth(head, 3);
	cout << kth->val;
}	
