#include <bits/stdc++.h>

using namespace std;
const int N = 150, M = 15, MOD = (int) 1e9 + 7;
int dp[N][M][1 << M];
int n, m;

int get(int pos, int digit, int mask){
    if(pos == m)
        return 0;

    if(dp[pos][digit][mask] != -1)
        return dp[pos][digit][mask];

    int ans = (mask == (1 << n) - 1);
    if(digit > 0){
        ans += get(pos + 1, digit - 1, mask | (1 << (digit - 1)));
        ans %= MOD;
    }

    if(digit < n - 1){
        ans += get(pos + 1, digit + 1, mask | (1 << (digit + 1)));
        ans %= MOD;
    }

    return dp[pos][digit][mask] = (ans % MOD);
}

int main(){
    int T;
    scanf("%d", &T);

    while(T--){
        scanf("%d %d", &n, &m);

        int ans = 0;
        memset(dp, -1, sizeof dp);
        for(int i = 1; i < n; i++){
            ans += get(0, i, (1 << i));
            ans %= MOD;
        }
        printf("%d\n", ans);
    }

    return 0;
}
