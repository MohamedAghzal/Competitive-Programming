#include <bits/stdc++.h>

using namespace std;

const int N = 20;
long long t[2 * (1 << N) + 1], A[(1 << N)];

void build(int node, int start, int end, bool op){
  if(start == end){
    t[node] = A[start];
    return;
  }

  int mid = (start + end) / 2;
  build(2*node, start, mid, !op);
  build(2*node + 1, mid + 1, end, !op);

  if(op){
    t[node] = t[2*node] | t[2*node + 1];
  } else {
    t[node] = t[2*node] ^ t[2*node + 1];
  }
}

void update(int node, int start, int end, int idx, int val, bool op){
  if(start == end){
    t[node] = val;
    return;
  }

  int mid = (start + end) / 2;
  if(start <= idx && idx <= mid){
    update(2*node, start, mid, idx, val, !op);
  } else {
    update(2*node + 1, mid + 1, end, idx, val, !op);
  }

  if(op){
    t[node] = t[2*node] | t[2*node + 1];
  } else {
    t[node] = t[2*node] ^ t[2*node + 1];
  }
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    for(int i = 0; i < (1 << n); i++){
      scanf("%lld", &A[i]);
    }

    build(1, 0, (1 << n) - 1, n & 1);

    while(m--){
      long long p, b;
      scanf("%lld %lld", &p, &b);
      update(1, 0, (1 << n) - 1, p - 1, b, n & 1);
      printf("%lld\n", t[1]);
    }

    return 0;
}
