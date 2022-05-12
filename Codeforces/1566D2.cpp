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
    
    int T; cin >> T; while (T--) {
        ll n, m; cin >> n >> m;         
        vector<pll> a(n*m);
        for (ll i = 0; i < n * m; i++) {
            cin >> a[i].first;
            a[i].second = i;
        }
        sort(all(a));
        for (ll i = 0; i < n*m; i++) {
            a[i].second = -a[i].second;
        }

        ll ans = 0;
        for (ll i = 0; i < n; i++) {
            sort(a.begin() + (m*i), a.begin() + (m*i+m));

            for (ll j = 0; j < m; j++) {
                for (ll k = 0; k < j; k++) {
                    if (a[i*m + k].second > a[i*m + j].second) ans++;
                }
            }
        }

        cout << ans << endl;
    }    
    
    return 0;
}

