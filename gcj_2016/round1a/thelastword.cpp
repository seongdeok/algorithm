#include <iostream>
#include <string>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt","w", stdout);
	int tt;
	cin >> tt;
	for(int tc=1; tc <= tt;tc++) {
		string str;
		cin >> str;
		string ret("");
		for(int i=0;i<str.length();i++) {
			if(i==0 || ret.at(0) <= str.at(i))
				ret = str.at(i) + ret;
			else
				ret = ret + str.at(i);
		}
		cout << "Case #" << tc << ": " << ret << endl;
	}
}
