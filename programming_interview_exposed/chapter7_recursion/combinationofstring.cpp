#include <iostream>
#include <string>
#include <vector>

using namespace std;

void combination(string& str, vector<char>& seq, int pos) {
	if(seq.size() > 0) {
		for(char c : seq)
			cout << c;
		cout << endl;
	}
	if( pos >= str.length()){
		return;
	}
	for(int i=pos;i<str.length();i++){
		seq.push_back(str.at(i));
		combination(str, seq, i + 1);
		seq.pop_back();
	}
}

int main() {
	string s("12345");
	vector<char> seq;
	combination(s, seq, 0);
}
