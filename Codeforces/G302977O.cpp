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
    
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    for (auto &x : a) cin >> x;
    pll best; //{len, start}
    vector<ll> pre(n+1, 0);
    for (ll i = 0; i < n; ++i) {
        pre[i+1] = pre[i] + !a[i];
    }

    ll ans = INFF;
    for (ll i = 0; i < n; i++) {
        ll l = i, r = n;
        while (l < r) {
            ll m = (l+r)/2;

            if (pre[m+1] - pre[i] <= k) {
                l = m+1;
            } else {
                r = m;
            }
        }

        best = max(best, { r-i, i });
    }

    cout << best.first << '\n';
    for (ll i = 0; i < n; i++) {
        if (best.second <= i && i < best.second + best.first) {
            cout << "1 ";
        } else {
            cout << a[i] << ' ';
        }
    }
    
    return 0;
}

