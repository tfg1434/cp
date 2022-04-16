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


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n; cin >> n;
    vector<ll> a(n+1);
    //get first 3
    ll _12, _13, _23;
    cout << "? 1 2" << endl; cin >> _12;
    cout << "? 1 3" << endl; cin >> _13;
    cout << "? 2 3" << endl; cin >> _23;
    a[3] = _13 - _12;
    a[1] = _13 - _23;
    a[2] = _13 - a[1] - a[3];

    ll idx = 4;
    while (idx <= n) {
        cout << "? " << idx-1 << " " << idx << endl;
        ll x; cin >> x;
        a[idx] = x - a[idx-1];
        idx++;
    }

    cout << "! ";
    for (int i = 1; i <= n; i++) cout << a[i] << " ";
    cout << endl;
    
    return 0;
}

