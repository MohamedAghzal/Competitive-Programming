#include <iostream>
#include <vector>

using namespace std;
const int N = (int) 1e5 + 5;
int dp[2][N];

bool check(int l, int r, int k){
  return(dp[0][r] - dp[0][l - 1] <= k || dp[1][r] - dp[1][l - 1] <= k);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n, k;
  cin >> n >> k;

  string s;
  cin >> s;

  dp[0][0] = s[0] == 'a';
  dp[1][0] = s[0] == 'b';

  for(int i = 1; i < n; i++){
    if(s[i] == 'a'){
      dp[0][i] = dp[0][i - 1] + 1;
      dp[1][i] = dp[1][i - 1];
    } else {
      dp[0][i] = dp[0][i - 1];
      dp[1][i] = dp[1][i - 1] + 1;
    }
  }

  int ans = 0;
  for(int i = 0; i < n; i++){
    int l = 0;
    int r = i;

    while(l <= r){
      int mid = (l + r) >> 1;
      if(check(mid, i, k)){
        ans = max(ans, i - mid + 1);
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
  }

  cout << ans;
  return 0;
}
