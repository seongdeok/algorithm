#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

struct Node {
	int val;
	Node* left;
	Node* right;
};
// Minimum heap
class Heap {
public :
	int buff[128];
	int size = 0;
	
	Heap() {};
	~Heap() {};
	// append element at the end, and changing position with parent if it is less than parent recursively.
	void insert(int num) {
		buff[size++] = num;
		int idx = size -1;
		while( idx > 0 && buff[idx] < buff[parent(idx)] ){
			int temp = buff[idx];
			buff[idx] = buff[parent(idx)];
			buff[parent(idx)] = temp;
			idx = parent(idx);
		}
	}
	void del(int num) {
	}
	// change root with last element, and delete last element which was root
	// change parent with smallest child recursively.
	int pop() {
		buff[0] = buff[size-1];
		size--;
		int idx = 0;
		while(1) {
			int l = left(idx) >= size ? INT_MAX : buff[left(idx)];
			int r = right(idx) >= size ? INT_MAX : buff[right(idx)];
			if( l < buff[idx] && l < r ) {
				buff[left(idx)] = buff[idx];
				buff[idx] = l;
				idx = l;
			} else if(r < buff[idx] && r < l) {
				buff[right(idx)] = buff[idx];
				buff[idx] = r;
				idx = r;
			} else {
				break;
			}
		}
	}
	int left(int i) {
		return (i*2) + 1;
	}
	int right(int i) {
		return (i*2) + 2;
	}
	int parent(int i) {
		return (i -1) / 2;
	}
	int min() {
		return buff[0];
	}
};
int main() {
	Heap h;
	vector<int> v = { 9,7,5,3,1};
	for(int ele : v){ 
		h.insert(ele);
		for(int i = 0;i<h.size;i++)
			cout << h.buff[i] << ", ";
		cout << endl;
	}
	int sz = v.size();
	for(int i=0;i <sz;i++){
		cout << h.min() << endl;
		h.pop();
	}

}
