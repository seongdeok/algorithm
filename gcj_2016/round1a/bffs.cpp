#include <iostream>
#include <vector>

using namespace std;

int dfs(vector<int>& seq, vector<bool>& visited, vector<int>& bffs) {
	int ret = 0;
	if(seq.size() == visited.size()) {
		for(int i=0;i<seq.size();i++) {
			int l = (i == 0) ? seq.back() : seq[i-1];
			int r = (i == seq.size() - 1) ? seq[0] : seq[i+1];
			if( l == bffs[seq[i]] || r == bffs[seq[i]]) 
				ret++;
		}
		return ret;
	}
	for(int i=0;i<visited.size();i++) {
		if( visited[i] == false) {
			seq.push_back(i);
			visited[i] = true;
			ret = max(ret, dfs(seq, visited, bffs));
			seq.pop_back();
			visited[i] = false;
		}
	}
	return ret;
}

int main() {
	int tt;
	cin >> tt;
	freopen("input.txt","r", stdin);
	freopen("output.txt","w", stdout);
	for(int tc=1;tc <= tt; tc++) {
		int n;
		cin >> n;
		vector<int> v(n);
		for(int i=0;i<n;i++){
			cin >> v[i];
			v[i]--;
		}
		vector<bool> visited(n,false);
		vector<int> seq;
		cout << "Case #" << tc << ": ";
		cout <<  dfs(seq, visited, v) << endl;
	}
}
