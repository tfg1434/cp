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


void solve() {
    ll n; cin >> n;
    string s, t; cin >> s >> t;

    // if (s == t) {
        // cout << "YES" << endl;
        // return;
    // }

    vector<ll> bvs, cvs;
    ll as = 0, bs = 0, cs = 0;
    ll at = 0, bt = 0, ct = 0;
    vector<ll> bvt, cvt;
    
    auto upd = [&]() {
        for (ll i = 0; i < len(s); i++) {
            char c = s[i];
            if (c == 'a') as++;
            else if (c == 'b') {
                bs++;
                bvs.push_back(i);
            } else {
                cs++;
                cvs.push_back(i);
            }
        }
        for (ll i = 0; i < len(t); i++) {
            char c = t[i];
            if (c == 'a') at++;
            else if (c == 'b') {
                bt++;
                bvt.push_back(i);
            } else {
                ct++;
                cvt.push_back(i);
            }
        }
    };
    upd();

    if (at != as || bt != bs || ct != cs) {
        cout << "NO" << endl;
        return;
    }

    for (ll i = 0; i < len(cvs); i++) {
        if (cvs[i] < cvt[i]) {
            cout << "NO" << endl;
            return;
        }

        for (ll j = cvs[i]; j > cvt[i]; j--) {
            swap(s[j], s[j - 1]);
        }
    }
    cout << s << endl;
    upd();
    for (ll i = 0; i < len(bvs); i++) {
        if (bvs[i] < bvt[i]) {
            cout << "NO" << endl;
            return;
        }

        // for (ll j = bvs[i]; j > bvt[i]; j--) {
            // swap(s[j], s[j - 1]);
        // }
    }

    cout << "YES" << endl;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T; while (T--) {
        solve();
    }    
    
    return 0;
}

