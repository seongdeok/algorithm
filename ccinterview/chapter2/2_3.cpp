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

int main() {	
	LinkedList* head = nullptr;
	LinkedList* before = nullptr;
	for(int i=0;i<4;i++) {
		LinkedList* temp = new LinkedList;
		temp->val = i;
        temp->next = nullptr;
		if( head == nullptr){
		   head = temp;
           before = head;

		}else {
            before->next = temp;
            before = temp;
        }
    }
	print(head);
	del(head, 1);
	print(head);
    
			
}
