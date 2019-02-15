#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = (int) 5e3;
int p[N];

int find(int u){
  return p[u] == u? u: find(p[u]);
}

void unite(int u, int v){
  int uset = find(u);
  int vset = find(v);

  p[uset] = vset;
}

int main(){
  int n;
  scanf("%d", &n);

  vector <pair<int, int>> destroy;
  
  for(int i = 1; i <= n; i++){
     p[i] = i;
  }
  
  for(int i = 0; i < n - 1; i++){
    int u, v;
    scanf("%d %d", &u, &v);
    if(find(u) == find(v)){
      destroy.push_back({u, v});
    } else {
      unite(u, v);
    }
  }

  set <int> S;
  for(int i = 1; i <= n; i++){
    if(find(i) == i){
      S.insert(i);
    }
  }

  vector <int> r;
  for(int e: S){
    r.push_back(e);
  }
  
  printf("%d\n", (int) destroy.size());
  for(int i = 0; i < destroy.size(); i++){
    printf("%d %d %d %d\n", destroy[i].first, destroy[i].second, r[i], r[i + 1]);
  }

  return 0;
}
