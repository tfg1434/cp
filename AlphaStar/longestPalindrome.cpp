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
constexpr ll MAXN = 20000;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    char s[MAXN], s2[MAXN];
    ll slen = 0, s2len = 0;
    ll maxlen = 0, maxl, maxr;

    char c;
    while (cin.get(c)) {
        s[slen] = c;
        slen++;
        if (isalpha(c)) {
            s2[s2len] = tolower(c);
            s2len++;
        }
    }

    auto pal = [&](ll l, ll r) {
        ll i, j;
        while (s2[l] == s2[r] && l >= 0 && r < s2len) {
            i = l; j = r;
            l--; r++;
        }
        if (j - i + 1 > maxlen) {
            maxl = i; maxr = j;
            maxlen = j - i + 1;
        }
    };

    for (ll i = 1; i < s2len; i++) {
        pal(i-1, i+1);//odd
        pal(i-1, i); //even
    }
    
    string ans = "";
    ll cAlpha = -1;
    for (ll i = 0; i < slen && maxr >= cAlpha+1; i++) {
        if (isalpha(s[i])) cAlpha++;
        if (maxl <= cAlpha && maxr >= cAlpha) ans += s[i];
    }
    cout << maxlen << '\n';
    cout << ans << '\n';
    
    return 0;
}


