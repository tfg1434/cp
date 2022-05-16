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
        ll n, k, z; cin >> n >> k >> z;
        vector<ll> a(n);
        for (auto &x : a) cin >> x;

        // vector<pll> pairs; //2sum, idx
        // for (ll i = 1; i <= k; i++) {
            // pairs.push_back({ a[i] + a[i+1] , i });
        // }
        // sort(all(pairs));

        // for (ll i = 0; i <= k; i++) sum += a[i];

        // ll last = k;
        ll ans = 0;
        for (ll t = 0; t <= z ; t++) {
            ll pos  = k - 2 * t;
            if (pos < 0) break;
            ll mx = 0, sum = 0;
            for (ll i = 0; i <= pos; i++) {
                if (i < n - 1)
                    mx = max(mx, a[i] + a[i+1]);
                sum += a[i];
            }

            ans = max(ans, sum + mx * t);

            // while (pairs.back().second > last - 3){
                // pairs.pop_back();
                // if (pairs.empty()) break;
            // } 

            // if (pairs.back().first > a[last] + a[last-1]) {
                // sum += pairs.back().first - a[last] - a[last-1];
                // last -= 2;
            // }
        }

        cout << ans << '\n';
    }    
    
    return 0;
}

