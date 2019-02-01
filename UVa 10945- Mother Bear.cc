#include <bits/stdc++.h>

using namespace std;

int main(){
    string word;

    while(getline(cin, word)){
        if(word == "DONE"){
            return 0;
        }

        string s = "";
        for(char c: word){
            if(isalpha(c)){
                s += tolower(c);
            }
        }

        stack <char> S;
        int n = s.length();
        for(int i = 0; i < n / 2; i++){
            S.push(s[i]);
        }

        bool good = true;
        for(int i = n % 2? n / 2 + 1: n / 2; i < n; i++){
            char t = S.top();
            S.pop();

            if(t != s[i]){
                good = false;
                break;
            }
        }

        if(good){
            cout << "You won't be eaten!" << endl;
        } else {
            cout << "Uh oh.." << endl;
        }
    }

    return 0;
}
