#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n, k;
  cin >> n >> k;

  string s;
  cin >> s;

  int cnt = 0;
  string ans = "";
  for(int i = 0; i < n; i++){
    if(cnt == k){
     ans += s[i];
     continue;
    }

    int cand;
    char c;
    if(s[i] - 'a' > 'z' - s[i]){
      cand = s[i] - 'a';
      c = 'a';
    } else {
      cand = 'z' - s[i];
      c = 'z';
    }

    if(cnt + cand < k){
     cnt += cand;
     ans += c;
    } else {
     int next = (s[i] - 'a' + k - cnt < 26)? s[i] - 'a' + k - cnt: s[i] - 'a' + cnt - k;
     ans += char(next  + 'a');
     cnt = k;
    }
  }

  cout << (cnt == k? ans: "-1");
  return 0;
}
