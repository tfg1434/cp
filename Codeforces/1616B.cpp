#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int C;
    cin >> C;
    
//    auto doubleStr = [](string s) {
//        string res = "";
//
//        for (int i = 0; i < 2; ++i) {
//            res += s;
//        }
//        
//        return res;
//    };

    for (int c = 0; c < C; ++c) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        string res = string(1, s[0]);
        for (int i = 1; i < n; ++i) {
            //if this char is bigger than previous char
            //or if this char is equal to previous char and this char is equal to first char
            //break
            if (s[i-1] < s[i] || (s[i-1] == s[i] && s[i] == s[0]))
                break;
            
            res += s[i];
        }
        
        string copy(res);
        reverse(copy.begin(), copy.end());
        cout << res + copy << '\n';
    }

    return 0;
}


