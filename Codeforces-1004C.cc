#include <iostream>
#include <vector>
#include <cstdio>
#include <unordered_map>
#include <set>

using namespace std;

int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

   int n;
   cin >> n;

   set <int> cnt;
   unordered_map <int, int> f;
   vector <int> v(n);

   for(auto &e: v){
      cin >> e;
      f[e] = (int) cnt.size();
      cnt.insert(e);
   }

   long long ans = 0;
   for(auto e: f){
      ans += (long long) e.second;
   }

   cout << ans;
   return 0;
}
