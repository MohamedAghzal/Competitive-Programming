#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   int n, m;
   cin >> n >> m;
   
   vector <int> a(n);
   map <int, int> occ;
   for(int i = 0; i < n; i++){
     cin >> a[i];
     occ[a[i]]++;
   }
   
   vector <int> b(m);
   for(int i = 0; i < m; i++){
     cin >> b[i];
   }

   sort(a.begin(), a.end());
   vector <int> ans(m);
   for(int i = 0; i < m; i++){
     int idx = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
     if(idx < 0){
       ans[i] = 0;
     } else {
       ans[i] = idx;
     }
     ans[i] += occ[b[i]];
   }

   for(int i = 0; i < m; i++){
     cout << ans[i] << ' ';
   }
   return 0;
}
