#include <iostream>
#include <cstring>

using namespace std;

int last[26], dist[26];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  string s;
  cin >> s;

  memset(last, -1, sizeof last);

  for(int i = 0; i < s.length(); i++){
    dist[s[i] - 'a'] = max(dist[s[i] - 'a'], i - last[s[i] - 'a']);
    last[s[i] - 'a'] = i;
  }


  for(int i = 0; i < 26; i++){
    dist[i] = max(dist[i], (int) s.length() - last[i]);
  }

  int ans = (int) 1e7;
  for(int i = 0; i < 26; i++){
    if(last[i] == -1) continue;
    ans = min(ans, dist[i]);
  }

  cout << ans;
  return 0;
}
