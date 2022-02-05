#include <bits/stdc++.h>
using namespace std;

#define ll long long

int T;
int t,n,A[1'000'000],s;
pair<int,int>p[1'000'000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while (T--) {
        cin >> n;
        for(int i=1;i<=n;i++)
            cin>>p[i].first,p[i].second=i;
        sort(p+1,p+n+1),s=0;
        for(int i=1;i<=n;i++)
            A[p[i].second]=pow(-1,i&1)*(n-i+2)/2,s+=2*abs(A[p[i].second])*p[i].first;
        cout<<s<<'\n';
        for(int i=0;i<=n;i++)
            cout<<A[i]<<' ';
        cout<<'\n';
    }

    return 0;
}
