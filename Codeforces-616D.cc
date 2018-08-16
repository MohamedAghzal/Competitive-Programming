#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef pair <int, int> pii;

struct cmp {
    bool operator() (const pii& a, const pii& b) const {
        return a.second - a.first + 1 > b.second - b.first + 1;
    }
};

int main(){

  int n, k;
  scanf("%d %d", &n, &k);

  vector <int> v(n + 1);

  for(int i = 1; i <= n; i++){
    scanf("%d", &v[i]);
  }

  int l = 1, r = 1;

  set <pii, cmp> Q;
  unordered_set <int> seen;
  unordered_map <int, int> cnt;

  while(r <= n){
    if(seen.size() < k){ //add new element
      seen.insert(v[r]);
      Q.insert({l, r});
      cnt[v[r]]++;
      r++;
    } else if(seen.count(v[r])){ //still haven't found (k+1)th value
      cnt[v[r]]++;
      Q.insert({l, r});
      r++;
    } else {
      if(!(--cnt[v[l]])){
        seen.erase(v[l]);
      }
      l++;
    }

    if(l > r) break;
  }
  
  pair <int, int> ans = *(Q.begin());
  printf("%d %d", ans.first, ans.second);
  return 0;
}
