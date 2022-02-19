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
        int ans = INT_MAX;

        for (char c = 'a'; c <= 'z'; c++) {
            int l = 0, r = n-1, this_iter = 0;

            while (l < r) {
                if (s[l] == s[r]) {
                    l++; r--;
                    continue;
                } 
                if (s[l] == c) {
                    l++; this_iter++;
                    continue;
                }
                if (s[r] == c) {
                    r--; this_iter++;
                    continue;
                }

                this_iter = INT_MAX;
                break;
            }

            ans = min(ans, this_iter);
        }

        if (ans == INT_MAX) ans = -1;
        cout << ans << '\n';
    }    
    
    return 0;
}

