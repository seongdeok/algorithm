#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void dfs(vector<bool>& used, vector<int>& seq, string& s) {
	if(seq.size() == used.size()) {
		for(int elem : seq) 
			cout << s.at(elem);
		cout << endl;
		return;
	}
	for(int i=0;i<used.size();i++) {
		if(used[i] == false) {
			used[i] = true;
			seq.push_back(i);
			dfs(used, seq, s);
			used[i] = false;
			seq.pop_back();
		}
	}
}

void permutation(string& str) {
	vector<bool> used(str.length(), false);
	vector<int> seq;
	dfs(used, seq, str);
}

int main() {
	string s{"hat"};
	permutation(s);
}
