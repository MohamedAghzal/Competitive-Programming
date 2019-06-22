#include <bits/stdc++.h>

using namespace std;

const int N = 70, INF = (int) 1e9;

int g[N][N];
int dist[N][N][5], seen[N][N][5];

typedef struct state{
    int x, y;
    string dir;

    state(int a, int b, string t){
        x = a;
        y = b;
        dir = t;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    map <string, string> right, left;
    right["north"] = "east";
    right["east"] = "south";
    right["south"] = "west";
    right["west"] = "north";

    left["north"] = "west";
    left["west"] = "south";
    left["south"] = "east";
    left["east"] = "north";

    map <string, int> id;
    id["north"] = 0;
    id["east"] = 1;
    id["south"] = 2;
    id["west"] = 3;

    while(true){
        int n, m;
        cin >> n >> m;

        if(n == 0 && m == 0)
            break;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> g[i][j];

        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        string s;
        cin >> s;
        queue <state> Q;
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= m; j++){
                for(int k = 0; k < 4; k++){
                    dist[i][j][k] = INF;
                    seen[i][j][k] = false;
                }
            }
        }

        if(!(x1 <= 0 || x1 >= n || y1 <= 0 || y1 >= m || g[x1][y1] || g[x1 - 1][y1] || g[x1][y1 - 1] || g[x1 - 1][y1 - 1])){
            Q.push(state(x1, y1, s));
            dist[x1][y1][id[s]] = 0;
            seen[x1][y1][id[s]] = true;
        }
        while(!Q.empty()){
            auto t = Q.front();
            Q.pop();

            int i = t.x;
            int j = t.y;
            string d = t.dir;
            if(i == x2 && j == y2)
                break;
            if(!seen[i][j][id[right[d]]]){
                Q.push(state(i, j, right[d]));
                seen[i][j][id[right[d]]] = true;
                dist[i][j][id[right[d]]] = dist[i][j][id[d]] + 1;
            }

            if (!seen[i][j][id[left[d]]]){
                Q.push(state(i, j, left[d]));
                seen[i][j][id[left[d]]] = true;
                dist[i][j][id[left[d]]] = dist[i][j][id[d]] + 1;
            }

            pair <int, int> direction;
            if(d == "north"){
                direction = {-1, 0};
            } else if(d == "south") {
                direction = {1, 0};
            } else if(d == "west") {
                direction = {0, -1};
            } else {
                direction = {0, 1};
            }

            for(int k = 1; k <= 3; k++){
                int n_x = i + k * direction.first;
                int n_y = j + k * direction.second;
                if(n_x <= 0 || n_x >= n || n_y <= 0 || n_y >= m
                   || g[n_x][n_y] || g[n_x - 1][n_y] || g[n_x][n_y - 1] || g[n_x - 1][n_y - 1])
                    break;

                if(seen[n_x][n_y][id[d]])
                    continue;

                Q.push(state(n_x, n_y, d));
                dist[n_x][n_y][id[d]] = dist[i][j][id[d]] + 1;
                seen[n_x][n_y][id[d]] = true;
            }
        }

        int ans = INF;
        for(int i = 0; i < 4; i++){
           ans = min(ans, (int) dist[x2][y2][i]);
        }

        if(ans == INF)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }
}
