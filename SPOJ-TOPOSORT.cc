#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, m;
  cin >> n >> m;

  vector <vector<int>> g(n + 1);
  vector <int> deg(n + 1, 0);
  for(int i = 0; i < m; i++){
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    deg[v]++;
  }

  set <int> Q;
  for(int i = 1; i <= n; i++){
    if(!deg[i]){
      Q.insert(i);
    }
  }

  vector <int> sorted;
  while(!Q.empty()){
    int t = *Q.begin();
    Q.erase(*Q.begin());

    sorted.push_back(t);
    for(int e: g[t]){
      deg[e]--;
      if(!deg[e]){
        Q.insert(e);
      }
    }
  }

  if(sorted.size() != n){
    cout << "Sandro fails.";
  } else {
    for(int u: sorted){
      cout << u << ' ';
    }
  }

  return 0;
}
