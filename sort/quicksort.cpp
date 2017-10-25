#include <iostream>
#include <vector>

using namespace std;

int swap(int a, int b, vector<int>& v){
	int temp = v[a];
	v[a] = v[b];
	v[b] = temp;
}

int partitioning(vector<int>& v, int from, int to) {
	int pivot = v[to];
	int l = from;
	int r = to -1;
	while(l < r){
		while(l < to && v[l] < pivot)
			l++;
		while(r >= 0 && v[r] > pivot)
			r--;
		if( l < r)
			swap(l, r, v);
		else
			swap(l, to, v);			
	}
	return l;
}

void quicksort(vector<int>& v, int from, int to){
	if(from >= to)
		return;
	int p = partitioning(v, from, to);
	quicksort(v, from, p-1);
	quicksort(v, p+1, to);
}

int main(){
	vector<int> v{ 10,9,8,7,6,5,4,3,2,1,};
	quicksort(v, 0, v.size() -1);
	for(auto s: v)
		cout << s << " ";
}
