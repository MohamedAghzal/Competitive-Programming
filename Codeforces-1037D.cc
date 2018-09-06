#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <unordered_map>

using namespace std;
unordered_map <int, int> pos;

bool cmp(int a, int b){
  return pos[a] < pos[b];
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;

  vector <set<int>> g(n + 1);
  for(int i = 0; i < n - 1; i++){
    int u, v;
    cin >> u >> v;
    g[u].insert(v);
    g[v].insert(u);
  }

  vector <int> a(n + 1);
  for(int i = 1; i <= n; i++){
    cin >> a[i];
    pos[a[i]] = i;
  }

  if(a[1] != 1){
    cout << "No";
    return 0;
  }

  queue <int> Q;
  unordered_map <int, int> p;
  p[1] = 1;
  Q.push(1);
  int cur = 1;

  while(!Q.empty()){
    int t = Q.front();
    Q.pop();

    if(t != a[cur]){
      cout << "No";
      return 0;
    }

    cur++;
    vector <int> v;
    for(int e: g[t]){
      if(!p[e]){
        v.push_back(e);
        p[e] = 1;
      }
    }
    sort(v.begin(), v.end(), cmp);
    for(int e: v){
      Q.push(e);
    }
  }

  cout << "Yes";
  return 0;
}
