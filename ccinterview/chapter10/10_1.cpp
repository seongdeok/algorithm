#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void solve(vector<int>& a, int sz, vector<int>& b) {
	int i = sz -1;
	int j = b.size() -1;
	int s = sz + b.size() - 1;
	while( i >= 0 || j >= 0) {
		if( j < 0 || a[i] > b[j]){
			a[s] = a[i];
			s--;i--;
		} else {
			a[s] = b[j];
			s--;j--;
		}
	}
}
int main() {
	vector<int> a { 1,4,6,8,9,11, -1,-1,-1, -1,-1};
	vector<int> b { 12,13,15,16,17};
	solve(a, 6, b);
	for(auto s : a) 
		cout << s << " ";
	}
