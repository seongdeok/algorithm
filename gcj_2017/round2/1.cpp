#include <iostream>
#include <vector>

using namespace std;

int dfs(vector<int>& v, int p, int depth, vector<int>& seq) {
	if(depth == 0){
		int sum = 0;
		vector<int> vv (p, 0);
		for(auto s :seq){
			sum += s;
			vv[s]++;
		}
		if( (sum % p) == 0){
			int ratio = 100;
			for(int i = 1; i< p; i++)
				if( v[i] < vv[i] )
					return 0;
				else if(vv[i] > 0)
					ratio = min(ratio, v[i] / vv[i]);

			for(int i = 1; i< p; i++)
				v[i] -= ratio * vv[i];

			return ratio;
		} else 
			return 0;
	}
	int ret = 0;
	for(int i=1;i<p;i++) {
		seq.push_back(i);
		ret += dfs(v, p, depth -1, seq);
		seq.pop_back();
	}
	return ret;
}
int main() {
	freopen("input.in", "r", stdin);
	int tc;
	cin >> tc;
	for(int tt = 1; tt <= tc;tt++) {
		int n, p;
		cin >> n >> p;
		vector<int> v(p, 0);
		for(int i=0;i<n;i++){
			int in;
			cin >> in;
			v[in % p]++;
		}
		if( p == 1){
			cout << "Case #" << tt <<": " << n << endl;
		} else  { 
			int ret = v[0];
			vector<int> seq;
			for(int i=1;i<=p;i++)	
				ret += dfs(v, p, i, seq);
			for(int i=1;i<p;i++){
				if(v[i] > 0){
					ret += 1;
					break;
				}
			}
			cout << "Case #" << tt <<": " << ret << endl;
		}
	}
}
