#include <bits/stdc++.h>

using namespace std;
const int N = 250;
vector <int> g[N];
int seen[N];

void mark(int u){
    if(seen[u]) return;
    seen[u] = 1;
    for(int v: g[u]){
        mark(v);
    }
}

int bfs(int n, int source){
    vector <int> color(n + 1, -1);
    queue <int> Q;
    unordered_map <int, int> cnt;

    Q.push(source);
    color[source] = 0;
    cnt[0]++;
    bool colorable = true;
    while(!Q.empty() && colorable){
        int u = Q.front();
        Q.pop();
        for(int v: g[u]){
            if(color[v] == -1){
                color[v] = color[u] ^ 1;
                ++cnt[color[v]];
                Q.push(v);
            } else if(color[v] == color[u]){
                colorable = false;
            }
        }
    }

    if(!colorable) return -1;
    return max(1, min(cnt[0], cnt[1])); 

}

int main(){
    int T;
    scanf("%d", &T);

    while(T--){
       int n, m;
       scanf("%d %d", &n, &m);

       for(int i = 0; i < N; i++){
            g[i].clear();
       }

       while(m--){
            int u, v;
            scanf("%d %d", &u, &v);

            g[u].push_back(v);
            g[v].push_back(u);
       }

       memset(seen, 0, sizeof seen);
       int ans = 0;
       for(int u = 0; u < n; u++){
          if(!seen[u]){
             int needed = bfs(n, u);
             if(bfs(n, u) != -1){
                ans += needed;
             } else {
                ans = -1;
                break;
             }
             mark(u);
          }
       }

       printf("%d\n", ans);
    }

    return 0;
}
