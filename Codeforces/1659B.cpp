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
        ll n, k; cin >> n >> k;
        string s; cin >> s;
        vector<ll> f(n, 0);
        ll kk = k;

        for (ll i = 0; i < n && kk > 0; i++) {
            if (k % 2 == s[i] - '0') {
                f[i] = 1;
                kk--;
            }
        }
        f[n-1] += kk;

        //construct the final string
        for (ll i = 0; i < n; i++) {
            if ((k - f[i]) % 2 == 1) s[i] = '1' - (s[i] - '0');
        }
        cout << s << '\n';
        for (auto& x : f) cout << x << ' '; cout << '\n';
    }    
    
    return 0;
}

