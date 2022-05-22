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


bool check(const vector<ll>& ans) {
    ll n = ans.size();
    ll ok = true;
    for (ll i = 1; i < n; i++) {
        ll y = abs(ans[i] - ans[i - 1]);

        if (y < 2 || y > 4) {
            ok = false;
            break;
        }
    }

    return ok;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<ll> a;
    for (ll x; cin >> x; ) a.push_back(x);
    bool myAns = check(a);

    if (myAns == false) {
        cout << "WA" << endl;
        return -1;
    }

    return 0;
}

