#include <bits/stdc++.h>

using namespace std;
const int N = 100;
int g[N][N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int c = 0;
    while(true){

        int n;
        cin >> n;

        if(n == 0)
            break;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> g[i][j];
            }
        }

        int proc = 0;


        vector <int> sums;
        while(proc <= n / 2){
            int sum = 0;
            for(int i = proc; i < n - proc; i++){
                if(proc != n - proc - 1)
                    sum += g[i][proc];
                sum += g[i][n - proc - 1];
            }

            for(int j = proc + 1; j < n - proc - 1; j++){
                if(proc + 1 != n - proc - 1)
                    sum += g[proc][j];
                sum += g[n - proc - 1][j];
            }

            sums.push_back(sum);
            proc++;
        }

        cout << "Case " << ++c << ": ";
        for(int i = 0; i < ceil((1.0 * n) / 2); i++){
            cout << sums[i] << (i + 1 == ceil((1.0 * n) / 2)? '\n':' ');
        }
    }

    return 0;
}
