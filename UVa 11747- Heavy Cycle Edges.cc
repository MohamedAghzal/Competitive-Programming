#include <bits/stdc++.h>

using namespace std;

typedef pair <int, pair <int, int>> ppi;

const int N = 1500;

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

        if(n == 0 && m == 0)
            break;

        vector <ppi> edges;
        while(m--){
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back({w, {u, v}});
        }

        for(int i = 0; i < N; i++){
            p[i] = i;
            r[i] = i;
        }

        sort(edges.begin(), edges.end());

        set <int> S;
        for(int i = 0; i < edges.size(); i++){
            ppi top = edges[i];
            int u = top.second.first;
            int v = top.second.second;
            if(find(u) == find(v)){
                S.insert(edges[i].first);
            } else {
                unite(u, v);
            }
        }
        if(S.empty()){
            cout << "forest" << endl;
        } else {
            for(auto it = S.begin(); it != S.end();){
                cout << *it;
                if(++it == S.end()){
                    cout << endl;
                } else {
                    cout << ' ';
                }
            }
        }
    }

    return 0;
}
