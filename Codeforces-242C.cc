#include <bits/stdc++.h>

using namespace std;

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main(){
  int x, y, a, b;
  scanf("%d %d %d %d", &x, &y, &a, &b);

  int n;
  scanf("%d", &n);

  set <pair<int, int>> allowed;
  for(int i = 0; i < n; i++){
    int r, k, t;
    scanf("%d %d %d", &r, &k, &t);
    for(int j = k; j <= t; j++){
      allowed.insert({r, j});
    }
  }

  queue <pair<int, int>> Q;
  map <pair<int, int>, bool> seen;
  map <pair<int, int>, int> d;

  d[{x, y}] = 0;
  Q.push({x, y});
  seen[{x, y}] = true;

  while(!Q.empty()){
    pair <int, int> t = Q.front();
    Q.pop();

    if(t.first == a && t.second == b){
      printf("%d", d[t]);
      return 0;
    }

    for(int i = 0; i < 8; i++){
      pair <int, int> nxt;
      nxt = {t.first + dx[i], t.second + dy[i]};

      if(allowed.count(nxt)){
        if(!seen[nxt]){
          seen[nxt] = true;
          Q.push(nxt);
          d[nxt] = d[t] + 1;
        }
      }
    }
  }

  puts("-1");
  return 0;
}
