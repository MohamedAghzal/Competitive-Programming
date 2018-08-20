#include <bits/stdc++.h>

using namespace std;
const int N = (int) 2e5 + 5;
int match[N], used[N];

int main(){
  int n, k;
  cin >> n >> k;

  string s;
  cin >> s;

  if(n == k){
   cout << s;
   return 0;
  }

  stack <int> S;
  memset(match, -1, sizeof match);

  for(int i = 0; i < s.length(); i++){
    if(s[i] == '('){
      S.push(i);
    }

    if(s[i] == ')'){
      int j = S.top();
      S.pop();
      match[j] = i;
    }
  }

  int cnt = 0;
  string ans = "";
  for(int i = 0; i < n; i++){
    if(used[i] || match[i] == -1) continue;
    used[i] = 1;
    used[match[i]] = 1;
    cnt += 2;
    if(cnt == k) break;
  }

  for(int i = 0; i < s.length(); i++){
    if(used[i]) cout << s[i];
  }
  return 0;
}
