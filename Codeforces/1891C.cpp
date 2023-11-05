#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0); cin.exceptions(cin.failbit);
  
  int t; cin>>t;
  while (t--) {
    int n; cin>>n;
    vector<int> a(n); for (int& x: a) cin>>x;
    sort(a.begin(), a.end());
    
    vector<uint64_t> sum_f(n,a[0]), sum_b(n+1,0);
    for (int i=1; i<n; i++) sum_f[i]=sum_f[i-1]+a[i];
    for (int i=n-1; i>=0; i--) sum_b[i]=sum_b[i+1]+a[i];

    uint64_t min_cost=UINT64_MAX;
    for (int i=0; i<n; i++) {
      if (sum_f[i]>=sum_b[i+1]) {
        min_cost=min(min_cost, n-1-i + sum_f[i]);
      }
      
      uint64_t x = i==0 ? 0 : sum_f[i-1];
      if (x >= sum_b[i+1]) {
        int d = x-sum_b[i+1];
        min_cost=min(min_cost,
          n-1-i + x + min({(max(a[i]-d,0)+1)/2 + 1, a[i], max(a[i]-d,0)+1}));
      }
    }

    cout<<min_cost<<"\n";
  }
}
