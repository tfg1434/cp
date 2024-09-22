#include <bits/stdc++.h>
using namespace std;
const int inf=1e9;

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
    int n; cin>>n;
    vs a(n);
    for(string&i:a)cin>>i;
    vector fre(n,vi(26));
    for(int i=0;i<n;i++){
        for(char c:a[i]){
            fre[i][c-'a']++;
        }
    }

    vi pc(p2(n));
    for(int m=0;m<p2(n);m++){
        vi min_fre(26,inf);
        for(int i=0;i<n;i++)if(m&p2(i)){
            for(int c=0;c<26;c++){
                ckmin(min_fre[c],fre[i][c]);
            }
        }
        for(int c=0;c<26;c++)if(min_fre[c]<inf)
            pc[m]+=min_fre[c];
    }

    vi dp(p2(n),inf);
    dp[0]=0;
    for(int i=0;i<n;i++){
        dp[p2(i)]=len(a[i])+1;
    }
    for(int m=0;m<p2(n);m++){
        for(int sm=m&(m-1);sm>0;sm=m&(sm-1)){
            ckmin(dp[m],dp[sm]+dp[m^sm]-pc[m]-1);
        }
    }

    cout<<dp[p2(n)-1]<<'\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
