#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& v, int s, int e, int val) {
	int mid = (s + e) / 2;
	if( s >= e){
		if(s == e && v[s] == val)
			return s;
		return -1;
	}
	if( v[s] < v[e] ) {
		if( val < v[s] || val > v[e] )
			return -1;
	}
	if( v[mid] == val)	
		return mid;
	int res = -1;
	res = search(v, s, mid -1, val);
	if(res > 0)
		return res;
	res = search(v, mid + 1, e, val);
	return res;
}

int main() {
	vector<int> v { 8,9,10, 1, 2, 3, 4};
    cout <<	search(v, 0, v.size() -1, 2);
}
