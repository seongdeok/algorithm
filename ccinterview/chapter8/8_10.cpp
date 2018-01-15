#include<iostream>
#include<vector>

using namespace std;

void dfs(vector<vector<int>>& v, int r, int c, int old_color, int new_color) {
		
	int R = v.size();
	int C = v[0].size();
	v[r][c] = new_color;
	if( r + 1 < R && v[r+1][c] == old_color)
		dfs(v, r + 1, c, old_color, new_color);
	if( c + 1 < C && v[r][c+1] == old_color)
		dfs(v, r , c + 1, old_color, new_color);
	if( r > 0 && v[r-1][c] == old_color)
		dfs(v, r -1, c, old_color, new_color);
	if( c > 0 && v[r][c-1] == old_color)		
		dfs(v, r , c - 1, old_color, new_color);

}
void solve(vector<vector<int>>& v, int r, int c, int color) {
	dfs(v,r,c,v[r][c], color);
}
int main() {
	vector<vector<int>> v(4, vector<int>(5,0));
	v[1][2] = v[2][1] = v[2][2] = v[2][3] =  1;
	solve(v, 2, 2, 3);
	for(auto r : v){
		for(auto c : r) 
			cout << c << " ";
		cout << endl;
	}
}

