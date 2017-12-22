#include <iostream>
#include <vector>
using namespace std;

struct LinkedList{
	int val;
	LinkedList* next;
};
void removeDuplicate(LinkedList* list) {
	LinkedList* from = list;
	while(from != nullptr) {
		LinkedList* before = from;
		LinkedList* cur = from->next;
		int val = from->val;
		while(cur != nullptr){
			if(cur->val == val){
				LinkedList* next = cur->next;
				delete cur;
				before->next = next;
				cur = before->next;
			} else {
				before = before->next;
				cur = before->next;
			}
		}
		from = from->next;
	}
}
void print(LinkedList* head){
	LinkedList* cur = head;
	while(cur != nullptr) {
		cout << cur->val << " ";
		cur = cur->next;
	}
}

int main() {
	vector<int> v { 3,5,5,2,4,4,1,7,9,1,1};
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
	print(head);
	printf("Linked list has made\n");

	removeDuplicate(head);
	print(head);
}


