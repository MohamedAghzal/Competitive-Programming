#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  
  int m, n;
  cin >> n >> m;

  if(m < n - 1){
    cout << "Impossible";
    return 0;
  }

  vector <pair<int, int>> g;
  int edges = 0;
  bool done = false;
  for(int i = 1; i < n; i++){
    for(int j = i + 1; j <= n; j++){
      if(__gcd(i, j) == 1){
        g.push_back({i, j});
        edges++;
      }
      if(edges == m){
        done = true;
        break;
      }
    }

    if(done){
      break;
    }
  }

  if(g.size() != m){
    cout << "Impossible";
    return 0;
  }

  cout << "Possible" << endl;
  for(auto e: g){
    cout << e.first << ' ' << e.second << endl;
  }

  return 0;
}
