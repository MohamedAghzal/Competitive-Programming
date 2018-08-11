#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <stack>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  string s;
  cin >> s;

  set <char> open;
  open.insert('<');
  open.insert('{');
  open.insert('[');
  open.insert('(');

  map <char, char> match;
  match['<'] = '>';
  match['{'] = '}';
  match['['] = ']';
  match['('] = ')';

  stack <int> S;
  int ans = 0;
  for(int i = 0; i < s.length(); i++){
    if(open.count(s[i])){
      S.push(i);
    } else {
      if(S.empty()){
        cout << "Impossible";
        return 0;
      }
      int j = S.top();
      S.pop();
      ans += (s[i] != match[s[j]]);
    }
  }

  if(!S.empty()){
    cout << "Impossible";
    return 0;
  }

  cout << ans;
  return 0;
}
