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
    
    ll n; cin>>n;
    ll z;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 1; i <= n / 3; i++)
        if (n % i == 0)
            for (int j = 0; j < i; j++) {
                z = 1;
                for (int k = j; k < n; k += i)
                    z &= a[k];

                if (z) {
                    cout << "YES";
                    return 0;
                }
            }
    cout << "NO";

    return 0;
}

