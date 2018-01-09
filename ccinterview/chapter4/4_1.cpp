#include <iostream>
#include <vector>

using namespace std;

int adjacent[100][100];

void travel(int node, vector<bool>& visited) {
	visited[node] = true;	
	for(int i= 0;i < 100;i++) {
		if( visited[i] == false && adjacent[node][i]) {
			travel(i, visited);
		}
	}
}

bool findRoute(int a, int b) {
	vector<bool> visited(100, false);
	travel(a, visited);
	return visited[b];
}

int main() {
	findRoute(2,4);
}
