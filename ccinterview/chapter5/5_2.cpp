#include <iostream>
#include <algorithm>
using namespace std;

int getCount(uint32_t n) {
	int maxi = 0;
	int cnt = 0;
	for(int i=0;i<32;i++) {
		if( n & (1 << i))
			cnt++;
		else
			cnt = 0;
		maxi = max(maxi, cnt);
	}
}
void solve(uint32_t num) {
	int maxi = 0;
	for(int i=0;i<32;i++) {
		uint32_t t = num | (1<<i);
		maxi = max(maxi, getCount(t));
	}
	cout << maxi << endl;
}

int main() {
	solve(0b111011001);
}
