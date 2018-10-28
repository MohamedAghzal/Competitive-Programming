#include <bits/stdc++.h>

using namespace std;
const int N = (int) 1e6 + 5;

typedef struct{
  int open, closed, len;
}seq;

seq t[4*N + 1];
char s[2*N];

seq combine(seq a, seq b){
   seq ans;
   ans.open = a.open + b.open - min(a.open, b.closed);
   ans.closed = b.closed + a.closed - min(a.open, b.closed);
   ans.len = a.len + b.len + min(a.open, b.closed);
   return ans;
}

void build(int node, int start, int end){
    if(start == end){
      if(s[start] == '('){
        t[node].open = 1;
      } else {
        t[node].closed = 1;
      }
      return;
    }

    int mid = (start + end) / 2;
    build(2*node, start, mid);
    build(2*node + 1, mid + 1, end);

    t[node] = combine(t[2*node], t[2*node + 1]);
}

seq query(int node, int start, int end, int l, int r){
   if(l > r){
     seq ans;
     ans.open = 0;
     ans.closed = 0;
     ans.len = 0;
     return ans;
   }

   if(l == start && r == end){
     return t[node];
   }

   int mid = (start + end) / 2;
   return (combine(query(2*node, start, mid, l, min(r, mid)),
                   query(2*node + 1, mid + 1, end, max(l, mid + 1), r)));
}

int main(){
   scanf("%s", s);

   int q;
   scanf("%d", &q);

   int n = strlen(s);

   build(1, 0, n - 1);

   while(q--){
     int l, r;
     scanf("%d %d", &l, &r);

     printf("%d\n", 2 * query(1, 0, n - 1, l - 1, r - 1).len);
   }

   return 0;
}
