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

int ask(int x, int y) {
    cout << "? " << x+1 << ' ' << y+1 << endl;
    int res; cin >> res;
    if (res == -1) {
        exit(-1);
    }
    return res;
}

void solve() {
    int n, m, q; cin >> n >> m >> q;
    vi ans;
    vi typ(n);
    for (int b = 0; b < 50; b++) {
        if (b==49&&!len(ans)){
            for(int i=b*20;i+1<(b+1)*20;i++){
                int is_fake=ask(0,i);
                if(is_fake)ans.pb(i);
            }
            if(len(ans)<10)ans.pb((b+1)*20-1);
            break;
        }

        for (int i = b*20; i+1 < (b+1)*20; i++) {
            typ[i+1] = ask(i, i+1) ? 1-typ[i] : typ[i];
        }
        int ones = 0;
        for (int i = b*20; i < (b+1)*20; i++) ones += typ[i];
        if(ones==10){
            int first_is_fake=ask((b+1)*20%n,b*20);
            if(first_is_fake)ans.pb(b*20);
            for(int i=b*20+1;i+1<(b+1)*20;i++){
                int is_fake=typ[b*20]^typ[i]^first_is_fake;
                if(is_fake)ans.pb(i);
            }
            if(len(ans)<10)ans.pb((b+1)*20-1);
            assert(len(ans)==10);
            break;
        }
        for (int i = b*20; i < (b+1)*20; i++) if(ones>10&&!typ[i]||ones<10&&typ[i]){
            ans.pb(i);
        }
    }

    cout<<"! ";
    for(int i=0;i<len(ans);i++)cout<<ans[i]+1<<" \n"[i==len(ans)-1];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
