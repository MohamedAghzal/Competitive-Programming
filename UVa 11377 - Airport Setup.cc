#include <bits/stdc++.h>

using namespace std;

const int INF = (int) 1e9;
typedef pair <int, int> pii;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;

    int c = 0;
    while(T--){
        int n, m, k;
        cin >> n >> m >> k;

        vector <bool> airport(n + 1, 0);
        for(int i = 0; i < k; i++){
            int city;
            cin >> city;
            airport[city] = 1;
        }

        vector <vector <int>> g(n + 1);

        while(m--){
            int u, v;
            cin >> u >> v;

            g[u].push_back(v);
            g[v].push_back(u);
        }

        int q;
        cin >> q;

        cout << "Case " << ++c << ":\n";
        while(q--){
            int from, to;
            cin >> from >> to;

            if(from == to){
                cout << 0 << endl;
                continue;
            }
            priority_queue <pii, vector <pii>, greater <pii>> Q;
            vector <int> dist(n + 1, INF);
            Q.push({airport[from] ^ 1, from});
            dist[from] = airport[from] ^ 1;
            while(!Q.empty()){
                pii t = Q.top();
                Q.pop();

                int u = t.second;
                int d = t.first;

                if(d > dist[u]) continue;

                for(int v: g[u]){
                    int add = (airport[v] ^ 1);
                    if(dist[u] + add < dist[v]){
                        dist[v] = dist[u] + add;
                        Q.push({dist[u] + add, v});
                    }
                }
            }

            cout << (dist[to] == INF? -1: dist[to]) << endl;
        }

        cout << endl;
    }

    return 0;
}
