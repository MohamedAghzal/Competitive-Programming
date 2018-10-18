#include <bits/stdc++.h>

using namespace std;
const int N = (int) 1e6 + 5;
const int MOD =  int(1e9) + 7;
long long f[N];

bool valid(int x, int a, int b){
  while(x){
    if(x % 10 != a && x % 10 != b){
      return false;
    }
    x /= 10;
  }
  return true;
}

long long binpow(long long a, long long b) {
    a %= MOD;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res % MOD;
}

long long inv(long long n){
   return binpow(n, MOD - 2);
}

long long C(long long n, long long k){
   return (((f[n] * inv(f[n - k])) % MOD) * (inv(f[k]))) % MOD;
}

int main(){

    long long a, b, n;
    scanf("%lld %lld %lld", &a, &b, &n);


    f[0] = 1;
    for(int i = 1; i <= n; i++){
      f[i] = (f[i - 1] * i) % MOD;
    }

    long long ans = 0;
    for(int i = 0; i <= n; i++){
      long long x = a * (long long) i + b * (n - (long long) i);
      if(valid(x, a, b)){
        ans = (ans + C(n, i) % MOD);
        ans %= MOD;
      }
    }

    printf("%lld", ans % MOD);
    return 0;
}
