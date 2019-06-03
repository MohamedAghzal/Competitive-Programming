#include <bits/stdc++.h>

using namespace std;

const int N = 100100;
int seen[N], vis[N], cnt;
stack <int> S;
vector <int> g[N], t[N];
set <int> scc;

void dfs(int u){
    if(seen[u])
        return;
    seen[u] = 1;
    for(int v: g[u]){
        dfs(v);
    }
    S.push(u);
}

void get(int u){
    if(vis[u])
        return;
    vis[u] = 1;
    scc.insert(u);
    for(int v: t[u]){
        get(v);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;

    while(T--){
        int m, n;
        cin >> n >> m;

        for(int i = 0; i < N; i++){
            seen[i] = 0;
            vis[i] = 0;
            t[i].clear();
            g[i].clear();
        }
        while(m--){
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            t[v].push_back(u);
        }

        for(int i = 1; i <= n; i++){
            dfs(i);
        }

        int cur = 1;

        unordered_map <int, bool> comp;
        while(!S.empty()){
            int u = S.top();
            S.pop();
            scc.clear();
            get(u);

            bool out = false;
            for(int v: scc){
                for(int k: t[v]){
                    if(!scc.count(k)){
                        out = true;
                    }
                }
            }

            if(!scc.empty()) comp[cur++] = (out);
        }

        int ans = 0;
        for(int i = 1; i < cur; i++){
            ans += (!comp[i]);
        }

        cout << ans << endl;
    }

    return 0;
}
