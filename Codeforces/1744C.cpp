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
        ll n; cin >> n;
        char c; cin >> c;
        string s; cin >> s;
        // if (c == 'g') {
            // cout << 0 << endl;
            // continue;
        // }

        ll R, L;
        vector<ll> occ;
        for (ll i = 0; i < n; i++) if (s[i] == c) occ.push_back(i);
        for (ll i = n-1; i >= 0; i--) {
            if (s[i] == 'g') {
                R = i;
                break;
            }
        }
        for (ll i = 0; i < n-1; i++) {
            if (s[i] == 'g') {
                L = i;
                break;
            }
        }
        vector<ll> ans(n);

        ll dist;
        for (ll i = R; i >= 0; i--) {
            if (s[i] == 'g') {
                dist = 0;
            } else {
                dist++;
            }
            ans[i] = dist; 
        }
        for (ll i = R+1; i < n; i++) {
            ans[i] = (n-1-i)+L+1;
        }

        ll res = 0;
        for (ll i = 0; i < occ.size(); i++) {
            res = max(res, ans[occ[i]]); 
        }

        // cout << ans << endl;
        cout << res << endl;
    }    
    
    return 0;
}

