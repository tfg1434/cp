#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define len(a) (ll)((a).size())
#define IN(A, B, C) assert(B <= A && A <= C)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll INFF = 1e18;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T; while (T--) {
        string s, t; cin >> s >> t;
        
        vector<vector<ll>> nxt(len(s)+5, vector<ll>(26, INFF));
        for (ll i = len(s) - 1; i >= 0; i--) {
            for (ll j = 0; j < 26; j++) {
                nxt[i][j] = nxt[i+1][j];
            }
            nxt[i][s[i] - 'a'] = i;
        }

        //pos is the pointer in s
        ll ans = 1, pos = 0;
        for (ll i = 0; i < len(t); i++) {
            if (pos == len(s)) {
                ans++;
                pos = 0;
            }

            if (nxt[pos][t[i] - 'a'] == INFF) {
                pos = 0;
                ans++;
            }
            if (nxt[pos][t[i] - 'a'] == INFF && pos == 0) {
                ans = INFF;
                break;
            }

            pos = nxt[pos][t[i] - 'a'] + 1;
        }

        if (ans == INFF) {
            cout << -1 << '\n';
        } else {
            cout << ans << '\n';
        }
    }    
    
    return 0;
}

