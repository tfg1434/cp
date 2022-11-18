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


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T; while (T--) {
        ll n, p; cin >> n >> p;
        vector<ll> a(n);
        set<ll> st;
        for (auto& x : a) {
            cin >> x;
            st.insert(x);
        }
        // cout << st << endl;
        ll an = a[n-1];

        //[l,r]
        auto isGaps = [&](ll l, ll r) -> bool {
            if (!st.count(l) || !st.count(r)) return true;

            ll lIdx = distance(st.find(l) , st.begin()), rIdx = distance(st.find(r), st.begin());
            if (rIdx-lIdx+1 < r-l+1) return false;
            return true;
        };

        bool yesIter1 = true;
        for (ll i = 0; i < an; i++) {
            yesIter1 &= st.count(i);
        }
        // bool yesIter1 = !isGaps(0, an-1);

        if (yesIter1) {
            ll ans;
            //how many do you need?
            for (ll i = p -1; ; i--) {
                if (i == -1){
                    ans = 0;
                    break;
                } 
                if (!st.count(i)){
                    ans = i - an;
                    break;
                } 
            }
            cout << ans << endl;
            continue;
        }
        {
            st.insert(0);
            ll point = n-2;
            while (point >= 0) {
                ll x = a[point] + 1;
                st.insert(x);
                if (x == p) {
                    point--;
                } else {
                    break;
                }
            }
            if (point == -1) st.insert(1);

            ll ans;
            for (ll i = an-1; ; i--) {
                if (!st.count(i)) {
                    ans = (p-an-1) + i+1;
                    break;
                }
                if (i == 0) {
                    ans = (p-an-1) + i+1;
                    // cout << "HEKL\n";
                    break;
                }
            }

            cout << ans << endl;
        }
    } 
    
    return 0;
}
