#include <bits/stdc++.h>

using namespace std;

const int INF = (int) 1e9;
const int N = 150;

int dp[N][N][N];
int a[N];
int n, k;

int get(int pos, int sum, int cnt){
    if(sum == 0)
        return 0;
    if(cnt > n)
        return INF;
    if(sum < 0 || pos >= k)
        return INF;
    if(dp[pos][sum][cnt] != -1)
        return dp[pos][sum][cnt];
    int ans;
    if(a[pos] == -1)
        ans = get(pos + 1, sum, cnt);
    else ans = min(a[pos] + get(pos, sum - pos - 1, cnt + 1), get(pos + 1, sum, cnt));

    return dp[pos][sum][cnt] = ans;
}

int main(){
    int T;
    cin >> T;

    while(T--){
        cin >> n >> k;

        for(int i = 0; i < k; i++){
            cin >> a[i];
        }

        memset(dp, -1, sizeof dp);
        int ans = get(0, k, 0);
        cout << (ans == INF? -1: ans) << endl;
    }

    return 0;
}
