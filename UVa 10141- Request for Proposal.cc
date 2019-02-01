#include <bits/stdc++.h>

using namespace std;

typedef tuple <string, double, int> tsdi;
map <string, int> order;

bool cmp(tsdi a, tsdi b){
  if(get <2>(a) > get <2> (b)) return true;
  if(get <2>(a) == get <2> (b) && get <1> (a) < get <1> (b)) return true;
  return order[get <0> (a)] < order[get <0> (b)];
}

int main(){
  int n, p;
  int cnt = 1;

  while(cin >> n >> p){
    order.clear();

    if(n == 0 && p == 0){
      return 0;
    }

    for(int i = 0; i < n; i++){
      string t;
      cin.ignore();
      getline(cin, t);
    }

    vector <tsdi> cand;
    for(int i = 0; i < p; i++){
      string option;
      getline(cin, option);
      order[option] = i;
      double d;
      int r;
      cin >> d >> r;
      cin.ignore();
      cand.push_back(make_tuple(option, d, r));

      for(int i = 0; i < r; i++){
        string q;
        getline(cin, q);
      }
    }

   sort(cand.begin(), cand.end(), cmp);
   if(cnt > 1) cout << endl;
   cout << "RFP #" << cnt++ << endl << get <0> (cand[0]) << endl;
  }

  return 0;
}
