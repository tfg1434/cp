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
    
    ll n, q; while (cin >> n >> q) {
        string s; cin >> s;

        string perm = "abc";
        vector<vector<ll>> pre(6, vector<ll>(n+1, 0));
        ll idx = 0;
        do {
            for (ll i = 0; i < n; i++) 
                pre[idx][i+1] = pre[idx][i] + (s[i] != perm[i%3]); 
            idx++;

        } while (next_permutation(all(perm)));

        for (ll i = 0; i < q; i++) {
            ll l, r; cin >> l >> r;

            ll ans = INFF;
            for (ll j = 0; j < 6; j++) {
                ans = min(ans, pre[j][r] - pre[j][l-1]);
            }
            cout << ans << '\n';
        }
    }        
    
    return 0;
}

