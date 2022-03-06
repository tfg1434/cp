#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

int T;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while (T--) {
        int n; cin >> n;
        string s; cin >> s;
        int cnt = 0; for (char c : s) cnt += c == '*';

        int curr = -1, pos = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                curr++;
                if (curr == cnt / 2) pos = i;
            }
        }
        
        ll ans = 0;
        curr = pos - cnt / 2; //where first sheep need to go
        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                ans += abs(curr - i);
                curr++;
            }
        }

        cout << ans << '\n';
    }    
    
    return 0;
}

