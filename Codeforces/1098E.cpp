#include <bits/stdc++.h>
using namespace std;
#define int int64_t

#ifdef LOCAL
#include "algo/debug.h"
#endif

#define f first
#define s second
template<class T> using V = vector<T>; 
using vi = V<int>;
using vb = V<bool>;
using vs = V<string>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x) 
#define len(x) (int)((x).size())
#define rsz resize
#define ins insert
#define ft front()
#define bk back()
#define pb push_back
#define lb lower_bound
#define ub upper_bound
template<class T> int lwb(V<T>& a, const T& b) { return lb(all(a),b)-begin(a); }
template<class T> int upb(V<T>& a, const T& b) { return ub(all(a),b)-begin(a); }
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a=b, true : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a=b, true : false; }
#define pct __builtin_popcount
#define ctz __builtin_ctz
#define clz __builtin_clz
constexpr int p2(int x) { return (int)1 << x; }
constexpr int bits(int x) { return x == 0 ? 0 : 31-clz(x); } // floor(log2(x)) 

int f(int a,int b,int c,int n){
    if(a==0)return((b/c)*(n+1));
    if(a>=c||b>=c)return f(a%c,b%c,c,n)+(a/c)*n*(n+1)/2+(b/c)*(n+1);
    int m=(a*n+b)/c;
    return n*m-f(c,c-b-1,a,m-1);
}

// \sum_{i=1}^n max(0,\lfloor\frac{a*i+b}{c}\rfloor)
int F(int a,int b, int c, int n) {
    if(a<0)b+=a*n,a=-a;
    if(b<0){
        int d=(b+a-1)/a;
        n-=d;
        b+=a*d;
    }
    if(n<0)return 0;
    return f(a,b,c,n)-b/c;
}

const int MAX = 1e5;
int c[MAX+1];

void solve() {
    int n; cin >> n;    
    vi a(n);
    for (int& i : a) cin >> i;
    V<array<int, 2>> v;
    for (int x : a) {
        V<array<int, 2>> nv = {{ x,1 }};
        for (auto [g, cnt] : v) {
            g = gcd(x, nv[0]);
            if (g != nv[0]) {
                nv.pb({g, 0});
            }
            nv.bk[1] += cnt;
        }
        v = nv;
        for (auto [g, cnt] : v) {
            c[g] += cnt;
        }
    }

    int n2=n*(n+1)/2, k=(n2*(n2+1)/2+1)/2, lb=1, rb=1e15;
    while (lb<rb) {
        int mb = (lb+rb)/2, b=0, s1=0, s2=0;
        for (int i = 1; i <= MAX; i++) {
            int ml=min(mb/i, c[i]);
            b+=ml*c[i]-ml*(ml-1)/2;
        }
        for (int i1=1, i2=2; i1<MAX; i1++) {
            b+=c[i1]*s1;
            while(i2<MAX&&(s2+i2*c[i2]<=mb||i2<=i1+1)){
                if(c[i2])
                    b+=F(c[i1]-1,i1,mb-s2-i1*c[i1],i2)-;
                s1+=c[i2];
                s2+=i2*c[i2];
                i2++;
            }
            if(c[i2])
                b+=gul(c[i1]-1,mb-s2-i1*c[i1],i2)

        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
