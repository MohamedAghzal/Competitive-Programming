#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;
const int N = 1500, M = 5;
int a[M][N], id[M][N];
int dp[N];

bool valid(int i, int j, int k){
    int x = a[0][i], y = a[0][j];

    for(int i = 0; i < k; i++){
        if(id[i][x] > id[i][y]){
           return false;
        }
    }

    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;

    for(int i = 0; i < k; i++){
        for(int j = 0; j < n; j++){
           cin >> a[i][j];
           id[i][a[i][j]] = j;
        }
    }

    int ans = 0;
    for(int i = n - 1; i >= 0; i--){
        dp[i] = 1;
        for(int j = i + 1; j < n; j++){
            if(valid(i, j, k)){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }

    cout << ans;
    return 0;
}
