#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define len(a) (ll)((a).size())
#define IN(A, B, C) assert(B <= A && A <= C)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll INFF = 1e18;
ll maxSum(ll arr[], ll n, ll k) {
  // k must be smaller than n
  if (n < k) {
    cout << "Invalid";
    return -1;
  }

  // Compute sum of first window of size k
  ll res = 0;
  for (ll i = 0; i < k; i++)
    res += arr[i];

  // Compute sums of remaining windows by
  // removing first element of previous
  // window and adding last element of
  // current window.
  ll curr_sum = res;
  for (ll i = k; i < n; i++) {
    curr_sum += arr[i] - arr[i - k];
    res = max(res, curr_sum);
  }

  return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T; while (T--) {
        ll n, k; cin >> n >> k;
        vector<ll> a(n);
        for (auto &x : a) cin >> x;

        if (k <= n) {
            cout << maxSum(a.data(), n, k) + k*(k-1)/2 << '\n';
            continue;
        }

        ll pos = (k % n);
        ll ans = 0;
        for (ll i = 0; i + pos < n; i++) {
            ans += a[i+pos] + i;
            a[i+pos] = 0;
            k--;
        }
        for (ll i = 0; i < n; i++) {
            ans += a[n-1-i] + i;
            a[n-1-i] = 0;
            k--;
        }
        
        while (k > 0) {
            for (ll i = 1; i < n && k > 0; i++) {
                ans += i;
                k--;
            }
        }

        cout << ans << '\n';
    }    
    
    return 0;
}

