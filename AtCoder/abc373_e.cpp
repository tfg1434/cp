#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int inf = 1e18;

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
    int n,m,k;cin>>n>>m>>k;
    V<array<int,2>>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i][0];
        a[i][1]=i;
        k-=a[i][0];
    }
    sort(all(a));
    vi pre(n+1);
    for(int i=0;i<n;i++)pre[i+1]=pre[i]+a[i][0];
    map<int,int>ans;

    // ps(a);
    for(int i=0;i<n;i++){
        //if all k votes go to me
        int big=lwb(a,{a[i][0]+k,inf});
        if(n-big>=m){
            ans[i]=-1;
            continue;
        }
        
        int lo=-1,hi=k;//how many votes go to me. i can win if i receive hi
        while(hi-lo>1){
            int mi=(lo+hi)/2;
            int big=lwb(a,{a[i][0]+mi,inf});
            int lb=0,rb=big;//how many candidates can we push to have >a[i]+mi votes. at least lb
            while(rb-lb>1){
                int mb=(lb+rb)/2;
                int cost=0;
                if(big-i-1>=mb){
                    // cost=mb*(a[i][0]+mi+1)-(pre[big]-pre[big-mb]);
                }else{
                    cost+=(big-i-1)*(a[i][0]+mi+1)-(pre[big]-pre[i+1]);
                    int MB=mb-(big-i-1);
                    cost+=MB*(a[i][0]+mi+1)-(pre[i]-pre[i-MB]);
                }
                // ps("mb cost",mb,cost);
                cost<=k-mi?lb=mb:rb=mb;
            }
            // ps(k-mi,lb);
            // ps(a[i][0],mi,lb,n-big+lb);
            n-big+lb<m?hi=mi:lo=mi;
        }
        ans[a[i][0]]=hi;
        // ps("=",hi);
    }
    vi output(n);
    for(int i=0;i<n;i++){
        output[a[i][1]]=ans[a[i][0]];
    }
    for(int i=0;i<n;i++)cout<<output[i]<<" \n"[i==n-1];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
