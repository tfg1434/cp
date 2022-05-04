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
string s;


bool cmp(string a, string b) {
    if (a.size() != b.size()) return a.size() < b.size();
    
    ll idx = 0;
    while (a[idx] == b[idx]) idx++;

    return s.find(a[idx]) < s.find(b[idx]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll m; cin >> m;
    char c;
    for (ll i = 0; i < m; i++) {
        cin >> c;
        // cout << c << endl;
        s += c;
    }
//    cout << s << endl;

//    cout << cmp("43", "48");

    vector<string> ans;
    //can also generate all using bitmasks
    y_combinator([&](auto rec, string in, string out) -> void {
        if (in.empty()) {
            ans.push_back(out);
            return;
        }
        rec(in.substr(1), out + in[0]);
        rec(in.substr(1), out);

    })(s, "");

    sort(all(ans), cmp);
    for (ll i = 1; i < ans.size(); i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}

