#include <bits/stdc++.h>
using namespace std;
#define FOR(s, e, i) for(int i=s; i<e; ++i)
#define FORE(s, e, i) for(int i=s; i<=e; ++i)
#define ROF(e, s, i) for(int i=e; i>=s; --i)
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define YN(b) cout << (b ? "YES\n" : "NO\n")
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
template<typename T> istream& operator>>(istream& in, pair<T, T>& p) { in >> p.first >> p.second; return in; };
template<typename T> ostream& operator<<(ostream& out, pair<T, T>& p) { out << p.first << ' ' << p.second << '\n'; return out; };
template<typename T> istream& operator>>(istream& in, vector<T>& a) { for (auto& x : a) in >> x; return in; };
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) { for (auto& x : a) out << x << ' '; return out; };
 
void solve() {
	ll n, k;
	cin >> n >> k;
 
	vector<vector<ll>> grid(n, vector<ll>(n));
	for (auto& row : grid)
		for (ll& col : row)
			cin >> col;
 
	ll ans = 0;
	for (int i = 0; i + 1 < n; ++i) {
        ll here = 0;
		ll sum = 0;
		ll bad = -1;
		ll prev[2]{ -10000, -10000 };
		vector<ll> nextblock(n);
		nextblock[n-1] = n;
		for (int j = n - 2; j >= 0; --j) {
			nextblock[j] = nextblock[j + 1];
			if (grid[i][j + 1] >= 2 || grid[i + 1][j + 1] >= 2)
				nextblock[j] = j + 1;
		}
		for (int j = 0; j < n; ++j) {
			if (grid[i][j] == 3 || grid[i + 1][j] == 3) {
				sum = 0;
				prev[0] = prev[1] = -10000;
				bad = j;
				continue;
			}
			if (grid[i][j] == 2) {
				if (j - prev[0] > 2*k-1 && j - prev[1] > 2*k) sum = 0;
				sum += min(k, j - max(bad, max(prev[0], prev[1])));
				here += sum * min(k, nextblock[j] - j);
				//cout << i << ' ' << j << "       " << sum << ' ' << min(k, nextblock[j] - j) << "      " << sum * min(k, nextblock[j] - j) << ' ' << ans << endl;
				prev[0] = j;
			}
			else if (grid[i + 1][j] == 2) {
				if (j - prev[1] > 2*k-1 && j - prev[0] > 2*k) sum = 0;
				sum += min(k, j - max(bad, max(prev[0], prev[1])));
				here += sum * min(k, nextblock[j] - j);
				//cout << i << ' ' << j << "       " << sum << ' ' << min(k, nextblock[j] - j) << "      " << sum * min(k, nextblock[j] - j) << ' '<< ans << endl;
				prev[1] = j;
			}
		}

        cout << here << endl;
        ans += here;
	}
	cout << ans << endl;
}
 
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	int t = 1;// cin >> t;
	while (t--) solve();
}
