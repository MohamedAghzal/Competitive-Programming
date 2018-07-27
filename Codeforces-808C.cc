#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(pair<pair <int, int>, int> a, pair <pair<int, int>, int> b){
  return a.first.first > b.first.first;
}
bool rearrange(pair<pair <int, int>, int> a, pair<pair<int, int>,int> b){
  return a.second < b.second;
}
int main() {
  int n, w; cin >> n >> w;
  vector <pair<pair <int, int>, int>> v(n);
  for(int i = 0; i < n; i++){
    cin >> v[i].first.first;
    v[i].first.second = 0;
    v[i].second = i;
  }
  for(int i = 0; i < n; i++){
    v[i].first.second += v[i].first.first & 1? (v[i].first.first + 1) / 2: v[i].first.first / 2;
    w -= v[i].first.second;
    if(w < 0){
      cout << -1;
      return 0;
    }
  }
  if(w == 0) goto end;
  sort(v.begin(), v.end(), cmp);
  for(int i = 0; i < n; i++){
    while(v[i].first.second < v[i].first.first && w > 0){
      v[i].first.second++;
      w--;
    }
  }
  sort(v.begin(), v.end(), rearrange);
  end:
    for(auto e : v){
      cout << e.first.second << ' ';
    }
  return 0;
}
