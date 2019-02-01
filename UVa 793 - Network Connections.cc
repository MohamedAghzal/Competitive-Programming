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
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int T;
  cin >> T;

  while(T--){
    int n;
    cin >> n;
    cin.ignore();
    for(int i = 1; i <= n; i++){
      p[i] = i;
    }
    
    int good = 0, bad = 0;
    while(true){
      string line;
      if(!getline(cin, line) || line == ""){
        break;
      }
 
      char c;
      int u, v;
      sscanf(line.c_str(), "%c %d %d", &c, &u, &v);
      if(c == 'c'){
        unite(u, v);
      } else {
        if(find(u) == find(v)){
          good++;
        } else {
          bad++;
        }
      }
    }
    
    printf("%d,%d\n", good, bad);
    if(T) puts("");
  }

  return 0;
}

