#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e6 + 5;

string t;
int z[N];

void process(string s) {
    int n = (int) s.length();
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
}

int main(){
    while(true){
        cin >> t;
        if(t == ".")
            break;

        memset(z, 0, sizeof z);
        process(t);

        int l = t.length();
        int period = l;

        for(int i = 1; i < l; i++){
            if(l % i != 0)
                continue;
            if(i + z[i] == l){
                period = i;
                break;
            }
        }

        cout << l / period << endl;
    }

    return 0;
}
