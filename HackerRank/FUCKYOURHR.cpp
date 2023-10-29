#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using db = long double; // or double, if TL is tight
using str = string; // yay python! 

// pairs
using pi = pair<int,int>;
using pl = pair<ll,ll>;
using pd = pair<db,db>;
#define mp make_pair
#define f first
#define s second

#define tcT template<class T
#define tcTU tcT, class U
// ^ lol this makes everything look weird but I'll try it
tcT> using V = vector<T>; 
tcT, size_t SZ> using AR = array<T,SZ>; 
using vi = V<int>;
using vb = V<bool>;
using vl = V<ll>;
using vd = V<db>;
using vs = V<str>;
using vpi = V<pi>;
using vpl = V<pl>;
using vpd = V<pd>;

// vectors
// oops size(x), rbegin(x), rend(x) need C++17
#define sz(x) ll((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend() 
#define sor(x) sort(all(x)) 
#define rsz resize
#define ins insert 
#define pb push_back
#define eb emplace_back
#define ft front()
#define bk back()

#define lb lower_bound
#define ub upper_bound
tcT> ll lwb(V<T>& a, const T& b) { return ll(lb(all(a),b)-bg(a)); }
tcT> ll upb(V<T>& a, const T& b) { return ll(ub(all(a),b)-bg(a)); }

// loops
#define FOR(i,a,b) for (ll i = (a); i < (b); ++i)
#define f0(i,a) FOR(i,0,a)
#define f1(i,a) FOR(i,1,a+1)
#define ROF(i,a,b) for (ll i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define rep(a) f0(_,a)
#define each(a,x) for (auto& a: x)

const ll P = 1e9+7; // 998244353;
const ll MX = 2e5+5;
const ll BIG = 1e18; // not too close to LLONG_MAX
const db PI = acos((db)-1);

db pdist(db x1, db y1, db x2, db y2) {
    db dx = x1-x2, dy = y1-y2;
    return sqrt(dx*dx + dy*dy);
}

db solveQuad(db a, db b, db c) {
    db d = b*b - 4*a*c;
    assert(d >= 0);
    db r1 =  (-b + sqrt(d)) / (2*a);
    db r2 =  (-b - sqrt(d)) / (2*a);
    
    return max(r1, r2);
}

void solve() {
    db ts; cin >> ts;
    V<pair<db, db>> a(3);
    f0(i, 3) {
        string _; cin >> _;
        cin >> a[i].f >> a[i].s;
        a[i].f *= PI/180;
    }
    string _; cin >> _;
    db sOff, sSpd; cin >> sOff >> sSpd;
    db x1, y1;
    db cur = 0;

    auto f = [&](ll idx) {
        db ang = a[idx].f, spd = a[idx].s;
        //calculate criminal starting position
        db dx = cos(ang);
        db dy = sin(ang);
        db x2 = dx*cur*spd;
        db y2 = dy*cur*spd;

        //do predictive calculation
        db dC = pdist(x1, y1, x2, y2);
        if (dC <= 1e-9) {
            cur++;
            return;
        }
        db r = spd / sSpd;
        // db toSam = atan2(x1 - x2, y1-y2);
        // gg(x1, y1, x2, y2);
        // gg(dx, dy, cos(toSam), sin(toSam));
        db DOT = dx*(x1-x2)/dC + dy*(y1-y2)/dC;
        db COS = DOT;

        db dA = solveQuad(1-r*r, 2*r*dC*COS, -(dC*dC));
        db T = dA / sSpd;
        x2 += dx*T*spd;
        y2 += dy*T*spd;
        x1 = x2, y1 = y2;
        cur += T + 1;
    };

    sor(a);
    db ans = BIG;
    do {
        cur = ts;
        x1=sOff, y1 = 0;
        f0(i,3) {
            f(i);
        }
        cur += pdist(x1, y1, 0, 0) / sSpd;
        ans = min(ans, cur);
    } while (next_permutation(all(a)));

    cout << fixed << setprecision(7) << ans - 1e-9 << endl;
}

signed main() {
    solve(); 

    return 0;
}
