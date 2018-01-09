#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void swap(vector<int>& v, int a, int b) {
	int temp = v[a];
	v[a] = v[b];
	v[b] = temp;
}

void maxheapify(vector<int>& v, int index, int last_index) {
	if( index < 0 )
		return;
	int l = index * 2 + 1;
	int r = index * 2 + 2;
	int val_l = l > last_index ? INT_MIN : v[l];
	int val_r = r > last_index ? INT_MIN : v[r];
	if( val_l > v[index] && val_l > val_r) {
		swap(v, index, l);
	} else if( val_r > v[index] && val_r > val_l) {
		swap(v, index, r);
	}
	maxheapify(v, index -1, last_index);
}
void print(vector<int>& v) {
	for(int a : v) 
		cout << a << " ";
	cout << endl;
}

int main() {
	vector<int> v { 10, 1, 30, 15, 16,12, 4, 5,3,2};
	for( int i=v.size() - 1; i > 0; i--) {
		maxheapify(v, i / 2, i );// start from parent index of the last element
		swap(v, i, 0);
		print(v);
	}
}
