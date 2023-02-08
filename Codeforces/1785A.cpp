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


int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    
    int T; cin >> T; while (T--) {
        ll n; cin >> n;
        ll c = 2;
        ll alice = false;
        ll aw = 0, ab = 0, bw = 0, bb = 0;
        ll i = 0;
        aw++; n-= 1; i++;
        while (n > 0) {
            if (n < c + c + 1) {
                if (n % 2 == 0) {
                    if (alice) {
                        aw += n/2;
                        ab += n/2;
                    } else {
                        bw += n/2;
                        bb += n/2;
                    }
                } else {
                    if (i % 2 == 0) {
                        if (alice) {
                            aw += n/2+1;
                            ab += n/2;
                        } else {
                            bw += n/2+1;
                            bb += n/2;
                        }
                    } else {
                        if (alice) {
                            aw += n/2;
                            ab += n/2+1;
                        } else {
                            bw += n/2;
                            bb += n/2+1;
                        }
                    }
                }
                // gg("broke out");
                break;
            }

            if (alice) {
                if (i % 2 == 0) {
                    aw += c+1;
                    ab += c;
                } else {
                    aw += c;
                    ab += c + 1;
                }
            } else {
                if (i % 2 == 0) {
                    bw += c+1;
                    bb += c;
                } else {
                    bw += c;
                    bb += c + 1;
                }
            }
            alice = !alice;
            n -= c + c + 1;
            i += c + c + 1;
            c += 2;

            // gg(aw, ab, bw, bb);
        }

        cout << aw << ' ' << ab << ' ' << bw << ' ' << bb << endl;
        
    } 
    
    return 0;
}
