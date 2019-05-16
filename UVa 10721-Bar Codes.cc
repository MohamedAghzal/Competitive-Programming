#include <bits/stdc++.h>

using namespace std;
const int N = 55;
typedef long long ll;
ll dp[N][N][N];

ll get(int n, int k, int m, int w){
    if(n == 0 && k == 0) return 1;
    if(k <= 0 || m <= 0 || n <= 0) return 0;
    if(dp[n][k][m] != -1) return dp[n][k][m];
    return dp[n][k][m] = get(n - 1, k, m - 1, w) + get(n - 1, k - 1, w, w);
}

int main(){
    int n, m, k;
    while(scanf("%d %d %d", &n, &k, &m) != EOF){
        memset(dp, -1, sizeof dp);
        printf("%lld\n", get(n, k, m, m));
    }
}
