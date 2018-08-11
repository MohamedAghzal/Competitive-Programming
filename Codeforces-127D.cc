#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;

vector <int> pre(string pat){

  int N = pat.length();
  vector <int> LPS(N);

  LPS[0] = 0;
  int i = 1, len = 0;
  while(i < N){
    if(pat[i] == pat[len]){
        len++;
        LPS[i] = len;
        i++;
    } else{
        if (len != 0){
          len = LPS[len - 1];
        } else {
          LPS[i] = 0;
          i++;
        }
    }
  }
  return LPS;
}

int compute(string pat, string s){

   int N = s.length();
   vector <int> LPS = pre(pat);

   int i = 0, j = 0, cnt = 0;
   while(i < N){
     if(pat[j] == s[i]){
        i++;
        j++;
     }

     if(j == pat.length()){
        cnt++;
        j = LPS[j - 1];
     } else if (i < N && pat[j] != s[i]){
       if(j > 0){
         j = LPS[j - 1];
       } else {
         i++;
       }
     }
   }
   return cnt;
}

int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

   string s;
   cin >> s;

   vector <int> L = pre(s);
   if(L[s.length() - 1] == 0){
    cout << "Just a legend";
    return 0;
   }

   string ans = s.substr(0, L[s.length() - 1]);
   if(L[s.length() - 1] >= s.length() / 2){
    L[s.length() - 1] = pre(ans)[ans.length() - 1];
   }
   if(L[s.length() - 1] == 0){
    cout << "Just a legend";
    return 0;
   }

   ans = s.substr(0, L[s.length() - 1]);
   if(compute(ans, s) > 2){
     cout << ans;
   } else {
     cout << "Just a legend";
   }

   return 0;
}
