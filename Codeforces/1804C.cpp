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
#define gg(...) [](const auto&...x){ char c='='; cerr<<#__VA_ARGS__; ((cerr<<exchange(c,',')<<x),...); cerr<<endl; }(__VA_ARGS__);


constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll INFF = 1e18;
bool isTriangular(int num)
{
    if (num < 0)
        return false;
 
    // Considering the equation n*(n+1)/2 = num
    // The equation is  : a(n^2) + bn + c = 0";
    int c = (-2 * num);
    int b = 1, a = 1;
    int d = (b * b) - (4 * a * c);
 
    if (d < 0)
        return false;
 
    // Find roots of equation
    float root1 = ( -b + sqrt(d)) / (2 * a);
    float root2 = ( -b - sqrt(d)) / (2 * a);
 
    // checking if root1 is natural
    if (root1 > 0 && floor(root1) == root1)
        return true;
 
    // checking if root2 is natural
    if (root2 > 0 && floor(root2) == root2)
        return true;
 
    return false;
}

int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    
    int T; cin >> T; while (T--) {
        ll n, x, p; cin >> n >> x >> p;

        bool ans = false;
        for (ll i = 1; i <= min(4*n, p); i++) {
            ll me = (i*(i+1) / 2) % n;
            if ((me - (n-x)) % n == 0) {
                ans = true;
                break;
            }
        }

        cout << (ans ? "YES" : "NO") << endl; 
    } 
    
    return 0;
}
