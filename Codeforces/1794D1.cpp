#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
 
#define all(a) a.begin(),a.end()
#define pb push_back
#define sz(a) ((int)a.size())
 
const int N=1000005,M=5005,mod=998244353;
int add(int x, int y){x+=y; if(x>=mod) x-=mod; return x;}
int mul(int x, int y){return ((ll)x)*y%mod;}
int cnt[N],dp[M],ndp[M],fac[M],ifac[M];
bool isp[N];
 
void ahcorz(){
    isp[0]=isp[1]=0;
    for(int i=2; i<N; ++i) isp[i]=1;
    for(int i=2; i<N; ++i) if(isp[i]) for(int j=i*2; j<N; j+=i) isp[j]=0;
    fac[0]=ifac[0]=ifac[1]=1;
    for(int i=1; i<M; ++i) fac[i]=mul(fac[i-1],i);
    for(int i=2; i<M; ++i) ifac[i]=mul(ifac[mod%i],mod-mod/i);
    for(int i=2; i<M; ++i) ifac[i]=mul(ifac[i-1],ifac[i]);
    dp[0]=1;
    int n; cin >> n;
    for(int i=0; i<n*2; ++i){
        int x; cin >> x; cnt[x]++;
    }
    for(int i=1; i<N; ++i) if(cnt[i]){
        memset(ndp,0,sizeof ndp);
        for(int j=0; j<=n; ++j){
            ndp[j]=mul(dp[j],ifac[cnt[i]]);
        }
        if(isp[i]){
            for(int j=1; j<=n; ++j){
                ndp[j]=add(ndp[j],mul(dp[j-1],ifac[cnt[i]-1]));
            }
        }
        memcpy(dp,ndp,sizeof ndp);
    }
    cout << mul(dp[n],fac[n]) << "\n";
}
 
signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    int t; t=1; while(t--) ahcorz();
}
