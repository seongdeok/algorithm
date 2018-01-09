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
int dfs(Node* node, int sum, vector<int>& seq) {
	if(node == nullptr)
		return 0;
	int res = 0;
	seq.push_back(node->val);
	for(int i=0;i<seq.size();i++) {
		int ss = 0;	
		for(int j=i;j<seq.size();j++) {
			ss += seq[j];
		}
		if( ss==sum)
			res++;
	}
	res += dfs(node->left, sum, seq);
	res += dfs(node->right, sum, seq);
	seq.pop_back();
	return res;
}
	
int main() {
	vector<int> v { 1,2,3,4,5,};
	Node* root = makeTree(v, 0, v.size() -1);
	vector<int> seq;	
	int count = dfs(root,  1, seq );	
	cout << count;
}
