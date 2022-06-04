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
        string s, c; cin >> s >> c;

        for (ll i = 0; i < len(s); i++) {
            if (s[i] == 'A') continue;

            char mn = 'Z';
            ll idx;
            bool found = false;
            for (ll j = len(s)-1; j > i; j--) {
                if (s[j] < mn){
                    mn = s[j];
                    idx = j;
                    found = true;
                } 
            }
            if (mn < s[i] && found) {
                swap(s[i], s[idx]);
                break;
            }
        }

        if (s < c) {
            cout << s << endl;
        } else {
            cout << "---\n";
        }
    }    
    
    return 0;
}

