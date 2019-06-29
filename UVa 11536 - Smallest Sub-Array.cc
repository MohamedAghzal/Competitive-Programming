#include <bits/stdc++.h>

using namespace std;

const int N = 1000010, INF = (int) 1e9;

int a[N], cnt[N];

int main(){
    int T;
    scanf("%d", &T);

    int c = 0;
    while(T--){
        int n, m, k;
        scanf("%d %d %d", &n, &m, &k);

        a[1] = 1;
        a[2] = 2;
        a[3] = 3;
        for(int i = 4; i <= n; i++){
            a[i] = (a[i - 1] + a[i - 2] + a[i - 3]) % m + 1;
        }

        memset(cnt, 0, sizeof cnt);
        int l = 1;
        int r = 2;

        int ans = INF;
        for(int i = 1; i <= 3; i++){
            cnt[a[i]]++;
            bool valid = true;
            for(int j = 1; j <= k; j++){
                if(!cnt[j]){
                    valid = false;
                    break;
                }
            }
            if(valid){
                ans = i;
                break;
            }
        }

        l = 1;
        r = 3;
        while(r <= n){
            bool valid = true;
            for(int j = 1; j <= k; j++){
                if(!cnt[j]){
                    valid = false;
                    break;
                }
            }

            if(valid){
                ans = min(ans, r - l + 1);
                cnt[a[l]]--;
                l++;
            } else {
                r++;
                cnt[a[r]]++;
            }
        }

        printf("Case %d: ", ++c);
        if(ans == INF){
            puts("sequence nai");
        } else {
            printf("%d\n", ans);
        }
    }
}
