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
        ll n; cin >> n;
        vector<ll> a(n), b(n);
        for (auto& x : a) cin >> x;
        for (auto& x : b) cin >> x;

        ll sum = 0;
        for (auto x : b) sum += x;
        vector<pll> c(n);
        for (int i = 0; i < n; ++i) c[i] = {a[i], b[i]};
        sort(all(c));

        ll ans = sum;
        for (int i = 0; i < n; i++) {
            sum -= c[i].second;
            ans = min(ans, max(c[i].first, sum));
        }

        cout << ans << '\n';


        //this doesn't work, you need to zip a and b together
        //b4 sorting
        // ll cost = 0, i = n-1;
        // while (i >= 0) {
            // if (b[i] < a[i]) {
                // if (cost + b[i] <= a[i]) {
                    // cost += b[i];
                    // i--;
                // } else {
                    // break;
                // }

            // } else break;
        // }
        
        // if (i >= 0) cout << a[i] << '\n';
        // else cout << accumulate(all(b), 0LL) << '\n';
    }    
    
    return 0;
}

