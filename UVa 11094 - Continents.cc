#include <bits/stdc++.h>

using namespace std;
const int N = 50;
char g[N][N];
int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};
int m, n;
int floodfill(int i, int j, char c1, char c2){
    if(j < 0) j = m - 1;
    if(j > m - 1) j = 0;

    if(i < 0 || i >= n || j < 0 || j >= m) return 0;
    if(g[i][j] != c1) return 0;

    int ans = 1;
    g[i][j] = c2;
    for(int d = 0; d < 4; d++){
        ans += floodfill(i + dr[d], j + dc[d], c1, c2);
    }

    return ans;
}

int main(){
    while(scanf("%d %d", &n, &m) != EOF){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                scanf(" %c", &g[i][j]);
            }
        }

        int x, y;
        scanf("%d %d", &x, &y);
        char c = g[x][y];
        floodfill(x, y, c, '.');

        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ans = max(ans, floodfill(i, j, c, '.'));
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}
