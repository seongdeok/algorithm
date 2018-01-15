#include <iostream>
#include <vector>

using namespace std;

int solve(int n, int sum, int depth) {
	if(depth >3){
		if(sum == n) 
			return 1;
		return 0;
	}
	int res = 0;		
	vector<int> coin { 25,10,5,1};
	int limit = (n - sum) / coin[depth];
	for(int i=0; i <= limit;i++) {
		solve(n, sum + i*coin[depth] , depth + 1);
	}
	return res;
}

int main() {
	cout << solve(10, 0, 0);
}
