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


ll toB(ll n, ll b) {
    string res;
    while (n > 0) {
        res += to_string(n % b);
        n /= b;
    }
    reverse(all(res));
    return stoll(res);
}
ll to10(ll n, ll b) {
    ll res = 0, pow = 1;
    while (n > 0) {
        res += (n % 10) * pow;
        pow *= b;
        n /= 10;
    }
    return res;
}

ll sumToN(ll n, ll b) {
    if (n < b) return n*(n+1)/2;

    ll d = log10(n);
    vector<ll> a(d+1);
    ll m = b*(b-1)/2;
    a[0] = 0, a[1] = m;
    for (ll i = 2; i <= d; i++) {
        a[i] = a[i-1]*b + m * ceil(pow(b, i-1)); 
    }

    ll p = ceil(pow(b, d));
    ll p10 = ceil(pow(10, d));
    ll msd = n / p10;
    // cout << msd << endl;


    // cout << 1+to10(n%p10, b) << endl;
    return msd*a[d] + msd*(msd-1)/2*p 
         + msd*(1+to10(n%p10, b)) + sumToN(n%p10, b);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n, b, s; cin >> n >> b >> s; 
    ll s_10 = to10(s, b);

    // cout << "sanity checl" << to10(20, 3) << endl;;
    ll hi = s_10 + n-1;
    ll hi_b = toB(hi, b);
    ll lo_b = toB(s_10-1, b);
    // cout << hi_b << ' ' << lo_b << endl;
    // cout << sumToN(hi_b, b) << ' ' <<  sumToN(lo_b, b) << endl;;

    cout << sumToN(hi_b, b) - sumToN(lo_b, b) << endl;
    
    return 0;
}
