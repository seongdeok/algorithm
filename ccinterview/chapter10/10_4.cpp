#include<iostream>
#include <vector>
#include <cstdint>

using namespace std;

class Listy{
public :
	vector<int> v;
	Listy(){
		v.resize(1000,1);
	};
	~Listy(){};
	int elementAt(uint32_t i) {
		if( i >= v.size() )
			return -1;
		return v[i];
	}
};


int main() {
	Listy list;
	uint32_t l = 0;
	uint32_t r = UINT32_MAX;
	while(r - l > 1) {
		uint32_t mid = (l + r ) / 2;
		int m = list.elementAt(mid);
		if( m > 0) 
			l = mid;
		else 
			r = mid;
	}
	if( list.elementAt(l) > 0 )
		cout << l+1 << endl;
	else
		cout << r+1 << endl;
}


