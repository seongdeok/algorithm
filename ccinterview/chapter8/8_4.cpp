#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<int>& v, int depth, vector<int>& seq) {
	if( depth >= v.size() ) {
		for(int s : seq) 
			cout << s << ",";
		cout << endl;
		return;
	}
	for(int i=depth;i<v.size();i++) {
		seq.push_back(v[i]);
		dfs(v, i+1, seq);
		seq.pop_back();
	}
}

int main() {
	vector<int> v { 5,3,2,6 };
	vector<int> seq;
	dfs(v, 0,seq);
}

