#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IN(A, B, C) assert(B <= A && A <= C)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll INFF = 1e18;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n; cin >> n;
    vector<ll> a(n);
    for (auto &x : a) cin >> x;
    ll c; cin >> c;
    vector<ll> b(c);
    for (auto &x : b) cin >> x;
    sort(all(b));

    vector<ll> ans;
    for (ll i = 0; i < n; i++) {
        vector<ll> aa, bb;
        for (ll j = i; j < i + c; j++) aa.push_back(a[j]);
        bb = b;
        sort(all(aa));
        // cout << aa << '\n' << bb << '\n';
        ll diff = bb[0] - aa[0];
        bool ok = true;
        for (ll j = 0; j < c; j++) {
            if (aa[j] + diff != bb[j]) {
                // cout << aa[j] + diff << ' ' << bb[j] << '\n';
                ok = false;
                break;
            }
        }
        if (ok) ans.push_back(i);
    }

    cout << ans.size() << '\n';
    for (auto &x : ans) cout << x+1 << '\n';
    
    return 0;
}

