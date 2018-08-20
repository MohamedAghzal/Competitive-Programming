#include <iostream>
#include <vector>
#include <set>
using namespace std;

int find(vector <int>& v, int x){
  return v[x] == -1? x : find(v, v[x]);
}

void unite(vector <int>& v, int x, int y){
  int xpos = find(v, x);
  int ypos = find(v, y);
  v[xpos] = ypos;
}

int main() {
  int n; cin >> n;
  string a; cin >> a;
  string b; cin >> b;
  vector <int> uf(1000010, -1);
  vector <pair <int, int>> ans;
  
  for(int i = 0; i < n; i++){
    int x = a[i] - 'a', y = b[i] - 'a';
    if(x == y) continue;
    if(find(uf, x) != find(uf, y)){
      ans.push_back({x, y});
      unite(uf, x, y);
    }
  }
  
  
  cout << int(ans.size()) << endl;
  for(auto  e : ans){
    cout << char(e.first + 'a') << ' ' << char(e.second + 'a') << endl;
  }
  
  return 0;
}
