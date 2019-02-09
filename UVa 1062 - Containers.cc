#include <bits/stdc++.h>

using namespace std;

int main(){
  string t;
  int c = 0;
  while(true){
    getline(cin, t);
    if(t == "end"){
      break;
    }

    vector <stack<char>> containers;
    for(int i = 0; i < t.size(); i++){
      bool found = false;
      for(int j = 0; j < containers.size(); j++){
        if(t[i] <= containers[j].top()){
          containers[j].push(t[i]);
          found = true;
          break;
        }
      }

      if(!found){
        stack <char> newCont;
        newCont.push(t[i]);
        containers.push_back(newCont);
      }
    }

    cout << "Case " << ++c << ": " << (int) containers.size() << endl;
  }

  return 0;
}
