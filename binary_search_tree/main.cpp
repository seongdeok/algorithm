#include <algorithm>
#include <iostream>
#include <random>
#include <vector>
#include <queue>
using namespace std;

struct Tree{
	int val;
	Tree* left;
	Tree* right;
};

int getRandom(int min, int max){
	random_device rn;
	mt19937_64 rnd(rn());
	uniform_int_distribution<int> range(min, max);
	return range(rnd);
}
Tree* insert(int val, Tree* root){
	Tree* node = new Tree;
	node->val = val;
	node->left = node->right = nullptr;
	if(root == nullptr){
		return node;
	} else {
		Tree* search = root;
		while(true) {
			if(search->val < val){
				if(search->right == nullptr) {
					search->right = node;
					break;
				} else
					search = search->right;
			} else {
				if(search->left == nullptr) {
					search->left = node;
					break;
				} else 
					search = search->left;
			}
				
		}
	}
	return root;
}
void inorder(Tree* node) {
	if(node == nullptr)
		return;
	inorder(node->left);
	cout << node->val << " " ;
	inorder(node->right);
}
void printTree(Tree* root) {
	queue<Tree*> que;
	que.push(root);
	while(!que.empty()){
		int cnt = que.size();
		for(int i=0;i<cnt;i++) {
			Tree* cur = que.front();
			que.pop();
			if(cur)
				cout << cur->val << " ";
			else
				cout << "N/A" << " ";
			if(cur)
				que.push(cur->left);
			if(cur)
				que.push(cur->right);
		}
		cout << endl;	
	}
}
int main(){
	vector<int> v;
	Tree* root = nullptr;
	for(int i=0;i<10;i++)
		v.push_back(getRandom(0,100));
	for(int i=0;i<10;i++)
		root = insert(v[i], root);	
	for(auto s : v)	
		cout << s << " " ;
	cout << endl;
	printTree(root);
	inorder(root);
}
