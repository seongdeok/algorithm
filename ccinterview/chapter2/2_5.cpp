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
LinkedList* revSum(LinkedList* h1, LinkedList* h2) {
	LinkedList* head = nullptr;
	LinkedList* before = nullptr;
	LinkedList* temp1 = h1;
	LinkedList* temp2 = h2;
	int add = 0;
	while(temp1 != nullptr || temp2 != nullptr) {
		LinkedList* cur = new LinkedList;
		cur->val = (temp1 == nullptr ? 0 : temp1->val) + (temp2 == nullptr ? 0 : temp2->val) + add;
		if( cur->val >= 10){
			add = 1;
			cur->val -= 10;
		} else
			add = 0;

		cur->next = nullptr;
		if(before) {
			before->next = cur;
		} else {
			before = cur;
			head = cur;
		}
		before = cur;
		if(temp1)
			temp1 = temp1->next;
		if(temp2)
			temp2 = temp2->next;
	}
	return head;
}
void print(LinkedList* head) {
	LinkedList* temp = head;
	while(temp) {
		cout << temp->val << ",";
		temp = temp->next;
	}
}
LinkedList* reverse(LinkedList* head) {
	LinkedList* cur = head->next;
	LinkedList* h1 = head;
	LinkedList* before = head;
	while(cur) {
		before->next = cur->next;
		cur->next = h1;
		h1 = cur;
		cur = before->next;
	}
	return h1;
}
		
int main() {
	vector<int> v1 { 7,1,6};
	vector<int> v2 { 5,9,2};
	LinkedList* head1 = makeList(v1);
	LinkedList* head2 = makeList(v2);
	LinkedList* res = revSum(head1,head2);
	print(res);
	print(reverse(res));
}
