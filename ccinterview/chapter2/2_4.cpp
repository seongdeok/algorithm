#include <iostream>
#include <vector>

using namespace std;
struct LinkedList{
	LinkedList* next;
	int val;
};

void del(LinkedList* head, int idx) {
    LinkedList* temp = head;
    while(idx--) temp = temp->next;
    if(temp == nullptr)
        return;
    LinkedList* target = temp->next;
    temp->next = target->next;
    delete target;
}
void print(LinkedList* head) {
    LinkedList* temp = head;
    while(temp != nullptr) {
        cout << temp->val << " , ";
        temp = temp->next;
    }
    cout << endl;
}
LinkedList* insert(LinkedList* head, int idx, LinkedList* target) {
	LinkedList* temp = head;
	LinkedList* before = nullptr;
	while(idx--) {
		if(temp == nullptr)
			return head;
		before = temp;
		temp = before->next;
	}
	if(before == nullptr) {
		target->next = head;
		return target;
	} else {
		target->next = temp;
		before->next = target;
		return head;
	}
}
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

int main() {	
	LinkedList* head = nullptr;
	vector<int> v { 3,5,8,5,10,2,1};
	head = makeList(v);

	print(head);
	LinkedList* temp = head;
	LinkedList* before = nullptr;
	int parti = 5;
	while(temp != nullptr) {
		if(temp->val < parti && temp != head){
			LinkedList* next = temp->next;
			if(before != nullptr)
				before->next = next;
			head = insert(head, 0, temp);
			temp = next;
		} else {
			before = temp;
			temp = temp->next;
		}
	}
	print(head);
    
			
}
