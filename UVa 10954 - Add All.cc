#include <bits/stdc++.h>

using namespace std;

int main() {
  while(true){
    int n;
    cin >> n;
    if(n == 0) break;

    priority_queue<int, vector <int>, greater<int>> Q;

    for(int i = 0; i < n; i++){
      int x;
      cin >> x;
      Q.push(x);
    }

    long long ans = 0;
    while(Q.size() > 1){
      int a = Q.top();
      Q.pop();
      int b = Q.top();
      Q.pop();
      ans += (a + b);
      Q.push(a + b);
    }

    cout << ans << endl;
  }
}
