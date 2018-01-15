#include <iostream>
#include <vector>

using namespace std;

int solve(vector<vector<int>>& v) {
	int r = v.size();
	int c = v[0].size();
	v[0][0] = 1;
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			if(j < c -1 && v[i][j+1] >= 0 ) v[i][j+1] += v[i][j];
			if(i < r -1 && v[i+1][j] >= 0 ) v[i+1][j] += v[i][j];
		}
	}
}
void dfs(vector<vector<int>>& v, int r, int c, vector<char>& path) {
	int R = v.size();
	int C = v[0].size();
	if( r >= R || c >= C)
		return;
	if( r == R - 1 && c == C - 1){
		for(char c : path)
			cout << c << "=>";
		cout <<endl;
		return;
	}
	path.push_back('R');
	dfs(v, r, c + 1,path);
	path.pop_back();
	path.push_back('D');
	dfs(v, r + 1, c,path);
	path.pop_back();
}

int main() {
	int r = 3;
	int c = 5;
	vector<vector<int>> v(3, vector<int>(5,0));
	v[1][2] = -1;
	int res = solve(v);
	cout << res << endl;
	vector<char> path;
	dfs(v, 0, 0, path);
}
