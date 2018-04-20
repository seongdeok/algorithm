#include <iostream>
#include <vector>
using namespace std;

struct Node {
	int val;
	Node* left;
	Node* right;
	Node(int v) : val(v), left(nullptr), right(nullptr){};
};

Node* insert(Node* root, int val) {
	Node* cur = root;
	Node* newOne = new Node(val);

	if(cur) {
		while(cur) {
			if(val < cur->val) {
				if(cur->left) {
					cur = cur->left;
				} else {
					cur->left = newOne;
					break;
				}
			} else {
				if(cur->right) 	
					cur = cur->right;
				else{
					cur->right = newOne;
					break;
				}
			}
		}
	}
	if(root == nullptr)
		root = newOne;
	return root;
}
void dfs(Node* node) {
	if(node->left)
		dfs(node->left);
	cout << node->val << " , ";
	if(node->right) 
		dfs(node->right);
}
int main() {
	Node* root = nullptr;
	root = insert(root, 2);
	root = insert(root, 9);	
	root = insert(root, 3);	
	root = insert(root, 5);	
	root = insert(root, 8);	
	root = insert(root, 19);	
	root = insert(root, 1);	
	dfs(root);
	cout << "-----------" << endl;
	Node* cur = root;
	vector<Node*> que;
	while(!que.empty() || cur) {
		if(cur) {
			que.push_back(cur);
			cur = cur->left;
		} else {
			Node* temp = que.back();
			que.pop_back();
			cout << temp->val << ",";
			cur = temp->right;
		}
	}

}
