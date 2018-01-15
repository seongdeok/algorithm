#include <iostream>
#include <vector>

using namespace std;



int main() {
	vector<int> v { -2,0,3,3,5,7,8};
	int l = 0;
	int r = v.size() - 1;
	while( r - l > 1){
		int mid = (l + r) / 2;
		if( v[mid] > mid) 
			r = mid;
		else if( v[mid] < mid)
			l = mid;
		else
			l = r = mid;
	}
	if(v[l] == l)
		cout << l << endl;
	else if(v[r] == r)
		cout << r << endl;
	else
		cout << "Not exist" <<endl;

}
