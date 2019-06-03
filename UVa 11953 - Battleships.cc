#include <bits/stdc++.h>

using namespace std;

const int N = 150;

char g[N][N];
int dx[] = {1, 0, 0, -1,};
int dy[] = {0, 1, -1, 0};
int n;

int get(int i, int j){
    if(i >= n || i < 0 || j < 0 || j >= n)
        return 0;
    if(g[i][j] == '.')
        return 0;

    int ans = (g[i][j] == 'x');
    g[i][j] = '.';
    for(int d = 0; d < 8; d++){
        ans |= get(i + dx[d], j + dy[d]);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;

    int c = 0;
    while(T--){
        cin >> n;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> g[i][j];
            }
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                ans += get(i, j);
            }
        }

        cout << "Case " << ++c << ": " << ans << endl;
    }

    return 0;
}
