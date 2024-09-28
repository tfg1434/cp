#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int inf=1e18;

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
    int n,W;cin>>n>>W; 
    V<multiset<int>> greed(W+1);
    for(int i=0;i<n;i++){
        int w,v;cin>>w>>v;
        greed[w].ins(v-1);
    }

    vector f(W+1,vi(W+1));
    for(int w=1;w<=W;w++)if(len(greed[w])){
        for(int k=1;k<=W/w;k++){
            int mx=*rbegin(greed[w]);
            ckmax(f[w][k],f[w][k-1]+mx);
            greed[w].erase(greed[w].find(mx));
            greed[w].ins(mx-2);
        }
    }

    //dp(w,j)=score after processing items of weight <= w and cum weight j
    vector dp(W+1,vi(W+1));
    for(int w=1;w<=W;w++){
        for(int j=1;j<=W;j++){
            for(int k=0;j-k*w>=0;k++){
                ckmax(dp[w][j],dp[w-1][j-k*w]+f[w][k]);
            }
        }
    }

    cout<<*max_element(all(dp[W]))<<'\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
