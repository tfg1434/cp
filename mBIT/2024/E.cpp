#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll MOD=998244353;

ll powmod(ll x, ll p)
{
    if (p==0)
    {
        return 1;
    }
    ll val=powmod(x, p/2);
    val=(val*val)%MOD;
    if (p%2==1)
    {
        return (x*val)%MOD;
    }
    else
    {
        return val;
    }
}

ll modinverse(ll x)
{
    return powmod(x, MOD-2);
}

ll n, q, p[200001], prod[200001], dp[200001];

int main()
{
    cin >> n >> q;
    for (int i=1; i<=n; i++)
    {
        cin >> p[i];
        p[i]*=modinverse(100);
        p[i]=p[i]%MOD;
        prod[i]=p[i]*(prod[i-1]+1);
        prod[i]=prod[i]%MOD;
        dp[i]=(prod[i]+dp[i-1])%MOD;
    }
    while (q--)
    {
        ll k, x;
        cin >> k >> x;
        x*=modinverse(100);
        x=x%MOD;
        p[k]=x;
        for (int i=k; i<=n; i++)
        {
            prod[i]=(p[i]*(prod[i-1]+1))%MOD;
            dp[i]=(prod[i]+dp[i-1])%MOD;;
        }
        cout << dp[n] << "\n";
    }
}
