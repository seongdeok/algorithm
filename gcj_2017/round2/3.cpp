#include <iostream>
#include <vector>

using namespace std;
char arr[51][51];
char temp[51][51];
int R,C;
bool dfs(int r, int c) {
    int next_r = r;
    int next_c = c+1;
    for(next_r=r;next_r< R;next_r++){
        for(; next_c < C;next_c++) {
            if(arr[next_r][next_c] == '|' || arr[next_r][next_c] == '-' ){
                break;
            }
        }
        if(arr[next_r][next_c] == '|' || arr[next_r][next_c] == '-' ){
                        break;
                    }
        next_c = 0;
    }

    if(r >= R) {
        for(int i=0;i<R;i++) for(int j=0;j<C;j++)
            temp[i][j] = arr[i][j];

        for(int i=0;i<R;i++) for(int j=0;j<C;j++){
            if(temp[i][j] =='|') {
                for(int k=0;k < R;k++) {
                    if( k == i) continue;
                    if( temp[k][j] == '.')
                        temp[k][j] = 'O';
                    else if(temp[k][j] == '|' || temp[k][j] == '-') {
                        return false;
                    }
                }
            } else if(temp[i][j] =='-') {
                for(int k=0;k < C;k++) {
                    if(k == j) continue;
                    if( temp[i][k] == '.')
                        temp[i][k] = 'O';
                    else if(temp[i][k] == '|' || temp[i][k] == '-') {
                        return false;
                    }
                }
            }
        }

        for(int i=0;i<R;i++) for(int j=0;j<C;j++)
            if(temp[i][j] == '.')
                return false;
        return true;
    }
    bool ret = dfs(next_r, next_c);
    if( ret)
        return ret;
    if( arr[r][c] == '|') {
        arr[r][c] = '-';
        ret = dfs(next_r, next_c);
    } else if(arr[r][c] == '-') {
        arr[r][c] = '|';
        ret = dfs(next_r, next_c);

    }
    return ret;


}

int main() {
    freopen("input.txt","r", stdin);
    int tc;
    cin >> tc;
    for(int tt=1;tt<=tc;tt++) {
        cin >> R >> C;
        for(int i=0;i<R;i++)
            for(int j=0;j<C;j++){
                cin >> arr[i][j];
                temp[i][j] = arr[i][j];
            }
        bool ret = dfs(0,0);
        cout << "Case #" << tt << ": ";
        if(ret) {
            cout << "POSSIBLE" << endl;
            for(int i=0;i<R;i++) {
                for(int j=0;j<C;j++) {
                    if(temp[i][j] == 'O')
                        cout << "." ;
                    else
                        cout << temp[i][j];
                }
                cout << endl;
            }
        } else {
            cout << "IMPOSSIBLE" << endl;
        }
    }
}

