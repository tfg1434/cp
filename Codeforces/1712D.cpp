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
        ll n, k; cin >> n >> k;
        vector<ll> a(n);
        for (auto& x : a) cin >> x;

        auto check = [&](ll x) {
            vector<ll> b = a;
            ll kk = 0;
            for (ll i = 0; i < n; i++){
                if (b[i] < (x+1)/2) {
                    kk++; b[i] = 1e9;
                }
            }
            if (kk > k) return false;

            ll s = 0;
            for (ll i = 0; i < n; i++) {
                if (b[i] >= x) s++;
            }
            for (ll i = 0; i < n-1; i++) {
                if (b[i] >= x && b[i+1] >= x) return true;
            }

            if (s >= 1 && kk <= k-1) return true;
            if (s == 0 && kk <= k-2) return true;
            return false;
        };

        ll l = 0, r = 1e9;
        while (l < r) {
            ll mid = (l+r+1)/2;

            if (check(mid)) l = mid;
            else r = mid-1;
        }

        cout << r << '\n';
    }    
    
    return 0;
}

