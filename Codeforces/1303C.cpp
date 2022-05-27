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
    string s; cin >> s;

    vector<bool> used(26, false);
    used[s[0] - 'a'] = true;
    string t(1, s[0]);
     
    ll pos = 0;
    for (ll i = 1; i < len(s); i++) {
        //it's a neighbour of us, b/c seen before
        if (used[s[i] - 'a']) {
            if (pos > 0 && t[pos - 1] == s[i]) {
                pos--;
            } else if (pos < len(t)-1 && t[pos + 1] == s[i]) {
                pos++;
            } else {
                cout << "NO" << endl;
                return;
            }
        //add it to the front or the back of t
        } else {
            if (pos == 0) {
                t = s[i] + t;
            } else if (pos == len(t) - 1) {
                t += s[i];
                pos++;
            } else {
                cout << "NO" << endl;
                return;
            }
        }
        used[s[i] - 'a'] = true;
    }

    for (ll i = 0; i < 26; i++) {
        if (!used[i])
            t += char('a' + i);
    }

    cout << "YES" << endl << t << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T; while (T--) {
        solve();
    }    
    
    return 0;
}

