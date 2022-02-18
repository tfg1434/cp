#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

int T;


string suffixes[4] = {"00", "25", "50", "75"};

int solve(const string& s, const string& suffix) {
    int res = 0;
    int r = s.size() - 1;
    while (r >= 0 && s[r] != suffix[1]) {
        r--; res++;
    }

    if (r < 0) return INT_MAX;
    r--;

    while (r >= 0 && s[r] != suffix[0]) {
        r--; res++;
    }

    return r < 0 ? INT_MAX : res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while (T--) {
        string s; cin >> s;        

        int ans = INT_MAX;
        for (const auto& suffix : suffixes) {
            ans = min(ans, solve(s, suffix));
        }

        cout << ans << '\n';
    }    
    
    return 0;
}

