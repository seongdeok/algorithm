#include <iostream>
#include <climits>
#include <bitset>
using namespace std;

void solve(uint32_t a, uint32_t b, int from, int to) {
	uint32_t t = a;
	for(int i = from; i<= to;i++)
		t &= ~(1<<i);
	t |= b << from;
	cout << t << endl;
	cout << bitset<32>(t)<< endl;
}

int main() {
	solve(0b1001111100, 0b10011, 2,6);
}
