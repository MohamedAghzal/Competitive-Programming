#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
using namespace std;
int main() {
  int n, m; 
  scanf("%d %d", &n, &m);
  vector <int> state(n);
  
  for(int i = 0; i < n; i++){
    scanf("%d", &state[i]);
  }
  
  vector <vector<int>> g(n);
  vector <int> in_deg(n, 0);
  for(int i = 0; i < m; i++){
    int u, v; 
    scanf("%d %d", &u, &v);
    g[v].push_back(u);
    in_deg[u]++;
  }
  
  queue <int> P;
  queue <int> CP;
  for(int i = 0; i < n; i++){
    if(!in_deg[i]){
      if(state[i]){
        CP.push(i);
      } else {
        P.push(i);
      }
    }
  }
  
  vector <int> sorted;
  int ans = 0;
  while(!P.empty() || !CP.empty()){
    while(!P.empty()){ 
      int cur = P.front();
      P.pop();
      sorted.push_back(cur);
      for(auto e: g[cur]){
          in_deg[e]--;
          if(!in_deg[e]){
            if(state[e]){
              CP.push(e);
            } else {
              P.push(e);
          }
        }
      }
    }
    
    if(!CP.empty()){
      ans++;
    }
    
    while(!CP.empty()){
      int cur = CP.front();
      CP.pop();
      sorted.push_back(cur);
      for(auto e: g[cur]){
          in_deg[e]--;
          if(!in_deg[e]){
            if(state[e]){
              CP.push(e);
            } else {
              P.push(e);
          }
        }
      }
    }
  }
  
  printf("%d", ans);
  return 0;
}
