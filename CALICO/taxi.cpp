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

struct Cab {
    string name;
    ll m, b;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T; while (T--) {
        string s; cin >> s;
        ll n; cin >> n;
        vector<Cab> cs;

        for (ll i = 0; i < n; i++) {
            Cab c;
            cin >> c.name;
            cin >> c.b >> c.m;
            // cout << c.name << ' ' << c.m << ' ' << c.b << endl;
            cs.push_back(c);
        }
        sort(all(cs), [](Cab a, Cab b) { return a.m < b.m; });
        // for (auto c : cs) cout << c.m << endl;
        
        auto intersectNext = [](Cab c, vector<Cab> cs) {
            // cout << cs.size() << endl;
            // if (cs.size() == 0) return ;
            double res = INFF;
            double m1 = c.m, b1 = c.b;
            for (Cab cc : cs) {
                double m2 = cc.m, b2 = cc.b;
                if (m1 == m2) {
                    continue;
                } 
                res = min(res, (b2-b1)/(m1-m2));
            }

            return res;
        };

        ll currX = 0;
        // cout << cs.size() << endl;
        Cab currBest = *min_element(all(cs), [&](Cab a, Cab b) {
            return a.m * currX + a.b < b.m * currX + b.b;
        });
        // cout << currBest.name;
        while (cs.size() > 0  && cs.back().m >= currBest.m) cs.pop_back();
        // cout << cs.size() << endl;

        vector<pair<pll, Cab>> ans;
        while (cs.size() > 0) {
            double nextX = intersectNext(currBest, cs);
            // cout << currBest.name << endl;
            // cout << nextX << endl;

            if (nextX == (ll) nextX) nextX--;
            ans.push_back({ { currX, (ll) nextX }, currBest });
            currX = nextX + 1;
            currBest = *min_element(all(cs), [&](Cab a, Cab b) {
                return a.m * currX + a.b < b.m * currX + b.b;
            });
            while (cs.size() > 0  && cs.back().m >= currBest.m) cs.pop_back();
        }    
        ans.push_back({ {currX, INFF}, currBest });

        cout << s << ":\n";
        for (auto [c, t] : ans) {
            auto [x1, x2] = c;
            if (x2 == INFF) cout << x1 << "+: " << t.name << endl;
            else if (x1 == x2) cout << x1 << ": " << t.name << endl;
            else cout << x1 << '-' << x2 << ": " << t.name << endl;
        }
        cout << endl;
    } 
    
    return 0;
}
