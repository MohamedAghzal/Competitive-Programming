#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n, m;
  cin >> n >> m;

  vector <int> d(m), h(m);
  for(int i = 0; i < m; i++){
    cin >> d[i] >> h[i];
  }

  int ans = 0;
  for(int i = 0; i < m - 1; i++){
    if((d[i + 1] - d[i]) < abs(h[i + 1] - h[i])){
      cout << "IMPOSSIBLE";
      return 0;
    }

    ans = max(ans, max(h[i], h[i + 1]));
    ans = max(ans, max(h[i], h[i + 1]) + ((d[i + 1] - d[i]) - abs(h[i + 1] - h[i])) / 2);
  }

  cout << max(ans, max(h[0] + d[0] - 1, h[m - 1] - d[m - 1] + n));
  return 0;
}
