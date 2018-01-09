#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
	int val;
	Node* left;
	Node* right;
	int index;
};

int res = -1;

bool dfs(Node* node, int val1, int val2) {
	if(node == nullptr)
		return false;
	bool l = dfs(node->left, val1,val2);
	bool r = dfs(node->right, val1, val2);
	if( l && (node->val == val1 || node->val == val2) )
		res = node->val;
	else if( r && (node->val == val1 || node->val == val2))	
		res = node->val;
	else if( l && r)
		res = node->val;
	bool result = l || r;
	result |= node->val == val1;
	result |= node->val == val2;
//	return result;
	return l || r || node->val == val1 || node->val == val2;
}
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
void printTree(Node* root) {
	queue<Node*> que;
	que.push(root);
	root->index = 0;
	int space = 40;
	while(!que.empty()) {
		int sz = que.size();
		Node* before = nullptr;
		for(int i=0;i<space;i++)
			cout << " ";
		space -= 2;
		for(int i=0;i<sz;i++) {
			Node* cur = que.front();
			que.pop();
			if(before != nullptr){
				for(int i=0;i< (cur->index - before->index);i++)
					cout << "   ";
			} else {
				for(int i=0;i< (cur->index);i++)
					cout << "   ";
			}
			cout << cur->val;
			if(cur->left){
				cur->left->index = cur->index * 2 ;
				que.push(cur->left);
			}
			if(cur->right){
				que.push(cur->right);
				cur->right->index = cur->index * 2 + 1;
			}
			before = cur;
		}
		cout << endl;
	}
}

int main() {
	vector<int> v{ 1,2,3,4,5};
	Node* root = makeTree(v, 0, v.size() -1);
	printTree(root);
	dfs(root, 2, 4);
	cout << res << endl;
}
