#include <bits/stdc++.h>

using namespace std;
const int N = 2005;
int bad[N][N], seen[N];

void dfs(vector <vector<int>> &g, set <int> &S, int i){
   if(seen[i]) return;
   seen[i] = 1;
   S.insert(i);
   for(int u: g[i]){
     if(seen[u]) continue;
     dfs(g, S, u);
   }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;

  int k;
  cin >> k;

  vector <vector<int>> g(n + 1);
  for(int i = 0; i < k; i++){
    int x, y;
    cin >> x >> y;

    g[x].push_back(y);
    g[y].push_back(x);
  }

  int m;
  cin >> m;

  for(int i = 0; i < m; i++){
    int x, y;
    cin >> x >> y;

    bad[x][y] = 1;
  }

  int ans = 0;
  for(int i = 1; i <= n; i++){
    if(seen[i]) continue;
    set <int> S;
    dfs(g, S, i);

    bool valid = true;
    for(int u: S){
      for(int v: S){
        if(u == v) continue;
        if(bad[u][v]){
          valid = false;
          break;
        }
      }
    }

    if(valid){
      int s = (int) S.size();
      ans = max(ans, s);
    }
  }

  cout << ans;
  return 0;
}
