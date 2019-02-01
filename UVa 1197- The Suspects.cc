#include <bits/stdc++.h>

using namespace std;

const int N = (int) 3e5 + 10;
int p[N];
int find(int u){
  return p[u] == u? u: find(p[u]); 
}

void unite(int u, int v){
  u = find(u);
  v = find(v);
  p[u] = v;
}

int main() {
  while(true){
    int n, m;
    scanf("%d %d", &n, &m);

    if(n == 0 && m == 0) break;
    for(int i = 0; i < n; i++){
      p[i] = i;
    }

    for(int i = 0; i < m; i++){
      int k;
      scanf("%d", &k);
      vector <int> a(n);
      for(int i = 0; i < k; i++){
        scanf("%d", &a[i]);
        if(i > 0) unite(a[i], a[i - 1]);
      }
    }

    int target = find(0), ans = 1;
    for(int i = 1; i < n; i++){
      ans += (find(i) == target);
    }

    printf("%d\n", ans);
  }

  return 0;
}
