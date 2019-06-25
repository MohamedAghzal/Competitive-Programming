#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
ll dp[13][1 << 13];
ll get(int pos, int mask){
    if(mask == (1 << n) - 1)
        return 1;
    if(dp[pos][mask] != -1)
        return dp[pos][mask];

    ll ans = 0;
    for(int i = 0; i < n; i++){
        if(!(mask & (1 << i)) && pos != i)
            ans += get(pos + 1, mask | (1 << i));
    }

    return dp[pos][mask] = ans;
}

int main(){
    ll fact[15];
    fact[0] = 1;
    for(int i = 1; i <= 15; i++){
        fact[i] = fact[i - 1] * i;
    }

    int T;
    cin >> T;

    while(T--){
        cin >> n;
        memset(dp, -1, sizeof dp);
        cout << get(0, 0) << '/' << fact[n] << endl;
    }
    return 0;
}
