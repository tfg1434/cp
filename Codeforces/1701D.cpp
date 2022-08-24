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
        ll n; cin >> n;
        vector<ll>b(n), a(n);
        for (auto& x : b) cin >> x;
        vector<pll> v;
        for (ll i = 0; i < n; i++) {
            v.push_back({(i+1)/(b[i]+1)+1, i});
        }
        sort(all(v));

        set<pll> st;
        ll j = 0;
        for (ll i = 1; i <= n; i++) {
            while (j < n && v[j].first == i) {
                ll idx = v[j++].second;
                st.insert({ b[idx] ? (idx+1) / b[idx] : n, idx });
            }
            a[st.begin()->second] = i;
            st.erase(st.begin());
        }

        for (ll i = 0; i < n; i++) {
            cout << a[i] << ' ';
        }
        cout << endl;
    }    
    
    return 0;
}

