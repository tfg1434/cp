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
constexpr ll N = 100005;
ll cnt[N];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n; cin >> n;
    ll sum2 = 0, sum4 = 0;
    for (ll i = 0; i < n; i++) {
        ll x; cin >> x;
        
        sum2 -= cnt[x] / 2;
        sum4 -= cnt[x] / 4;
        cnt[x]++;
        sum2 += cnt[x] / 2;
        sum4 += cnt[x] / 4;
    }
    ll q; cin >> q;

    for (ll i = 0; i < q; i++) {
        char t; cin >> t;
        
        if (t == '+') {
            ll x; cin >> x;
            
            sum2 -= cnt[x] / 2;
            sum4 -= cnt[x] / 4;
            cnt[x]++;
            sum2 += cnt[x] / 2;
            sum4 += cnt[x] / 4;
        } else {
            ll x; cin >> x;
            
            sum2 -= cnt[x] / 2;
            sum4 -= cnt[x] / 4;
            cnt[x]--;
            sum2 += cnt[x] / 2;
            sum4 += cnt[x] / 4;
        }

        //sum2>=4 b/c two pairs already in square
        if (sum4 >= 1 && sum2 >= 4) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}

