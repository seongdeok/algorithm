#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N = 10;
	vector<int> v(N+4);
	v[0] = 1;
	for(int i=0;i<N;i++){
		for(int j=1;j<=3;j++) {
			v[i+j] += v[i];
		}
	}
	cout << v[N] << endl;
}
