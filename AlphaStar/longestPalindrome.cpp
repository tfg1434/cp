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

struct Pal {
    ll left, right, len;
};

constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll INFF = 1e18;
ll n;


bool EQUAL(char a, char b) {
    if (!(isalpha(a) && isalpha(b))) return true;
    return tolower(a) == tolower(b);
};
Pal longestLength(string &s, int left, int right) {
    ll len = 0;
    while (left >= 0 && right < n) {
        if (!EQUAL(s[left], s[right])) {
            left++; right--;
            break;
        }
        left--; right++;
        if (left < 0 || right >= n) break;
        if (isalpha(s[left])) len++;
        if (isalpha(s[right])) len++;
    }
    while (right - left > 1 && (!isalpha(s[left]) || !isalpha(s[right]))) left++, right--;
    return { left, right, len };
}

string longestPalindrome(string s) {
    n = s.size();
    
    int start = 0, end = 0, maxlen = 0;
    for (int i = 0; i < n; i++) {
        Pal x = longestLength(s, i, i);
        Pal y = longestLength(s, i, i+1);
        if (x.len > maxlen) start = x.left, end = x.right, maxlen = x.len;
        if (y.len > maxlen) start = y.left, end = y.right, maxlen = x.len;
    }
    
    return s.substr(start, end - start + 1);
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s = "", temp;
    while (!cin.eof()) {
        getline(cin, temp);
        s += temp + '\n';
    }

    string ans = longestPalindrome(s);
    ll len = 0;
    for (auto x : ans) if (isalpha(x)) len++;
    cout << len << '\n' << ans << '\n';
    
    return 0;
}

