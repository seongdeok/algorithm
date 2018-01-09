#include <iostream>
#include <vector>

using namespace std;
// index start from 0
#define LEFT(idx)   (idx * 2 + 1)
#define RIGHT(idx)  (idx * 2 + 2)
#define PARENT(idx) ((idx - 1) / 2)

void maxheapify(vector<int>& v, int index, int last_index) {
	if(index < 0)
		return;
	int swap_index = index;
	if( LEFT(index) <= last_index	&& v[LEFT(index)] > v[index])
		swap_index = LEFT(index);
	if( RIGHT(index) <= last_index && v[RIGHT(index)] > v[swap_index])
		swap_index = RIGHT(index);
	swap(v[index], v[swap_index]);
	maxheapify(v, index - 1, last_index);
}

void heapsort(vector<int>& v) {
	for(int i=v.size() - 1;i > 0;i--) {
		maxheapify(v, PARENT(i), i);
		swap(v[0], v[i]);
	}
}
void print(vector<int>& v) {
	for(int s : v) 
		cout << s << " ";
	cout << endl;
}

int main() {
	vector<int> v { 1,7,4,2,9,5,3};
	heapsort(v);
	print(v);
}
