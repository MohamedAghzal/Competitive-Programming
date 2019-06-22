#include <bits/stdc++.h>

using namespace std;

typedef pair <int, pair <int, int>> ppi;

const int N = 11, INF = (int) 1e9, MOD = 20437;

int dp[N * N * 10][N][N][26], dist[N][N][26];
bool visited[N][N][26];

char g[N][N];

int dx[] = {0, 1, -1, 0};
int dy[] = {-1, 0, 0, 1};

int n, t;

typedef pair <pair <int, int>, char> state;

int get(int steps, int i, int j, int c){
    if(i >= n || j >= n || i < 0 || j < 0 || steps < 0)
        return 0;
    if(g[i][j] == '#')
        return 0;
    if(c == t)
        return 1;
    if(dp[steps][i][j][c] != -1)
        return dp[steps][i][j][c];

    int ans = 0;
    for(int d = 0; d < 4; d++){
        int x = i + dx[d];
        int y = j + dy[d];
        if(x < 0 || x >= n || y < 0 || y >= n || g[x][y] == '#')
            continue;

        int nc = g[x][y] == char(c + 'A' + 1)? c + 1: c;
        if(dist[x][y][nc] != dist[i][j][c] + 1)
            continue;
        ans += get(steps - 1, x, y, nc);
        ans %= MOD;
    }

    return dp[steps][i][j][c] = ans % MOD;
}

int main(){
    int c = 0;
    while(true){
        scanf("%d", &n);
        if(n == 0)
            break;

        pair <int, int> start, lst;
        t = -1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                scanf(" %c", &g[i][j]);
                if(g[i][j] == 'A')
                    start = {i, j};
                if(isalpha(g[i][j])){
                    if(t < g[i][j] - 'A'){
                        t = g[i][j] - 'A';
                        lst = {i, j};
                    }
                }
            }
        }

        memset(dp, -1, sizeof dp);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                for(int k = 0; k < 26; k++){
                    dist[i][j][k] = INF;
                    visited[i][j][k] = false;
                }
            }
        }

        printf("Case %d: ", ++c);

        queue <state> Q;
        Q.push({{start.first, start.second}, 'A'});
        dist[start.first][start.second][0] = 0;
        visited[start.first][start.second][0] = true;

        while(!Q.empty()){
            auto nxt = Q.front();
            Q.pop();

            int u = nxt.first.first;
            int v = nxt.first.second;
            int c = nxt.second - 'A';
            for(int i = 0; i < 4; i++){
                int x = u + dx[i];
                int y = v + dy[i];

                if(x >= n || x < 0 || y >= n || y < 0 || c < 0 || c >= 26 || (g[x][y] != '.' && g[x][y] > char(c + 'A' + 1)))
                    continue;
                if(g[x][y] == '#')
                    continue;

                if(g[x][y] == char(c + 'A' + 1)){
                    if(visited[x][y][c + 1])
                        continue;
                    visited[x][y][c + 1] = true;
                    dist[x][y][c + 1] = dist[u][v][c] + 1;
                    Q.push({{x, y}, char(c + 'A' + 1)});
                } else {
                    if(visited[x][y][c])
                        continue;
                    visited[x][y][c] = true;
                    dist[x][y][c] = dist[u][v][c] + 1;
                    Q.push({{x, y}, char(c + 'A')});
                }
            }
        }

        int shortest = dist[lst.first][lst.second][t];
        memset(dp, -1, sizeof dp);

        if(shortest == INF)
            puts("Impossible");
        else
            printf("%d %d\n", shortest, get(shortest, start.first, start.second, 0));
    }
    return 0;
}
