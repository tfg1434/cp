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


bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}

vector<ll> factorization(ll n) {
    vector<ll> first_primes;

    if (n == 1)
        return first_primes;

    for (ll d = 1, i = 2; i * i <= n && first_primes.size() <= 3;
         i += d, d = 2) {
        while (n % i == 0)
            first_primes.push_back(i), n /= i;
    }

    if (n > 1)
        first_primes.push_back(n);

    return first_primes;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll q; while (cin >> q) {
        vector<ll> primes = factorization(q);

        if (primes.size() <= 1) cout << "1\n0\n";
        else if (primes.size() == 2) cout << "2\n";
        else cout << "1\n" << primes[0]*primes[1] << '\n';
    }
    
    return 0;
}
 

