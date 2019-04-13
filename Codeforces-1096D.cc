#pragma GCC optimize("O2")
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <climits>

using namespace std;
const int N = (int) 1e5 + 5;
typedef long long ll;
ll f[5][N], a[N];
char t[N];
char h[] = "hard";

ll get(char * t, int i, int j, int n){
  ll ans = LONG_LONG_MAX;
  if(i < 4){
    if(f[i][j] != -1) return f[i][j];
    if(j == n) return 0;
    ans = min(ans, get(t, i, j + 1, n) + a[j]);
    if(t[j] == h[i]){
       ans = min(ans, get(t, i + 1, j + 1, n));
    } else {
       ans = min(ans, get(t, i, j + 1, n));
    }
    return f[i][j] = ans;
  }
  return ans;
}

int main() {
  memset(f, -1, sizeof f);
  int n;
  scanf("%d", &n);
  scanf("%s", t);
  for(int i = 0; i < n; i++){
    scanf("%lld", &a[i]);
  }

  printf("%lld\n", get(t, 0, 0, n));
  return 0;
}
