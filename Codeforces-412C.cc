#include <iostream>
#include <vector>
#include <cstdio>
#include <unordered_map>
#include <algorithm>
#include <cctype>

using namespace std;
int N = int(1e5) + 5;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;

  vector <string> seq(n);
  for(int i = 0; i < n; i++){
    cin >> seq[i];
  }

  vector <unordered_map<char, int>> f(int(seq[0].length()));

  for(int i = 0; i < n; i++){
    for(int j = 0; j < seq[i].length(); j++){
      if(isalpha(seq[i][j])){
          f[j][seq[i][j]]++;
      }
    }
  }

  string ans = "";
  for(int i = 0; i < f.size(); i++){
    if(f[i].size() == 0){
      ans += "a";
    }
    else if(f[i].size() == 1){
      for(auto e: f[i]){
        ans += e.first;
      }
    } else {
      ans += "?";
    }
  }

  cout << ans;
  return 0;
}
