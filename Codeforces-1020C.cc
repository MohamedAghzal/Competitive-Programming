#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <unordered_map>
#include <algorithm>
#include <climits>

using namespace std;

typedef pair<int, int> pii;
unordered_map <int, int> id;

bool cmp(priority_queue <pii, vector<pii>, greater<pii>> a, 
         priority_queue <pii, vector<pii>, greater<pii>> b){
  return a.size() > b.size();
}

long long get(int z, unordered_map <int, int> cnt, int m, 
              vector <priority_queue<pii, vector<pii>, greater<pii>>> g, 
              priority_queue <pii, vector<pii>, greater<pii>> Q){
                  
  unordered_map <int, bool> used;

  long long ans = 0;
  for(int i = 2; i <= m; i++){
    while(g[i].size() >= z){
        pii t = g[i].top();
        g[i].pop();
        ans += (long long) t.first;
        used[t.second] = true;
        cnt[1]++;
    }
  }

  while(!Q.empty()){
    if(cnt[1] >= z) break;
    pii t = Q.top();
    Q.pop();

    if(!used[t.second] && id[t.second] != 1){
      ans += (long long) t.first;
      cnt[1]++;
      used[t.second] = true;
    }
  }
  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n, m;
  cin >> n >> m;
  vector <priority_queue<pii, vector<pii>, greater<pii>>> g(m + 1);
  priority_queue <pii, vector<pii>, greater<pii>> Q;
  unordered_map <int, int> cnt;
  unordered_map <int, int> cost;

  for(int i = 1; i <= n; i++){
    int x, y;
    cin >> x >> y;

    Q.push({y, i});
    g[x].push({y, i});
    cnt[x]++;
    id[i] = x;
    cost[i] = y;
  }

  sort(g.begin() + 2, g.end(), cmp);
  long long ans = (long long) 1e12;

  for(int i = 1; i <= n; i++){
    ans = min(ans, get(i, cnt, m, g, Q));
  }
  cout << ans;
  return 0;
}
