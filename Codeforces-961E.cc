#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int getSum(vector <int> &BIT, int x){
  int sum = 0;
  while(x){
    sum += BIT[x];
    x -= x & (-x);
  }
  return sum;
}

void update(vector <int> &BIT, int x, int a){
  for(int i = x; i < BIT.size(); i += i & (-i)){
    BIT[i] += a;
  }
}

long long calc(vector <int> &BIT, int a, int b){
  return getSum(BIT, a) - getSum(BIT, b);
}

int main(){
  int n;
  scanf("%d", &n);
  
  vector <int> v(n + 1);
  vector <vector<int>> g(n + 1);
  vector <int> f(n + 1, 0);
  for(int i = 1; i <= n; i++){
    scanf("%d", &v[i]);
    v[i] = min(v[i], n);
    int e = min(v[i], i - 1);
    g[e].push_back(i - 1);
  }
  
  long long ans = 0;
  for(int i = 1; i <= n; i++){
    update(f, v[i], 1);
    for(auto e: g[i]){
      ans += calc(f, n, e);
    }
  }
  
  printf("%lld", ans);
  return 0;
}
