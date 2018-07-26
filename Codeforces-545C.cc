#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;

  vector <pair<int, int>> trees(n);
  for(auto &e: trees){
    cin >> e.first >> e.second;
  }

  sort(trees.begin(), trees.end());
  int cut = 0;
  for(int i = 1; i < n - 1; i++){
    if(trees[i - 1].first < trees[i].first - trees[i].second){
       cut++;
    } else if(trees[i].first + trees[i].second < trees[i + 1].first){
       cut++;
       trees[i].first += trees[i].second;
    }
  }

  cout << (n <= 2? n: cut + 2);
  return 0;
}
