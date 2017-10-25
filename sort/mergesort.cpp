#include<iostream>
#include <algorithm>
#include <vector>

using namespace std;

void mergesort(vector<int>& v, int from, int to) {
	if(to <= from)
		return;
	int mid = (from + to) / 2;
	mergesort(v, from, mid);
	mergesort(v, mid + 1, to);
	vector<int> temp(v);

	int l = from;
	int r = mid + 1;
	int idx = 0;
	while( l <= mid || r <= to){
		if( v[l] < v[r] || r > to)
			temp[idx++] = v[l++];
		else
			temp[idx++] = v[r++];
	}
	for(int i=0;i<= to -from;i++)
		v[from+i] = temp[i];
		
}


int main(){
	vector<int> v{10,9,8,7,6,5,4,3,2,1};
	mergesort(v, 0, v.size() -1);
	for(auto s: v)
		cout << s << " ";
}
