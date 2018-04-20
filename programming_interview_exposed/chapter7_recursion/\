#include <iostream>
#include <vector>

using namespace std;

int binarysearch(vector<int>& array, int s, int e, int val) {
	if( s > e){
		return -1;
	}
	int mid = (s + e) / 2;
	if( array[mid] > val ) {
		return binarysearch(array, s, mid - 1, val);
	} else if (array[mid] == val) {
		return mid;
	} else 
		return binarysearch(array, mid + 1, e, val);
}

int main() {
	vector<int> v{1,4,6,8,9,10, 13, 16, 18, 20};	
	cout << binarysearch(v, 0, v.size() -1, 3);
}
