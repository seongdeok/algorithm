#include <vector>
#include <iostream>

using namespace std;

void makeTree(vector<int>& array, vector<int>& tree, int s, int e, int pos) {
	if( s == e) {
		tree[pos] = array[s];
		return;
	}
	makeTree(array, tree, s, (s+ e) / 2, pos* 2 + 1);
	makeTree(array, tree, (s+e) / 2 + 1, e, pos* 2 + 2);
	tree[pos] = tree[pos*2+ 1] + tree[pos*2+ 2];
}
void update(vector<int>& tree, int idx, int val, int s, int e, int pos) {
	cout << s << ", " << e << endl;
	if( s == e && s == idx) {
		tree[pos] = val;
		cout << "hit" << endl;
		return;
	}
	int p = (s + e) / 2;
	if( s <= idx && p >= idx) {
		update(tree, idx, val, s, p, pos*2 + 1);
		tree[pos] = tree[pos*2 + 1] + tree[pos*2 + 2];
	} else if( p < idx && idx <= e) {
		update(tree, idx, val, p + 1, e, pos*2 + 2);
		tree[pos] = tree[pos*2 + 1] + tree[pos*2 + 2];
	}
}
int querrywithIndex(vector<int>& tree, int from, int to, int target_s, int target_e, int pos) {
	if( from == target_s && to == target_e)
		return tree[pos];
	int target_p = (target_s + target_e) / 2;
	int res = 0;
	if( target_s <= from && target_e >= from)
		res += querrywithIndex(tree, max(from, target_s ), min(target_p, to), target_s, target_p, pos*2 + 1);
	if( target_p + 1 <= to && to <= target_e)
		res += querrywithIndex(tree, max(from, target_p+1), min(target_e, to), target_p + 1, target_e, pos*2 + 2);
	return res;
}

int querry(vector<int>& tree, int s, int e, int num) {
	return querrywithIndex(tree, s, e, 0, num, 0); 
}

int main() {
	vector<int> v { 0,1,2,3,4,5,6,7,8,9};
	vector<int> tree(4 * v.size(), 0);
	makeTree(v, tree, 0, v.size() -1, 0);
	cout <<	querry(tree, 0, 3, v.size() -1)<< endl;
	update(tree, 1, 99, 0, v.size() -1, 0);
	cout <<	querry(tree, 1, 1, v.size() -1)<< endl;
	
}
