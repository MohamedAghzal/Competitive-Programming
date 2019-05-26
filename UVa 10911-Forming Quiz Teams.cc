#include <bits/stdc++.h>

using namespace std;
const int N = 20;
int n;
const double inf = (double) 1e9;
double dp[1 << N];
char s[52];

typedef struct{
    double x, y;
} Point;

Point a[N];

double distance(Point a, Point b){
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double get(int mask){
    if(mask == (1 << n) - 1)
        return 0;
    if(dp[mask] != -1)
        return dp[mask];

    double ans = inf;
    int id;
    for(int i = 0; i < n; i++){
        if(!(mask & (1 << i))){
            for(int j = i + 1; j < n; j++){
                if(!(mask & (1 << j))){
                    ans = min(ans, distance(a[i], a[j]) + get(mask | (1 << i) | (1 << j)));
                }
            }
        }
    }

    return dp[mask] = ans;
}

int main(){
    int c = 0;
    while(scanf("%d", &n) && (n != 0)){
        n *= 2;
        for(int i = 0; i < n; i++){
            scanf("%s %lf %lf", s, &a[i].x, &a[i].y);
        }

        for(int i = 0; i < (1 << N); i++){
            dp[i] = -1.0;
        }

        printf("Case %d: %.2f\n",++c, get(0));
    }
    
    return 0;
}

