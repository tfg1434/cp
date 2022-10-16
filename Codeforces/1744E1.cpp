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

// pair<bool, bool> check(ll div, ll c, ll d, ll xy) {
    // if (div > c) return {}false;
    // if (xy/div > d) return false;
// }


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T; while (T--) {
        ll a,b,c,d; cin >> a >> b >> c >> d;
        ll xy = a*b;

        bool found = false;
        ll ans1, ans2;
        while(true) {
            bool ok = true;
            xy += a*b;
            //we want largest factor div of xy <= c. and if xy/div >d then we break;
            ll div = 1;
            ll i; for (i = 1; i*i < xy; i++) {
                if (xy % i == 0) {
                    ll ta, tb;
                    if (xy / i == i) ta=tb=i;
                    else ta = i, tb = xy/i;
                    if (ta <= c) div = max(div, ta);
                    if (tb <= c) div = max(div, tb);
                    
                    // cout << i << endl;
                    // if (i > c) break;
                    // if (xy/i > d) {
                        // ok = false;
                        // break;
                    // }
                    // found = true;
                    // ans1 = i,  ans2= xy/i;
                    // break;
                }
            }    
            if (xy/div > d) {
                ok = false;
                break;
            }
            if (xy/div <=b) continue;
            found = true;
            ans1 =div, ans2 = xy/div;
        }

        if (found) cout << ans1 << ' ' << ans2 << endl;
        else cout << "-1 -1\n";
    }    
    
    return 0;
}

