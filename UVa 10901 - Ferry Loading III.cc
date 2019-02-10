#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> pii;

int main(){
  ios_base::sync_with_stdio(false); 
  cin.tie(0); cout.tie(0);

  int T;
  cin >> T;
  while(T--){
    int n, t, m;
    cin >> n >> t >> m;

    int added = 0;
    queue <pii> left, right;
    for(int i = 1; i <= m; i++){
      int k;
      string side;
      cin >> k >> side;

      if(side == "left"){
        left.push({i, k});
      } else {
        right.push({i, k});
      }
    }
    
    vector <int> ans(m + 1);
    int time = 0, bank = 0;
    while(!left.empty() || !right.empty()){
      int added = 0;
      if(bank == 0){
        while(added < n && !left.empty() && left.front().second <= time){
          pii top = left.front();
          left.pop();

          ans[top.first] = time + t;
          added++;
        } 
      } else {
        while(added < n && !right.empty() && right.front().second <= time){
          pii top = right.front();
          right.pop();

          ans[top.first] = time + t;
          added++;
        }
      }

      if(!added && (right.empty() || right.front().second > time) && (left.empty() || left.front().second > time)){
        if(right.empty()){
          time = left.front().second;
        } else if (left.empty()){
          time = right.front().second;
        } else {
          time = min(right.front().second, left.front().second);
        }

       time -= t;
       bank ^= 1;
      }
      time += t;
      bank ^= 1;
    }

    for(int i = 1; i <= m; i++){
      cout << ans[i] << endl;
    }
    if(T) cout << endl;
  }

  return 0;
}
