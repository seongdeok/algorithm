#include <iostream>
#include <vector>

using namespace std;
void solve(vector<int>& v, int value) {
	int l = 0;
	int r = v.size() -1;
	int idx;
	while( r - l > 1) {
		int mid = (l + r) /2;
		if( v[mid] > v[0]) 
			r = mid;
		else
			l = mid;
	}
	if(v[l] > v[0])
		idx = r;
	else 
		idx = l;
	if( v[0] > value){
		l = 0;
		r = idx;
	} else {
		l = idx;
		r = v.size() -1;
	}
	while( r-l >1 ) {
		int mid = (l+r) / 2;
		if(v[mid] > value)
			r = mid;
		else
			l = mid;
	}
	if( v[l] == value)
		cout << l << endl;
	else
		cout << r << endl;
}

int main() {
	vector<int> v { 8,9,10, 1, 2, 3, 4};
	solve(v, 2);
}
