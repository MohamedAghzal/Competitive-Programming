#include <bits/stdc++.h>

using namespace std;

const int N = 20;

typedef pair <pair<int, int>, int> state;
int dist[N][N][1 << 16], seen[N][N][1 << 16], nt[N][N];
char g[N][N];

int dx[] = {1, 0, 0, -1, 1, 1, -1, -1};
int dy[] = {0, -1, 1, 0, -1, 1, 1, -1};

int main(){
    int n, m;

    while(cin >> n >> m){
        int nuts = 0;
        pair <int, int> start;
        memset(nt, -1, sizeof nt);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> g[i][j];
                if(g[i][j] == '#'){
                    nt[i][j] = nuts++;
                } else if (g[i][j] == 'L'){
                    start = {i, j};
                }
            }
        }

        memset(seen, 0, sizeof seen);
        memset(dist, 0, sizeof dist);

        queue <state> Q;
        Q.push({{start.first, start.second}, 0});
        dist[start.first][start.second][0] = 0;
        seen[start.first][start.second][0] = 1;
        while(!Q.empty()){
            state t = Q.front();
            Q.pop();

            int x = t.first.first;
            int y = t.first.second;
            int mask = t.second;

            for(int i = 0; i < 8; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx < 0 || nx >= n || ny < 0 || ny >= m)
                    continue;

                int nmask;
                if(g[nx][ny] == '#')
                    nmask = mask | (1 << (nt[nx][ny]));
                else
                    nmask = mask;

                if(seen[nx][ny][nmask])
                    continue;
                Q.push({{nx, ny}, nmask});
                dist[nx][ny][nmask] = dist[x][y][mask] + 1;
                seen[nx][ny][nmask] = 1;
            }
        }

        cout << dist[start.first][start.second][(1 << nuts) - 1] << endl;
    }
}
