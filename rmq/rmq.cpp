#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void makeTree(vector<int>& v, vector<int>& rmq, int s, int e, int pos) {
	if( s>= e){
		rmq[pos] = v[s];
		return;
	}
	int m = (s+e)/2;
	makeTree(v, rmq, s, m, pos*2 + 1);
	makeTree(v, rmq, m+ 1, e, pos*2 + 2);
	rmq[pos] = min(rmq[pos*2+1], rmq[pos*2+2]);
}

int query(vector<int>& rmq, int from, int to, int s, int e, int pos) {
	if(from == s && to == e && from == to){
		return rmq[pos];
	}
	int res = INT_MAX;
	int m = (s + e) / 2;
	if( s <= from && from <= m)
		res = min(res, query(rmq, from, min(m, to), s, m, pos*2 + 1));
	if( m + 1 <= to && to <= e) 
		res = min(res, query(rmq, max(from, m + 1), to, m+ 1, e, pos* 2 + 2));
	return res;
}

int main() {
	vector<int> v{1,5,3,2,7,3,8,8,9,2,5,3,7,5,4};
	vector<int> rmq(v.size() * 4);
	makeTree(v, rmq, 0, v.size() -1, 0);
	cout << query(rmq, 0,4, 0, v.size() -1, 0);
}
