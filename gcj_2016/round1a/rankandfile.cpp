#include <iostream>
#include <map>
#include <set>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt","w", stdout);
	int tt;
	cin >> tt;
	for(int tc = 1; tc <= tt; tc++) {
		int n;
		int in;
		cin >> n;
		map<int, int> mm;
		for(int i=0;i< n*(n*2 - 1);i++) {
			cin >> in;
			if(mm.find(in) == mm.end() ) 
				mm.insert(make_pair(in, 1));
			else
				mm[in]++;
		}
		set<int> ret;
		for(auto iter : mm) {
			if(iter.second % 2 == 1)
				ret.insert(iter.first);
		}
		cout << "Case #" << tc << ":";
		for(const int& val : ret)
			cout << " " << val;
		if( n != ret.size())
			cout <<" wrong n, size " << n << "," << ret.size() ;
		cout << endl;
	}
}
