#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cstring>

using namespace std;
const int N = 2150;
int p[N];

int depth(vector <int> &g, int i){
  if(p[i] != -1) return p[i];
  return p[i] = g[i] == -1? 0: depth(g, g[i]) + 1;
}

int main(){
  int n;
  cin >> n;

  vector <int> g(n + 1);
  for(int i = 1; i <= n; i++){
    cin >> g[i];
  }

  int ans = 1;
  memset(p, -1, sizeof p);
  for(int i = 1; i <= n; i++){
    ans = max(ans, depth(g, i) + 1);
  }
  cout << ans;
  return 0;
}
