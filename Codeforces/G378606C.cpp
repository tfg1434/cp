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
        ll n, m; cin >> n >> m;
        vector<pll> p(m);
        for (ll i = 0; i < m; i++) {
            cin >> p[i].first;
            p[i].second = i+1;
        }
        sort(all(p));
        vector<ll> d(n+1, 0);

        for (ll i = 0; i < m; i++) {
            //each i causes rate of change to increase by i at t=1
            //then decrease by i at t = (p_i-p_x) % n
            ll nxt = (p[(i+1)%m].first - p[i].first + n) % n;
            ll x = p[(i+1) % m].second;
            d[1] += x;
            d[1+nxt] -= x;
        }

        ll ans = 0, curr = 0;
        for (ll i = 1; i <= n; i++) {
            curr += d[i];
            ans += curr;
            cout << ans << ' ';
        }        
        cout << endl;
    }    
    
    return 0;
}

