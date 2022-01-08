#include <bits/stdc++.h>
using namespace std;

#define ll long long

//convert binary to decimal
ll fromBin(ll n)
{
    ll factor = 1;
    ll total = 0;

    while (n != 0)
    {
        total += (n%10) * factor;
        n /= 10;
        factor *= 2;
    }

    return total;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    cin >> s;
    cout << s << endl;
    unsigned ll n = stoul(s, nullptr, 2);
    
    int t = 1;
    int k = 0;
    
    while (t < n){
        t *= 4;
        ++k;
    }
    
    cout << k << endl;

    return 0;
}
