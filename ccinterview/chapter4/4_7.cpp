#include <iostream>
#include <vector>

using namespace std;
enum Status {
	NOT_VISITED,
	VISITED,
	FINISHED
};
int dfs(int node, vector<vector<int>>& v, vector<Status>& visited, vector<int>& sorted) {
	int res = 1;
	visited[node] = VISITED;
	for(int i=0;i<v.size();i++) {
		if(v[node][i] > 0) {
			if(visited[i] == NOT_VISITED)
				res &= dfs(i, v, visited, sorted);
			else if(visited[i] == VISITED)
				res = 0;
		}
	}
	visited[node] = FINISHED;
	sorted.push_back(node);
	return res;
}

void topology(vector<vector<int>>& v) {
	vector<Status> visited(v.size(), NOT_VISITED);
	vector<int> seq;
	int res = 1;
	for(int i=0;i<v.size();i++){
		if(visited[i] == NOT_VISITED) 
			res &= dfs(i, v, visited, seq);
	}
	if( res == 0)
		cout << "cycle exists" << endl;
	else {
		for(int i=v.size() -1; i >= 0 ;i--)
			cout << seq[i] << ",";
		cout << endl;
	}
}

int main() {
	vector<vector<int>> v(6, vector<int>(6,0));
	v[0][3] = 1;
	v[5][1] = 1;
	v[1][3] = 1;
	v[5][0] = 1;
	v[3][2] = 1;
	v[2][5] = 1;
	topology(v);
}
