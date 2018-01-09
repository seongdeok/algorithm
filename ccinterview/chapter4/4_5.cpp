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
bool isBST(Node* node) {
	if(node == nullptr) 
		return true;
	bool res = isBST(node->left);
	res &= isBST(node->right);
	if(res){
		if(node->left)
			res &= node->val >= node->left->val;
		if(node->right)
			res &= node->val <= node->right->val;
	} 
	return res;
}

int main() {
	vector<int> v { 1,5, 4};
	Node* root = makeTree(v, 0, v.size() -1 );
	cout << isBST(root) <<endl;
}
