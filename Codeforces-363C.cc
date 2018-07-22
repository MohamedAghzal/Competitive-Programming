#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  string s;
  cin >> s;

  int n = s.length();
  
  if(n < 3){
     cout <<s;
     return 0;
  }
  string constructed = "";
   
  constructed += s[0];
  constructed += s[1];
  for(int i = 2; i < n; i++){
     int l = constructed.length();
     if(s[i] == constructed[l - 1] && s[i] == constructed[l - 2]){
        continue;
     }

     if(l > 2 && s[i] == constructed[l - 1] && constructed[l - 2] == constructed[l - 3]){
        continue;
     }

     constructed += s[i];
  }

  cout << constructed;

  return 0;
}
