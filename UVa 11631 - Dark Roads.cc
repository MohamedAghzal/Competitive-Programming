#include <bits/stdc++.h>

using namespace std;

typedef pair <int, pair<int, int>> ppi;

const int N = (int) 2e5 + 5;
int p[N], r[N];

int find(int u){
    return (p[u] == u? u: find(p[u]));
}

void unite(int u, int v){
    u = find(u);
    v = find(v);
    if(u != v){
        if(r[u] > r[v]){
            p[u] = v;
            r[u] += r[v];
        } else {
            p[v] = u;
            r[v] += r[u];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    while(true){
        int n, m;
        cin >> n >> m;
        if(m == 0 && n == 0)
            break;
        vector <ppi> edges;
        int total = 0;
        for(int i = 0; i < m; i++){
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back({w, {u, v}});
            total += w;
        }

        sort(edges.begin(), edges.end());

        for(int i = 0; i <= n; i++){
            p[i] = i;
            r[i] = 1;
        }

        int mn_cost = 0;
        for(int i = 0; i < m; i++){
            ppi front = edges[i];
            if(find(front.second.first) != find(front.second.second)){
                unite(front.second.first, front.second.second);
                mn_cost += front.first;
            }
        }

        cout << total - mn_cost << endl;
    }

    return 0;
}
