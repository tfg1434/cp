#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IN(A, B, C) assert(B <= A && A <= C)

constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll INFF = 1e18;
ll n, a, b;


ll op(ll x) {
    return (a*(x*x%n)+b)%n;
}

pll torHare(ll x) {
    ll tort = op(x), hare = op(op(x));
    while (tort != hare) {
        tort = op(tort);
        hare = op(op(hare));
    }

    ll mu = 0;
    hare = x;
    while (tort != hare) {
        tort = op(tort);
        hare = op(hare);
        ++mu;
    }

    ll lambda = 1;
    hare = op(tort);
    while (tort != hare) {
        hare = op(hare);
        ++lambda;
    }

    return {mu, lambda};
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while (cin >> n && n) {
        cin >> a >> b;

        pll ans = torHare(0);
        cout << n - ans.second << '\n';
    }
    
    return 0;
}

