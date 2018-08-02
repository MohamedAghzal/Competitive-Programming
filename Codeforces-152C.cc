#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;
const int MOD = (int) 1e9 + 7;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n, m;
  cin >> n >> m;

  vector <string> names(n);
  for(string &s: names){
     cin >> s;
  }

  vector <unordered_map<char, bool>> seen(m);
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      seen[j][names[i][j]] = true;
    }
  }

  long long ans = 1;
  for(int i = 0; i < m; i++){
    ans = (ans * (seen[i].size())) % MOD;
    ans %= MOD;
  }

  cout << ans;
  return 0;
}
