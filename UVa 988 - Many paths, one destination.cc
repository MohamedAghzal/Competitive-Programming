#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e4;
int n;
vector <int> g[N];
int dp[N];

int get(int u){
    if(g[u].empty())
        return 1;
    if(dp[u] != -1)
        return dp[u];

    int ans = 0;
    for(int v: g[u]){
        ans += get(v);
    }

    return dp[u] = ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 0;
    while(cin >> n){
        for(int i = 0; i < N; i++){
            g[i].clear();
        }
        for(int i = 0; i < n; i++){
            int c;
            cin >> c;

            for(int j = 0; j < c; j++){
                int v;
                cin >> v;

                g[i].push_back(v);
            }
        }

        memset(dp, -1, sizeof dp);
        if(t) cout << endl;
        else t++;
        cout << get(0) << endl;
    }

    return 0;
}
