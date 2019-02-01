#include <bits/stdc++.h>

using namespace std;
typedef pair <string, string> pss;

int main(){
  vector <pss> dict;

  string word;
  map <string, int> cnt;
  while(cin >> word){
    if(word == "#") break;
    string t = "";
    for(char c: word){
      t += tolower(c);
    }

    sort(t.begin(), t.end());
    dict.push_back({word, t});
    cnt[t]++;
  }

  vector <string> ans;
  for(auto e: cnt){
    if(e.second == 1){
      for(auto k: dict){
        if(k.second == e.first){
          ans.push_back(k.first);
        }
      }
    }
  }

  sort(ans.begin(), ans.end());
  for(auto e: ans){
    cout << e << endl;
  }

  return 0;
}
