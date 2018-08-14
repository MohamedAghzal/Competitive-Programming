#include <bits/stdc++.h>

using namespace std;
const int N = 1645;
int p[N];

int dfs(int i, int cnt[]){
  if(cnt[i] > 0) return i;
  cnt[i]++;
  return dfs(p[i], cnt);
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int cnt[N];

  int n;
  cin >> n;

  for(int i = 1; i <= n; i++){
    cin >> p[i];
  }

  vector <int> ans(n + 1);
  for(int i = 1; i <= n; i++){
    memset(cnt, 0, sizeof cnt);
    ans[i] = dfs(i, cnt);
  }

  for(int i = 1; i <= n; i++){
    cout << ans[i] << ' ';
  }

  return 0;
}
