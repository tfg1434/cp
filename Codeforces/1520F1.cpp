#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IN(A, B, C) assert(B <= A && A <= C)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll INFF = 1e18;


void f(ll l, ll r, ll k) {
    if (l == r) {
        cout << "! " << l << endl;
        return;
    }
    
    ll mid = (l + r) / 2;
    cout << "? " << l << ' ' << mid << endl;
    ll sum; cin >> sum;
    if ((mid - l + 1) - sum >= k) {
        f(l, mid, k);
    } else {
        f(mid+1, r, k - (mid - l + 1) + sum);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n, _; cin >> n >> _;
    ll k; cin >> k;

    f(1, n, k);
       
    return 0;
}

