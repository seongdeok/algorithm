#include<iostream>
#include<vector>

using namespace std;
void dfs(int in, int out, vector<char>& seq) {
	if(in == 0 && out == 0){
		for(char c : seq) 
			cout << c;
		cout <<endl;
		return;
	}
	if( in > 0) {
		seq.push_back('(');
		dfs(in -1, out, seq);
		seq.pop_back();
	}
	if( out > 0 && in < out) {
		seq.push_back(')');
		dfs(in, out -1, seq);
		seq.pop_back();
	}
}
			
int main() {
	int n = 3;
	vector<char> seq;
	dfs(3,3,seq);
}
