#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, s;
ll dp[50][300];

ll get(int pos, int sum){
    if(pos == n)
        return (sum >= s);
    if(dp[pos][sum] != -1)
        return dp[pos][sum];

    ll ans = 0;
    for(int side = 1; side <= 6; side++){
        ans += get(pos + 1, sum + side);
    }

    return dp[pos][sum] = ans;
}

ll power(ll a, ll b){
    ll res = 1;
    while(b){
        if(b & 1)
            res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

int main(){
    while(true){
        scanf("%d %d", &n, &s);
        if(n == 0 && s == 0)
            break;

        memset(dp, -1, sizeof dp);
        ll x = get(0, 0);
        ll y = power(6, n);
        ll g = __gcd(x, y);
        x /= g;
        y /= g;
        if(x % y == 0) printf("%lld\n", x / y);
        else printf("%lld/%lld\n", x, y);
    }
    return 0;
}
