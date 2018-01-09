#include <iostream>
#include <vector>

using namespace std;
struct Node {
	int val;
	Node* left;
	Node* right;
};

Node* makeTree(vector<int>& v, int l, int r) {
	Node* cur = new Node;
	int med = (l+r) / 2;
	cur->val = v[med];
	if( l < med) 
		cur->left = makeTree(v, l, med -1);
	else
		cur->left = nullptr;
	if( r > med)
		cur->right = makeTree(v, med+1, r);
	else
		cur->right = nullptr;
}
void dfs(Node* node, vector<bool>& visited, vector<int>& seq) {
	if(node == nullptr)
		return;
	
int main() {
	vector<int> v { 1,2,3,4,5,6};
	Node* root = makeTree(v, 0, v.size() -1);
	dfs(root, vector<bool>(v.size()), vector<int>());		
}
