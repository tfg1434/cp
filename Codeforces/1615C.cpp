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
        string a; cin >> a;
        string b; cin >> b;

        auto f = [&](string s) -> ll {
            ll ca = count(all(s), '1');
            ll cb = count(all(b), '1');

            if (ca == cb) {
                ll res = 0;
                for (ll i = 0; i < n; i++) {
                    if (s[i] != b[i]) res++;
                }
                return res;
            }
            return INFF;
        };

        auto flip = [&](ll idx) -> string {
            string res = a;
            for (ll i = 0; i < n; i++) {
                if (i == idx) continue;
                res[i] = (res[i] == '0') ? '1' : '0';
            }
            return res;
        };

        // if (count(all(a), '1') == count(all(b), '1')) {
            // cout << f(a) << '\n';
        // } else {
            ll ans = INFF;
            ans = min(ans, f(a));

            for (ll i = 0; i < n; i++) {
                if (a[i] == b[i] && a[i] == '1') {
                    ans = min(ans, f(flip(i))+1);
                    break;
                }
            }
            for (ll i = 0; i < n; i++) {
                if (a[i] != b[i] && a[i] == '1') {
                    ans = min(ans, f(flip(i))+1);
                    break;
                }
            }

            cout << ((ans == INFF) ? -1 : ans) << '\n';
        // }
    }    
    
    return 0;
}

