#include<iostream>
#include <vector>

using namespace std;

int board[8][8];
bool available(int i, int j) {
	int x_dir[8] = { 1, 1, -1, -1, 1, 0,-1, 0};
	int y_dir[8] = {-1, 1, -1,  1, 0, 1, 0,-1};
	for(int k = 0;k < 8; k++) {
		int a = i;
		int b = j;
		while( a >= 0 && a < 8 && b >= 0 && b < 8){
			if(board[a][b] ==1)
				return false;
			a += x_dir[k];
			b += y_dir[k];
		}
	}
	return true;
}
int dfs(int num, int start) {
	if(num >= 8){
		return 1;
	}
	int res = 0;
	int index = start;
	while( index < 64) {
		int i = index / 8;
		int j = index % 8;
		if(board[i][j] == 0 && available(i,j)){
			board[i][j] = 1;
			res += dfs(num + 1, index + 1);
			board[i][j] = 0;
		}
		index++;	
	}
	return res;
}
int main(){
	for(int i=0;i<8;i++)
		for(int j=0;j<8;j++)
			board[i][j] = 0;
	cout << dfs(0, 0);

}
