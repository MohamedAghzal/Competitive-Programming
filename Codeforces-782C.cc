#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
const int N = 200050;
int colors[N];
vector <int> g[N];

void dfs(int u, int p){
  int id = 1;

  for(int v: g[u]){
    if(v == p) continue;

    while(colors[u] == id || colors[p] == id){
      id++;
    }

    colors[v] = id++;
    dfs(v, u);
  }
}

int main(){

  int n;
  scanf("%d", &n);

  int deg = 0;
  for(int i = 0; i < n - 1; i++){
    int u, v;
    scanf("%d %d", &u, &v);

    g[u].push_back(v);
    g[v].push_back(u);

    deg = max(deg, (int) g[u].size());
    deg = max(deg, (int) g[v].size());
  }

  colors[1] = 1;
  dfs(1, 0);

  printf("%d\n", deg + 1);
  for(int i = 1; i <= n; i++){
    printf("%d ", colors[i]);
  }

  return 0;
}
