#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int n; cin>>n;
  ll s=9;
  cout<<"3 ";
  for (ll i=4; i<2*n-2; i+=2) {
    s+=i*i; cout<<i<<" ";
  }
  cout<<(s-1)/2<<" "<<(s+1)/2<<"\n";
}
