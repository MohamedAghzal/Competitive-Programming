#include <bits/stdc++.h>

using namespace std;

const int N = 50;
typedef unsigned long long ll;
ll k, n, r;

ll dp[N][N][N][2];

ll get(int x, int y, int peaks, int dir){
    if(y < 0 || x > 2 * n)
        return 0;
    if(x == 2 * n)
       return (y == 0 && peaks == r);
    if(dp[x][y][peaks][dir] != -1)
        return dp[x][y][peaks][dir];

    ll ans = 0;
    ans += get(x + 1, y + 1, peaks, 1);
    ans += get(x + 1, y - 1, peaks + (y == k && dir), 0);

    return dp[x][y][peaks][dir] = ans;
}

int main(){
    while(scanf("%d %d %d", &n, &r, &k) != EOF){
        memset(dp, -1, sizeof dp);
        printf("%llu\n", get(0, 0, 0, 0));
    }
    return 0;
}
