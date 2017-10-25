#include <iostream>
#include <vector>

using namespace std;

void swap(int a, int b, vector<int>& v){
	int temp = v[a];
	v[a] = v[b];
	v[b] = temp;
}

void heapsort(vector<int>& array){
	for(int index = 0; index < array.size(); index++){
		int p = (index -1) / 2;
		while(index > 0){
			if(array[index] >= array[p]){
				swap(index, p, array);
				index = p;				
			} else
				break;
		}
	}
	for(int idx = array.size() -1;idx >= 0; idx--) {
		swap(0, idx, array);
		int i = 0;
		int l = 1;
		int r = 2;
		while( l < idx || r < idx) {
			if( l < idx && array[i] < array[l] && (r >= idx || array[l] > array[r])){
				swap(i, l, array);
				i = l;
			} else if( r < idx && array[i] < array[r] && (l >= idx  || array[r] > array[l])){
				swap(i, r, array);
				i = r;
			} else 
				break;
			l = i*2 + 1;
			r = i*2 + 2;
		}
	}
}

int main(){
	vector<int> v { 10,9,8,7,6,5,4,3,2,1};
	heapsort(v);
	for(auto s : v) 
		cout << s << " ";
}

