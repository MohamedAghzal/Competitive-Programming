#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

bool go(vector<pair<pii, int>> &a, int k){

  int n = (int) a.size();
  int e = 0;
  
  for(int i = 0; i < n; i++){
    if(i == k) continue;
    if(e > a[i].first.first) return false;
    e = a[i].first.second;
  }

  return true;
}

int main(){

  int n;
  scanf("%d", &n);

  vector <pair<pii, int>> a(n);
  for(int i = 0; i < n; i++){
    scanf("%d %d", &a[i].first.first, &a[i].first.second);
    a[i].second = i + 1;
  }

  sort(a.begin(), a.end());

  vector <int> built;
  for(int i = 0; i < n; i++){
    if(go(a, i)){
      built.push_back(a[i].second);
    }
  }

  sort(built.begin(), built.end());
  
  printf("%d\n", (int) built.size());
  for(int e: built){
    printf("%d ", e);
  }

  return 0;
}
