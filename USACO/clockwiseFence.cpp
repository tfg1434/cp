#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

int N;
int dir(char c) {
    if (c == 'E') return 0;
    if (c == 'N') return 90;
    if (c == 'W') return 180;

    return 270;
}

int da(char a, char b) {
    int a1 = dir(a), a2 = dir(b);
    if (a1 == (a2 + 90) % 360) return 90;
    if (a1 == a2) return 0;
    if (a1 == (a2 + 270) % 360) return -90;
    
    assert("wtf" && false);
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        int ans = 0;

        for (int j = 0; j < s.size(); j++) 
            ans += da(s[j], s[(j + 1) % s.size()]);
       
        cout << (ans == 360 ? "CW" : "CCW") << '\n';
    }
    
    return 0;
}

