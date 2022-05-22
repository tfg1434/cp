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


struct seg {
    ll l, r;
    bool operator < (const seg& s) const {
        ll a = r - l;
        ll b = s.r - s.l;
        if (a != b) return a < b;
        return l > s.l;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T; while (T--) {
        ll n; cin >> n;

        priority_queue<seg> pq;
        vector<ll> ans(n, 0);
        pq.push({1, n});

        for (ll i = 1; i <= n; i++) {
            seg top = pq.top();
            pq.pop();
            ll l = top.l, r = top.r;
            ll mid;
            if ((r-l+1) & 1) mid = (l + r) / 2;
            else mid = (l + r - 1) / 2;

            ans[mid-1] = i;
            if (mid != l) pq.push({l, mid-1});
            if (mid != r) pq.push({mid+1, r});
        }

        for (auto x : ans) cout << x << ' ';
        cout << '\n';
    }    
    
    return 0;
}

