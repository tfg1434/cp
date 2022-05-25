#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IN(A, B, C) assert(B <= A && A <= C)
#define mod2(a, n) ((a%n)+n)%n
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll INFF = 1e18;


void doRotate(string& s) {
    rotate(s.rbegin(), s.rbegin() + 1, s.rend());
    cout << s << endl;
}

string s;
ll f(ll pos, ll len) {
    if (pos < s.size()) return pos;
    
    if (pos < len / 2) {
        return f(pos, len / 2);
    }
    return f(mod2((pos-1),(len/2)), len / 2);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    cin >> s;
    ll n; cin >> n;
   
    ll len = s.size();
    while (len < n) len*=2;
    //output s[rec(n-1, len)];
    //index of n-1th character in string with length len

    cout << s[f(n-1, len)] << endl;
   
    return 0;
}
