#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3,unroll-loops")

using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()

const ll oo = 1e17;
const ll mod = 1e9+7; // 998244353;
const int N = 1e5+5;;
array<vector<int>, N> divisors;

//try array :)
ll undo[100005];

void solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i <n; i++){
        cin>>v[i];
    }
    sort(all(v));
    ll ans = 0;
    vector<int> cnt(v.back()+1);
    for(int i = 0; i <n; i++){
        ll temp = 0;
        for(int k = divisors[v[i]].size()-1; k>=0; k--){
            int d = divisors[v[i]][k];
            temp+=(ll)d*(ll)cnt[d];
            for(int j = 0; j < (int)divisors[d].size(); j++){
                undo[divisors[d][j]]+=cnt[d];
                cnt[divisors[d][j]]-=cnt[d];
            }
        }

        cout << (cnt[1]) << endl;
        ans+=temp*(ll)(n-i-1);
        // cout << "\n";
        for(auto d: divisors[v[i]])
            cnt[d]++;
        for(auto d: divisors[v[i]]){
            cnt[d]+=undo[d];
            undo[d]=0;
        }
    }
    cout << ans << "\n";
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t = 1;
    cin >> t;
    for(int i = 1; i <N; i++){
        for(int j = i; j < N; j+=i){
            divisors[j].push_back(i);
        }
    }
    for(int i = 1; i <=t; i++){
        solve();
    }
    return 0;
}
