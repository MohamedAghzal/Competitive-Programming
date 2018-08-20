#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5;
int p[N], cost[N];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;

  vector <int> in_deg(n + 1);
  for(int i = 1; i <= n; i++){
    cin >> cost[i];
  }

  for(int i = 1; i <= n; i++){
    cin >> p[i];
    in_deg[p[i]]++;
  }

  queue <int> Q;
  vector <int> seen(n + 1);
  for(int i = 1; i <= n; i++){
    if(!in_deg[i]){
      Q.push(i);
      seen[i] = 1;
    }
  }

  while(!Q.empty()){
    int t = Q.front();
    Q.pop();
    in_deg[p[t]]--;
    if(!(in_deg[p[t]])){
      Q.push(p[t]);
      seen[p[t]] = 1;
    }
  }

  long long ans = 0;
  for(int i = 1; i <= n; i++){
    if(seen[i]) continue;
    int x = cost[i];
    for(int j = i; !seen[j]; j = p[j]){
      x = min(x, cost[j]);
      seen[j] = 1;
    }
    ans += x;
  }

  cout << ans;
  return 0;
}
