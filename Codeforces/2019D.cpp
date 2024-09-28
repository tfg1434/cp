#include <bits/stdc++.h>
using namespace std;

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

void solve() {
    int n;cin>>n;
    vi a(n);
    for(int&i:a)cin>>i;
    vi mn(n+1,n),mx(n+1,0);
    for(int i=0;i<n;i++){
        ckmin(mn[a[i]],i);
        ckmax(mx[a[i]],i);
    }
    for(int i=1;i<n;i++){
        ckmin(mn[i+1],mn[i]);
        ckmax(mx[i+1],mx[i]);
    }
    // ps(a);
    // for(int i=1;i<=n;i++)ps(i,mn[i],mx[i]);
    for(int i=1;i<=n;i++){
        if(mx[i]-mn[i]+1>i){
            cout<<"0\n";
            return;
        }
    }
    int l=0,r=n-1;
    for(int i=1;i<=n;i++){
        int L=mx[i]-i+1;
        int R=mn[i]+i-1;
        ckmax(l,L);
        ckmin(r,R);
    }
    cout<<max(0,r-l+1)<<'\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc; while (tc--) solve();
    return 0;
}

