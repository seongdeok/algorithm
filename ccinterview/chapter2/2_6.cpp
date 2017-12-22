#include <vector>
#include <iostream>

using namespace std;
struct LinkedList {
	int val;
	LinkedList* next;
};


LinkedList* makeList(vector<int>& v, int idx) {
	if(idx >= v.size())
		return nullptr;
	LinkedList* cur = new LinkedList;
	cur->val = v[idx];
	cur->next = makeList(v, idx + 1);
	return cur;
}
LinkedList* cloneReverse(LinkedList* head) {
	LinkedList* temp = head;
	LinkedList* before = nullptr;
	LinkedList* cur;	
	while(temp) {
		cur = new LinkedList;
		cur->val = temp->val;
		cur->next = before;
		before = cur;	
		temp = temp->next;
	}
	return cur;
}

bool isPalindrome(LinkedList* head) {
	LinkedList* rev = cloneReverse(head);
	LinkedList* temp = head;
	LinkedList* temp1 = rev;
	while(temp) {
		if( temp->val != temp1->val)	
			return false;
		temp = temp->next;
		temp1 = temp1->next;
	}
	return true;
}
void print(LinkedList* head) {
	LinkedList* temp = head;
	while(temp) {
		cout << temp->val << ",";
		temp = temp->next;
	}
	cout << endl;
}

int main(){
	vector<int> v { 0,1,2,1,3};
	LinkedList* head = makeList(v, 0);
	LinkedList* rev = cloneReverse(head);
	print(head);
	print(rev);
	cout << isPalindrome(head) << endl;

}
