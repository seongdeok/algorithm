#include<iostream>
#include<vector>

using namespace std;

void mergesort(vector<int>& v, int s, int e) {
	if( s >= e)
		return;
	int mid = (s+e) /2;
	mergesort(v, s, mid);
	mergesort(v, mid+1, e);
	int a = s;
	int b = mid + 1;
	vector<int> temp (e - s + 1);
	int index = 0;
	while( a <= mid || b <= e){
		if( b > e || v[a] < v[b] ){
			temp[index++] = v[a];
			a++;
		} else {
			temp[index++] = v[b];
			b++;
		}
	}
	for(int i=0;i<index;i++)
		v[s+i] = temp[i];
	
}

int main() {
	vector<int> v { 10,9,8,7,6,5,4,3,2,1};
	mergesort(v, 0, v.size() -1);
	for(auto c : v)
		cout << c << " " ;
}
