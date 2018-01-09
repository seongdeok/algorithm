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
Node* getNode(Node* node, int val) {
	if(node->val == val)
		return node;
	Node* temp = nullptr;
	if(node->left){
		temp = getNode(node->left);
		if(temp)
			return temp;
	}
	if(node->right) {
		temp = getNode(node->right);
		if(temp)
			return temp;
	}
	return nullptr;
}
		
int main() {
	vector<int> v { 1,5, 4};
	Node* root = makeTree(v, 0, v.size() -1 );
	cout << isBST(root) <<endl;
}
