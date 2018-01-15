#include <iostream>
#include <vector>

using namespace std;
void dfs(vector<int>& v, vector<bool>& visited, vector<int>& seq) {
	for(int s : seq) 
		cout << s << ",";
	cout << endl;
	for(int i=0;i<v.size();i++) {
		if(visited[i] == false){
			seq.push_back(v[i]);
			visited[i] = true;
			dfs(v,visited, seq);
			seq.pop_back();
			visited[i] = false;
		}
	}
}
int main() {
	vector<int> v { 1,3,5,7,9};
	vector<bool> visited(v.size(), false);
	vector<int> seq;
	dfs(v, visited, seq);
}
