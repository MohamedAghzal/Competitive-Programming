#include <bits/stdc++.h>

using namespace std;

const int N = 1500, MOD = (int) 1e9 + 7;

int dp[N][N][2];
string digits;
int cnt[N], k;

int make(int n){
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;

    if(cnt[n] != -1)
        return cnt[n];

    int nxt = __builtin_popcount(n);
    return cnt[n] = 1 + make(nxt);
}

int get(int pos, int one, int smaller, int last){
    if(pos == digits.length()){
        if(last && one == 1) return 0;
        return (make(one) == k);
    }

    if(dp[pos][one][smaller] != -1)
        return dp[pos][one][smaller];

    int d = digits[pos] - '0';
    int n = smaller? 1 : d;
    int ans = 0;

    for(int i = 0; i <= n; i++){
        ans += get(pos + 1, one + (i == 1),  smaller | (i < d), (i == 1));
        ans %= MOD;
    }

    return dp[pos][one][smaller] = ans % MOD;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> digits;
    cin >> k;

    memset(dp, -1, sizeof dp);
    memset(cnt, -1, sizeof cnt);

    cout << get(0, 0, 0, 0) << endl;
    return 0;
}
