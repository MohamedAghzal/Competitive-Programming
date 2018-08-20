#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  long long n, q;
  cin >> n >> q;

  while(q--){
    long long x, y;
    cin >> x >> y;

    long long sum =  x + y;
    if(sum % 2 == 0){
      cout << (long long) ceil(1.0 * (n * x  - (n - y)) / 2)  << endl;
    } else {
      cout << (long long) ceil(1.0 * ((n * n) + n * x - (n - y)) / 2) << endl;
    }
  }
  return 0;
}
