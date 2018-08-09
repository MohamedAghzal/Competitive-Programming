#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>

using namespace std;
const int N = 3590;
int seen[N][N], cnt[N][N];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n, m;
  cin >> n >> m;

  set <pair<int, int>> p;
  for(int i = 0; i < m; i++){
    int u, v;
    cin >> u >> v;
    p.insert({u, v});
    seen[u][v] = true;
  }

  for(auto e: p){
    for(int j = 1; j <= n; j++){
      if(seen[e.second][j]){
         cnt[e.first][j]++;
      }
    }
  }

  long long ans = 0;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      if(i == j) continue;
      ans += (long long) (cnt[i][j] * (cnt[i][j] - 1)) >> 1;
    }
  }

  cout << ans;
  return 0;
}
