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
    
    ll q, x; cin >> q >> x;

    vector<ll> cnt(x, 0);
    set<pll> st;
    for (ll i = 0; i < x; i++) {
        st.insert({ cnt[i], i });
    }

    for (ll i = 0; i < q; i++) {
        ll y; cin >> y;
        ll m = y % x;

        st.erase({ cnt[m], m });
        cnt[m]++;
        st.insert({ cnt[m], m });

        cout << st.begin()->first*x + st.begin()->second << '\n';
    }
    
    return 0;
}

