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

int dfs(Node* node) {
	if(node==nullptr) 
		return 0;
	int l = dfs(node->left);
	int r = dfs(node->right);
	if(l != r || l == -1 || r == -1)	
		return -1;
	else
		return l + 1;
}

int main() {
	vector<int> v { 1,3,5};
	Node* root = makeTree(v, 0, v.size() -1 );
	cout << root << "mmm" << endl;
	cout << dfs(root) << endl;
}
