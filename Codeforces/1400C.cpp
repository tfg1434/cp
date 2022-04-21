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
string s;
ll x;


string f(string s) {
    string res = s;
    for (ll i = 0; i < s.size(); i++) {
        if (i - x >= 0 && s[i-x] == '1' || i + x < s.size() && s[i+x] == '1') {
            res[i] = '1';
        } else {
            res[i] = '0';
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T; while (T--) {
        cin >> s >> x;
        string w = string(s.size(), '1');

        bool ok = true;
        for (ll i = 0; i < s.size(); i++) {
            if (s[i] != '0') continue;

            if (i - x >= 0) w[i-x] = '0';
            if (i + x < s.size()) w[i+x] = '0';
        }

        if (f(w) == s) cout << w << '\n';
        else cout << "-1\n";
    }    
    
    return 0;
}

