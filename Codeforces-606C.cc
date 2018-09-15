#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <cstdio>

using namespace std;
const int N = (int) 1e6 + 5;
int seen[N];

int main(){
  int n;
  scanf("%d", &n);

  vector <int> a(n + 1);
  for(int i = 1; i <= n; i++){
    scanf("%d", &a[i]);
  }

  if(is_sorted(a.begin(), a.end())){
    printf("0");
    return 0;
  }

  vector <int> t = a;
  reverse(t.begin(), t.end());

  if(is_sorted(t.begin(), t.end())){
    printf("%d", n - 1);
    return 0;
  }

  vector <int> f(n + 1, 0);
  for(int i = 1; i <= n; i++){
    f[a[i]] = f[a[i] - 1] + 1;
  }

  printf("%d", n - *max_element(f.begin(), f.end()));

  return 0;
}
