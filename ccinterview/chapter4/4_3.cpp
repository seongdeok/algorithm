#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
	int val;
	Node* left;
	Node* right;
};

struct LinkedList {
	int val;
	LinkedList* next;
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

void makeList(Node* root, vector<LinkedList*>& v) {
	queue<Node*> que;
	que.push(root);
	int depth = 0;
	while(!que.empty()) {
		size_t sz = que.size();
		LinkedList* before = nullptr;
		for(size_t i = 0;i < sz;i++) {
			Node* node = que.front();
			que.pop();
			LinkedList* cur = new LinkedList;
			cur->val = node->val;
			cur->next = nullptr;
			if(before == nullptr) {
				v.push_back(cur);
			} else {
				before->next = cur;
			}
			before = cur;
			if(node->left)
				que.push(node->left);
			if(node->right)
				que.push(node->right);
		}
	}
}

int main() {
	vector<int> v { 1,3,5,7,8,9, 10};
	Node* root = makeTree(v, 0, v.size() -1);
	vector<LinkedList*> list;
	makeList(root, list);
	for(LinkedList* head : list){
		LinkedList* temp = head;
		while(temp)	{
			cout << temp->val << ",";
			temp = temp->next;
		}
		cout << endl;
	}
}


	
