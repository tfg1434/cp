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
        ll n, m, k; cin >> n >> m >> k;
        vector<ll> a(k);
        for (auto& x : a) cin >> x;
        bool ans = false;
        sort(all(a), greater<ll>());

        ll hor = 0, ver = 0;
        bool hc = false, vc = false;
        for (ll i = 0; i < k; i++) {
            if (a[i] < 2*n) break;

            ll cnt = a[i] / n;
            if (hor == m - 1) {
                if (!hc) {
                    ans = false;
                } else {
                    ans = true;
                }
                break;
            }
            hor += cnt;
            if (a[i] >= 3*n) {
                hc = true;
            }
            if (hor >= m) {
                ans = true;
                break;
            }
        }
        if (ans) {
            cout << "Yes" << endl;
            continue;
        }

        ans = false;
        for (ll i = 0; i < k; i++) {
            if (a[i] < 2*m) break;
            ll cnt = a[i] / m;
            if (ver == n - 1) {
                if (!vc) {
                    ans = false;
                } else {
                    ans = true;
                }
                break;
            }
            ver += cnt;
            if (a[i] >= 3*m) {
                vc = true;
            }
            if (ver >= n) {
                ans = true;
                break;
            }
        }
        if (ans) {
            cout << "Yes" << endl;
            continue;
        }
        cout << "No" << endl;

        // bool ans = false;
        // //try horizontal arrangement. m columns
        // ll hor = 0;
        // for (ll i = 0; i < k; i++) {
            // if (a[i] >= 2*n) {
                // ll cnt = a[i] / n;
                // hor += cnt;
                // // a[i] -= cnt * n;
            // }
        // }
        // if (hor >= m) ans = true;
        // //try vertical arrangement. n rows
        // ll ver = 0;
        // for (ll i = 0; i < k; i++) {
            // if (a[i] >= 2*m) {
                // ll cnt = a[i] / m;
                // ver += cnt;
                // // a[i] -= cnt * m;
            // }
        // }
        // if (ver >= n) ans = true;

        // cout << (ans ? "Yes" : "No") << endl;
    }    
    
    return 0;
}

