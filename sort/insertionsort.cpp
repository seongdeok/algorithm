#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	vector<int> v {10,9,8,7,6,5,4,3,2,1};
	for(int i=1;i < v.size();i++){
		int idx = i;
		while(idx > 0 && v[idx] < v[idx-1]) {
			swap(v[idx], v[idx-1]);
			idx--;
		}
	}
	for(auto s : v)
		cout << s << " " ;

}
