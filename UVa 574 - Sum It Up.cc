#include <bits/stdc++.h>

using namespace std;
const int N = 25;
int a[N];
vector <int> valid;

void get(int pos, int mask, int sum, int n, int targ){
    if(sum == targ)
        valid.push_back(mask);
    if(pos >= n)
        return;
    get(pos + 1, mask | (1 << pos), sum + a[pos], n, targ);
    get(pos + 1, mask, sum, n, targ);
}

int main(){
    while(true){
        int sm, n;
        scanf("%d %d",&sm, &n);
        if(sm == 0 && n == 0) break;
        for(int i = 0; i < n; i++){
            scanf("%d", &a[i]);
        }

        valid.clear();
        get(0, 0, 0, n, sm);
        set <vector<int>> ans;
        for(int i = 0; i < valid.size(); i++){
            vector <int> t;
            for(int j = 0; j < n; j++){
                if(valid[i] & (1 << j)){
                    t.push_back(a[j]);
                }
            }
            ans.insert(t);
        }
        printf("Sums of %d:\n", sm);
        if(ans.empty()){
            puts("NONE");
        } else {
            for(auto it = ans.rbegin(); it != ans.rend(); it++){
                auto e = *it;
                for(int i = 0; i < e.size(); i++){
                    printf("%d%c", e[i], i == e.size() - 1? '\n':'+');
                }
            }
        }
    }
}
