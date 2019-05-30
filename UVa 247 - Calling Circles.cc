#include <bits/stdc++.h>

using namespace std;

const int N = 50;
stack <int> S;
int seen[N], vis[N];
vector <int> g[N], t[N], group;

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
    group.push_back(u);
    for(int v: t[u]){
        get(v);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int c = 0;
    while(true){
        int n, m;
        cin >> n >> m;
        if(n == 0 && m == 0) break;

        for(int i = 0; i < N; i++){
            g[i].clear();
            t[i].clear();
            seen[i] = 0;
            vis[i] = 0;
        }

        unordered_map <string, int> id;
        unordered_map <int, string> org;
        int val = 1;
        while(m--){
            string a, b;
            cin >> a >> b;

            if(!id[a]){
                id[a] = val;
                org[val] = a;
                val++;
            }

            if(!id[b]){
                id[b] = val;
                org[val] = b;
                val++;
            }

            g[id[a]].push_back(id[b]);
            t[id[b]].push_back(id[a]);
        }

        for(int i = 1; i <= n; i++){
            dfs(i);
        }

        vector <vector<int>> ans;
        while(!S.empty()){
            int u = S.top();
            S.pop();
            if(!org[u].empty()){
                group.clear();
                get(u);
                ans.push_back(group);
            }
        }
        if(c > 0) cout << endl;
        cout << "Calling circles for data set " << ++c << ":\n";
        for(vector <int> e: ans){
            for(int i = 0; i < e.size(); i++){
               cout << org[e[i]] << (i == e.size() - 1? "\n":", ");
            }
        }
    }

    return 0;
}
