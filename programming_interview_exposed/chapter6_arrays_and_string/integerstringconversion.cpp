#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int convert(string& str) {
	int ret = 0;
	int sign = 1;
	int idx = 0;
	if(str.at(0) == '-' ) {
		sign = -1;
		idx++;
	}
		
	for(;idx<str.length();idx++) {
		ret = ret * 10;
		ret += str.at(idx) - '0';
	}
	return ret* sign;
}
string convertInteger(int num) {
	string ret = "";
	int val = num < 0 ? (-1) * num : num;
	while( val > 0 ) {
		ret = (char)('0' + val % 10) + ret;
		val /= 10;
	}
	if(num < 0) 
		ret = '-' + ret;
	return ret;
}
int main() {
	string s("-12345");
	cout << convert(s);
	cout << convertInteger(-654321);
}
