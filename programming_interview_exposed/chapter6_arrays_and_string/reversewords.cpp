#include <iostream>
#include <string>

using namespace std;

string solve(string& s) {
	string ret("");
	int last = s.length() -1;
	int idx = last;
	while(idx >= 0) {
		if(last <= 0)
			break;
		while(s.at(last) == ' '){
			last--;
		}
		idx = last;
		while(idx >= 0){
			if( s.at(idx) == ' ' || idx == 0) {
				if(ret.length() != 0)
					ret += ' ';
				if(idx == 0)
					ret += s.substr(idx, last -idx+1);
				else
					ret +=s.substr(idx+1, last - idx);
				last = idx;
				break;
			}
			idx--;
		}
	}
	return ret;
}

int main() {
	string s("Do or do not, there is no try.");
	cout <<	solve(s);
}
