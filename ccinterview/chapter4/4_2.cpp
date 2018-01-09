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
int depth(Node* cur) {
	if( cur== nullptr)
		return 0;
	int maxi = 0;
	maxi = max(maxi, depth(cur->left) + 1);
	maxi = max(maxi, depth(cur->right) + 1);
	return maxi;
}
int main() {
	vector<int> v { 1,2,4,5,7,8,9};
	Node* root = makeTree(v, 0, v.size() -1);
	cout << depth(root) << endl;
}
