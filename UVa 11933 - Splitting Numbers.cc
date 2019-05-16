#include <bits/stdc++.h>

using namespace std;

int main(){
    while(true){
        int n;
        scanf("%d", &n);
        if(n == 0) break;

        int a = 0, b = 0;
        int state = 0;
        for(int i = 0; i < 32; i++){
            if(n & (1 << i)){
                if(state){
                    b |= (1 << i);
                } else {
                    a |= (1 << i);
                }
                state ^= 1;
            }
        }

        cout << a << ' ' << b << endl;
    }

    return 0;
}
