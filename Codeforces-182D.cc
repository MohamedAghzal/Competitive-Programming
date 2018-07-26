#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <string>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  vector <string> s(2);

  cin >> s[0] >> s[1];

  if(s[0].length() > s[1].length()){
    swap(s[0], s[1]);
  }

  int ans = 0;
  int n = s[0].length();
  int m = s[1].length();

  for(int i = 0; i < n; i++){

    if(n % (i + 1) == 0 && m % (i + 1) == 0){
      bool valid = true;
      for(int j = 0; j < n; j += (i + 1)){
        if(!valid) break;
        if(s[0].substr(j, i + 1) != s[0].substr(0, i + 1)){
          valid = false;
        }
      }

      for(int j = 0; j < m; j += (i + 1)){
        if(!valid) break;
        if(s[1].substr(j, i + 1) != s[0].substr(0, i + 1)){
          valid = false;
        }
      }

      valid &= s[1].substr(0, i + 1) == s[0].substr(0, i + 1);
      ans += valid;
    }
  }

  cout << ans;
  return 0;
}
