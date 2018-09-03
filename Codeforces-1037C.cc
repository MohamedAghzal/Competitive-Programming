#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  
  int n;
  cin >> n;

  string a, b;
  cin >> a >> b;

  int ans = 0;
  bool s = false;
  for(int i = 0; i < n; i++){
    if(a[i] != b[i]){
      if(i + 1 < n && b[i + 1] != a[i + 1] && a[i] == b[i + 1] && a[i + 1] == b[i]){
        ans++;
        swap(a[i], a[i + 1]);
      }
    }
  }

  for(int i = 0; i < n; i++){
    ans += a[i] != b[i];
  }

  cout << ans;
  return 0;
}
