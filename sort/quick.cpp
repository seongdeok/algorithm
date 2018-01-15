#include <iostream>
#include <vector>

using namespace std;

int partitioning(vector<int>& v, int from, int to) {
	int pivot = to;
	int done_index = from -1;
	for(int i = from;i<to;i++) {
		if( v[i] < v[pivot]) {
			done_index++;
			swap(v[done_index],v[i]);
		}
	}
	swap(v[done_index+1], v[pivot]);
	return done_index+1;
}
void quicksort(vector<int>& v, int from, int to) {
	if( from >= to)
		return;
	int p =	partitioning(v, from, to);	
	quicksort(v, from, p-1);
	quicksort(v, p + 1, to);
}
int main() {
	vector<int> v { 6,4,6,3,21,6,3,7,3,5,23,76,3,64,3,2,1};
	quicksort(v, 0, v.size() -1);
	for(auto c : v) 
		cout << c << " ";

}
