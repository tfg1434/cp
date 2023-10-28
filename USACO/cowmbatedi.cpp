#include <bits/stdc++.h>
using namespace std;
 
#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
 
#define MN 100005
#define MA 26
int n, m, k;
string s;
int d[MA][MA];
int cst[MN][MA];
int ps[MN][MA];
int dp[MN][MA];
int mn[MN];
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // freopen("cowmbat.in", "r", stdin);
    // freopen("cowmbat.out", "w", stdout);
 
    cin >> n >> m >> k >> s;
    F0R(i, m) F0R(j, m) cin >> d[i][j];
    F0R(c, m) F0R(a, m) F0R(b, m)
        d[a][b] = min(d[a][b], d[a][c]+d[c][b]);
 
    FOR(i, 1, n){
        F0R(j, m){
            cst[i][j] = d[s[i-1]-'a'][j];
            ps[i][j] = ps[i-1][j]+cst[i][j];
            //cout << i << " " << j << " " << cst[i][j] << "\n";
        }
    }
    FOR(i, 1, n) cout << cst[i][0] << ' ';
    cout << endl;
    memset(dp, 0x3f, sizeof dp);
    memset(mn, 0x3f, sizeof mn);
    mn[0] = 0;
 
    FOR(i, 1, n){
        F0R(j, m){
            dp[i][j] = min(dp[i][j], dp[i-1][j]+cst[i][j]);
            if (i >= k) dp[i][j] = min(dp[i][j], ps[i][j]-ps[i-k][j]+mn[i-k]);
            // cout << "dp " << i << " " << j << " " << dp[i][j] << "\n";
            mn[i] = min(mn[i], dp[i][j]);
        }
    }

    cout << mn[n] << "\n";
}

