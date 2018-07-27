#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  string num;
  cin >> num;

  long long mod_two = 0, mod_one = 0;
  long long ans = 0;
  for(char c: num){
     bool valid = false;
     int x = c - '0';

     if(x % 3 == 2){
       if(mod_one){
         valid = true;
       } else if(mod_two >= 2){
         valid = true;
       }
       mod_two++;
     } else if (x % 3 == 1) {
       if(mod_two){
         valid = true;
       } else if(mod_one >= 2){
         valid = true;
       }
       mod_one++;
     } else if (x % 3 == 0){
       valid = true;
     }
     if(valid){
       ans++;
       mod_one = 0;
       mod_two = 0;
     }
  }

  cout << ans;
  return 0;
}
