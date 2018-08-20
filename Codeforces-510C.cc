#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void top_sort(vector <vector<int>> &g, int V){
   vector <int> in_degree(V, 0);
   
   for(int i = 0; i < V; i++){
     for(auto e : g[i]){
       in_degree[e]++;
     }
   }
   
   queue <int> Q;
   vector <int> sorted;
   int isCycle = 0;
   
   for(int i = 0; i < V; i++){
     if(!in_degree[i]){
       Q.push(i);
     }
   }
   
   while(!Q.empty()){
     int curr = Q.front();
     Q.pop();
     sorted.push_back(curr);
     
     for(auto e : g[curr]){
       in_degree[e]--;
       if(!in_degree[e]) Q.push(e);
     }
     
     isCycle++;
   }
   
   if(isCycle != V){
     cout << "Impossible";
     return;
   }
   
   for(auto v : sorted){
     cout << char(v + 'a');
   }
   
}

int main(){
  int n; cin >> n;
  vector <string> authors(n);
  
  for(int i = 0; i < n; i++){
    cin >> authors[i];  
  }
  
  vector <vector<int>> g(26);
  
  for(int i = 0; i < n - 1; i++){
    string a = authors[i];
    string b = authors[i + 1];
    int cnt = 0;
    
    while(a[cnt] == b[cnt]){
      cnt++;
    }

    if(cnt == b.size() && a.size() > b.size() && a[cnt + 1] == b[cnt]){
      cout << "Impossible";
      return 0;
    }
    
    if(cnt < a.size() && b.size() > cnt){
      g[a[cnt] - 'a'].push_back(b[cnt] - 'a');  
    }
    
  }
  
  top_sort(g, 26);
  return 0;
}
