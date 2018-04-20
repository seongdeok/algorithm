#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

int solve(string& str) {
	map<char, int> mm;
	for(int i=0;i<str.length();i++) {
		mm[str.at(i)]++;
	}
	for(int i=0;i<str.length();i++)
		if(mm[str.at(i)] == 1)
			return i;
	return -1;
}


int main() {
	string s("abacde");
	cout << solve(s);
}
