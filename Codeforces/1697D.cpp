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


char ask(ll i) {
    cout << "? 1 " << i << endl;
    cout.flush();
    string s; cin >> s;
    return s[0];
}

ll ask(ll l, ll r) {
    cout << "? 2 " << l << " " << r << endl;
    cout.flush();
    ll x; cin >> x;
    return x;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n; cin >> n;
    string s = "";
    vector<vector<ll>> f(n+1);
    for (ll i = 0; i < n; i++) {
        if (i == 0) {
            s += ask(1);
            f[0] = {1};
            continue;
        }

        ll curr = ask(1, i+1);
        //new unique char
        if (curr > f[i-1][0]) {
            s += ask(i+1);
        } else {
            map<char, ll> last;
            for (ll j = 0; j < s.size(); j++)
                last[s[j]] = j;

            vector<ll> lasts;
            for (auto [x, y] : last)
                lasts.push_back(y);
            sort(all(lasts));

            ll l = 0, r = len(lasts);
            while (r-l>1) {
                ll m = (l+r)/2;
                ll d = ask(lasts[m]+1, i+1);
                if (d == f[i-1][lasts[m]]) {
                    l = m;
                } else {
                    r = m;
                }
            }

            s += s[lasts[l]];
        }

        f[i].resize(i+1);
        set<char> st;
        for (ll j = i; j >= 0; j--) {
            st.insert(s[j]);
            f[i][j] = len(st);
        }
    }

    cout << "! " << s << endl;
    cout.flush();
    
    return 0;
}

