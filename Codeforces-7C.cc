#include<iostream>
#include<cstdio>

using namespace std;

long long gcdExtended(long long a, long long b, long long *x, long long *y) {
  if (a == 0) {
    *x = 0;
    *y = 1;
    return b;
  }
  long long x1, y1; 
  long long gcd = gcdExtended(b % a, a, &x1, &y1);
  *x = y1 - (b / a) * x1;
  *y = x1;
  return gcd;
}

int main(){
  long long A, B, C; 
  cin >> A >> B >> C;
  
  long long x, y;
  long long g = gcdExtended(A, B, &x , &y);
  
  if(C % g) cout << -1;
  else cout << - x * (C / g) << ' ' << - y * (C / g) << endl;
  
  return 0;
}
