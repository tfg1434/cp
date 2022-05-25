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
    
    ll n, l; cin >> n >> l;
    vector<ll> a(n);
    for (auto &x : a) {
        cin >> x;
        x *= 2;
    }
    sort(all(a));

    ll ans = 0;
    //check all knot positions
    for (ll i = 0; i < n; i++) {
        ll l = i-1, r = i+1;
        bool broke = false;
        while (l >= 0 && r < n) {
            if (abs(a[l] - a[i]) == abs(a[r] - a[i])) {
                l--; r++;
            } else {
                broke = true;
                break;
            }
        }
        ans += !broke;
    }

    //check all midpoints of knots
    for (ll i = 1; i < n; i++) {
        ll c = i-1, d = i;
        ll mid = (a[c] + a[d]) / 2;

        ll l = c-1, r = d+1;
        bool broke = false;
        while (l >= 0 && r < n) {
            if (abs(a[l] - mid) == abs(a[r] - mid)) {
                l--; r++;
            } else {
                broke = true;
                break;
            }
        }
        ans += !broke;
    }

    cout << ans-2 << '\n';
    
    return 0;
}

