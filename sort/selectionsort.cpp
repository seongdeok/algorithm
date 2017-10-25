#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	vector<int> v = {10,9,8,7,6,5,4,3,2,1};
	for(int i=0;i < v.size();i++){
		int mini = v[i];
		int idx = i;
		for(int j=i+1;j < v.size();j++){
			if( v[j] < v[idx]) {
				mini = v[j];
				idx = j;
			}
		}
		swap(v[i], v[idx]);
	}
	for(auto s : v) 
		cout << s << " ";
}
