T#include <bits/stdc++.h>

using namespace std;

int main(void){
  int T;
  cin >> T;

  while(T--){
    int x, y;
    cin >> x >> y;

    int h = (x + y);
    int g = (x - y);

    if((h % 2) || (g % 2) || x < y) cout << "impossible" << endl;
    else cout << h / 2 << ' ' << g / 2 << endl;
  }

  return 0;
}
