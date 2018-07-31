#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair <int, int> a, pair <int, int> b){
   return (a.first - a.second) > (b.first - b.second);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n, m;
  cin >> n >> m;
  vector <pair<int, int>> songs(n);
  long long sum = 0, acc = 0;
  for(auto &e: songs){
    cin >> e.first >> e.second;
    sum += e.first;
    acc += e.second;
    if(acc > m){
      cout << -1;
      return 0;
    }
  }
  sort(songs.begin(), songs.end(), cmp);
  long long ans = 0;
  for(auto e: songs){
    if(sum <= m) break;
    sum -= (e.first - e.second);
    ans++;
  }
  cout << (sum <= m? ans: -1);
  return 0;
}
