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


vector<ll> pfacs(ll n) {
    ll c = 2;
    vector<ll> res;
    while (n > 1) {
        if (n%c == 0) {
            res.push_back(c);
            n /= c;
        } else c++;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T; while (T--) {
        ll p, q; cin >> p >> q;

        set<ll> st;
        ll qq = q;
        for (ll i = 2; i*i <= qq; i++) {
            while (qq % i == 0) qq /= i, st.insert(i);
        }
        if (qq > 1) st.insert(qq);

        ll ans = 1;
        //try all factors
        for (auto x : st)  {
            ll pp = p;
            while (pp % q == 0) pp /= x;
            
            ans = max(ans, pp);
        }

        cout << ans << '\n';


        //p is not a superset of q
        // if (p%q != 0) {
            // cout << p << '\n';
            // continue;
        // }

        // vector<ll> pf = pfacs(q);
        // map<ll, ll> cnt;
        // for (ll x : pf) cnt[x]++;

        // ll ans = p;
        // for (auto [f, c] : cnt) {
            // ll powP = 0, op = p;
            // while (op%f == 0) {
                // powP++;
                // op /= f;
            // }

            // ll diff = powP - c + 1;
            // ll div = 1;
            // for (ll i = 0; i < diff; i++) div *= f;
            // ans = min(ans, div);
        // }

        // cout << p / ans << '\n';
    }    
    
    return 0;
}

