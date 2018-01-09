#include <iostream>

using namespace std;

int main(){
	uint32_t a = 0b11101;
	uint32_t b = 0b01111;
	int cnt = 0;
	for(int i=0;i<32;i++){
		if( (a & (1<<i)) != (b & (1<<i)))
			cnt++;
	}
	cout << cnt << endl;
}
