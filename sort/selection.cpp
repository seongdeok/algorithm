#include<iostream>
#include<vector>

using namespace std;

void selectionsort(vector<int>& v) {
	for(int i=0;i<v.size();i++) {
		int min_idx = i;
		for(int j=i+1;j<v.size();j++) {
			if(v[j] < v[min_idx]) 
				min_idx = j;
		}
		swap(v[min_idx], v[i]);
	}
}
			
int main() {
	vector<int> v { 10,9,8,7,6,5,4,3,2,1};
	selectionsort(v);
	for(auto c : v) 
		cout << c << " ";
	cout << endl;
}
