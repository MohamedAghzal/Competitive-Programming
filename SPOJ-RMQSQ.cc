#include <bits/stdc++.h>

using namespace std;
const int N = (int) 1e6 + 5, K = (int) log2(N);
int t[N][K + 1];

int main(){

  int n;
  cin >> n;

  vector <int> a(n);
  for(int i = 0; i < n; i++){
    scanf("%d", &a[i]);
  }

  for(int i = 0; i < n; i++){
    t[i][0] = a[i];
  }

  for(int j = 1; j <= K; j++){
    for(int i = 0; i + (1 << j) <= n; i++){
        t[i][j] = min(t[i][j - 1], t[i + (1 << (j - 1))][j - 1]);
    }
  }

  int q;
  cin >> q;

  while(q--){
    int l, r;
    cin >> l >> r;
    int j = (int) log2(r - l + 1);
    cout << min(t[l][j], t[r - (1 << j) + 1][j]) << endl;
  }
  
  return 0;
}
