#include <iostream>
#include <vector>
#include <string>
using namespace std;

int search(vector<string>& v, string str, int s, int e) {
	if(s >= e){
		if( v[s].compare(str) == 0){
			cout << s << endl;
			return 1;
		}
		return 0;
	}
	int mid = (s+ e) / 2;
	if(search(v,str, s,mid)){
		return 1;
	}
	return search(v,str, mid + 1, e);
}

int main() {
	vector<string> v { "abc", "", "" , "", "ball", "", "", "car", "", "", "dad", "", ""};
	search(v, "ball", 0, v.size()-1);
}
