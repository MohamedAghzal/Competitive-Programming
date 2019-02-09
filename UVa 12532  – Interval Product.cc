#include <bits/stdc++.h>

using namespace std;
const int N = (int) 2e5;
int t[4*N + 1], a[N];

int get(int a, int b){
  if(a * b == 0) return 0;
  if(a * b < 0) return -1;
  return 1;
}

void build(int node, int start, int end){
  if(start == end){
    t[node] = a[start];
    return;
  }

  int mid = (start + end) >> 1;
  build(2*node, start, mid);
  build(2*node + 1, mid + 1, end);

  t[node] = get(t[2*node], t[2*node + 1]);
}

void update(int node, int start, int end, int i, int v){
  if(start == end){
    a[i] = v;
    t[node] = v;
    return;
  }

  int mid = (start + end) >> 1;
  if (i <= mid) update(2*node, start, mid, i, v);
  else update(2*node + 1, mid + 1, end, i, v);
  t[node] = get(t[2*node], t[2*node + 1]);
}

int query(int node, int start, int end, int l, int r){
  if(r < start || l > end) return 1;
  if(l <= start && r >= end) return t[node];

  int mid = (start + end) >> 1;
  int x = query(2*node, start, mid, l, r);
  int y = query(2*node + 1, mid + 1, end, l, r);
  return get(x, y);
}

int main() {
  int n, k;
  while(cin >> n >> k){
    memset(t, 0, sizeof t);

    for(int i = 1; i <= n; i++){
      scanf("%d", &a[i]);
    }

    build(1, 1, n);

    while(k--){
      char c;
      cin >> c;
      if(c == 'C'){
        int i, v;
        cin >> i >> v;
        update(1, 1, n, i, v);
      } else {
        int l, r;
        cin >> l >> r;
        int prod = query(1, 1, n, l, r);
        if(prod < 0){
          cout << "-";
        } else if(prod > 0) {
          cout << "+";
        } else {
          cout << "0";
        }
      }
    }

    cout << endl;
  }

  return 0;
}
