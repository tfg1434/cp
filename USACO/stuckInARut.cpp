#include <bits/stdc++.h>
using namespace std;
using pll = pair<long long, long long>;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define eb emplace_back
#define vi vector<ll>
#define vb vector<bool>
#define f0(i,a) for(ll i=0;i<(a);i++)
#define f1(i,a) for(ll i=1;i<(a);i++)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define f first
#define s second
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
#ifdef I_AM_NOOB
#define gg(...) [](const auto&...x){ char c='='; cerr<<#__VA_ARGS__; ((cerr<<exchange(c,',')<<x),...); cerr<<endl; }(__VA_ARGS__);
#else
#define gg(...) 777771449
#endif

constexpr ll INFF = 1e18;
constexpr ll P = 1e9+7;
// constexpr ll P = 998244353;

struct Cow {
    ll x,y, id;
    char t;
};

bool byX(Cow a, Cow b) {
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}
bool byY(Cow a, Cow b) {
    if (a.y == b.y) return a.x < b.x;
    return a.y < b.y;
}

// Realised ordering of timestamp of collisions
// Didn't think to impose ordering to avoid sort
// Initially didn't think to put N and E in separate vectors
int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    
    ll n; while (cin >> n) {
        vector<Cow> E, N;
        f1(i, n+1) {
            Cow c; cin >> c.t >> c.x >> c.y;
            c.id = i;
            (c.t == 'E' ? E : N).pb(c);
        }
        sort(all(N), byX);
        sort(all(E), byY);

        vi blame(n+1);
        vb collided(n+1);
        f0(i, E.size()) {
            f0(j, N.size()) {
                //VERY IMPORTANT to check here instead of i in outer loop
                //b/c you update collided in inner loop
                if (collided[E[i].id] || collided[N[j].id]) continue;
                ll x1 = E[i].x, y1 = E[i].y, x2 = N[j].x, y2 = N[j].y;
                if (x2 >= x1 && y2 <= y1) {
                    ll dx = x2-x1, dy = y1 - y2;
                    if (dx == dy) continue;
                    //---> |
                    if (dy < dx) {
                        blame[N[j].id] += 1 + blame[E[i].id];
                        collided[E[i].id] = true;
                    } else if (dy > dx){
                        blame[E[i].id] += 1 + blame[N[j].id];
                        collided[N[j].id] = true;
                    }
                }
            }
        }

        f1(i, n+1) {
            cout << blame[i] << endl;
        }
    }
    
    return 0;
}
