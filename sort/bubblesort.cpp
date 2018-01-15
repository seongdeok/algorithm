#include <iostream>
#include <vector>

using namespace std;

void bubblesort(vector<int>& v ) {
	for(int i=v.size() -1; i > 0;i--) {
		for( int j=0;j < i;j++) {
			if(v[j] > v[j+1])
				swap(v[j], v[j+1]);
		}
	}
}
int main() {
	vector<int> v { 10,9,8,7,6,5,4,3,2,1};
	bubblesort(v);
	for( auto s : v) 
		cout << s << " " ;
}
