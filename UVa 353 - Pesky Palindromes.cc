#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100;
int dp[N][N], p[N][N];
string s;
bool palindrome(int i, int j){
    if(i == j) return 1;
    if(i > j) return 0;
    if(i == j - 1) return (s[i] == s[j]);
    if(p[i][j] != -1) return p[i][j];
    return p[i][j] = (s[i] == s[j]) && palindrome(i + 1, j - 1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    while(cin >> s){
        unordered_set <string> S;
        int ans = 0;
        memset(p, -1, sizeof p);
        palindrome(0, s.length() - 1);
        for(int i = 0; i < s.length(); i++){
            for(int j = i; j < s.length(); j++){
                string t = s.substr(i, j - i + 1);
                if(palindrome(i, j) && !S.count(t)){
                    ans++;
                    S.insert(t);
                }
            }
        }
        cout << "The string " <<  '\'' << s << '\'' << " contains "<< ans << " palindromes.\n";
    }
    return 0;
}
