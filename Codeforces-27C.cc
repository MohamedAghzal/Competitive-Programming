#include <iostream>
#include <vector>
#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector <int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    int mx = v[0], idx_mx = 0;
    int mn = v[0], idx_mn = 0;
    int mid = -1;

    for(int i = 0; i < n; i++){
       if (i > 0 && (v[i] > mn && v[i] < mx) || (((v[i] >= mx && idx_mn > idx_mx) || (v[i] <= mn && idx_mx > idx_mn)) && idx_mx != idx_mn)){
            mid = i;
            break;
       }
       if(v[i] < mn){
         mn = v[i];
         idx_mn = i;
       }

       if(v[i] > mx){
         mx = v[i];
         idx_mx = i;
       }
    }

    if(mx == mn || mid == -1){
       cout << 0;
       return 0;
    }

    cout << 3 << endl;
    int a[] = {idx_mn + 1, idx_mx + 1, mid + 1};
    sort(a, a + 3);
    cout << a[0] << ' ' << a[1] << ' ' << a[2];
    return 0;
}
