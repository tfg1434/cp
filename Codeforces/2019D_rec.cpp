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

// struct Treap{
    // struct Node{
        // int x,y,l,r,mn;
        // Node(){
        // }
    // }
    // int root;
    // int merge(int &u,int l,int r){
        // if(l==-1)return void(u=r);
        // if(r==-1)return void(u=l);
        // if(t[l].y<t[r].y){
            // merge(t[l].r,t[l].r,r);
            // u=l;
        // }else{
            // merge(t[r].l,l,t[r].l);
            // u=r;
        // }
    // }
    // void split(int u,int X,int& l,int& r){
        // if(u==-1)return void(l=r=-1);
        // if(t[u].x<X){
            // split(t[u].r,X,t[u].r,r);
            // l=u;
        // }else{
            // split(t[u].l,X,l,t[u].l);
            // r=u;
        // }
    // }
    // int range_min(int u,int)
// }

void solve() {
    int n;cin>>n;
    vi a(n);
    for(int&i:a)cin>>i;
    multiset<int>b,c;
    for(int i=0;i<n;i++){
        b.ins(a[i]-i);
        c.ins(a[i]-(n-1-i));
    }
    int l=0,r=n;
    auto ml=[&](){
        a.erase(a.find(a[l]-l));
        l++;
    };
    auto mr=[&](){
        b.erase(b.find(a[r]-(n-r)));
        r--;
    };
    while(l<r){
        if(a[l]>=r-l&&a[r-1]>=r-l){
            ans+=*begin(b)>=1;
            ans+=*begin(c)>=1;
            ml(); mr();
        }
        else if(a[l]>=r-l)mr();
        else if(a[r]>=r-l)ml();
    }
    cout<<ans<<\n;
}

signed main() {
    srand(0);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc; while (tc--) solve();
    return 0;
}
