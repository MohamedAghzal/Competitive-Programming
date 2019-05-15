#include <bits/stdc++.h>

using namespace std;

const int N = 1750;
int dp[N][N][20], p[N];
vector <int> primes;
int s;

void sieve(){
    for(int i = 2; i < N; i++){
        int k = 0;
        if(!p[i]){
            primes.push_back(i);
            for(int j = 2 * i; j < N; j += i){
                p[j] = true;
            }
        }
    }
}

long long get(int n, int k, int pos){
    if(pos == primes.size() || n < 0 || k < 0)
        return 0;
    if(n == 0 && k == 0)
        return 1;
    if(dp[n][pos][k] != -1)
        return dp[n][pos][k];

    return dp[n][pos][k] = get(n - primes[pos], k - 1, pos + 1) + get(n, k, pos + 1);
}

int main(){
   sieve();
   while(true){
      int n, k;
      scanf("%d %d", &s, &k);
      if(s == 0 && k == 0) break;
      memset(dp, -1, sizeof dp);
      printf("%lld\n", get(s, k, 0));
   }

   return 0;
}
