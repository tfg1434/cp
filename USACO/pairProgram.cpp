#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 2e3 + 1;
const int MOD = 1e9 + 7;

// adding and subtracing under mod
ll ad(ll &a, ll b) { return a = (a + b) % MOD; }
ll sb(ll &a, ll b) { return a = (((a - b) % MOD) + MOD) % MOD; }

int main() {
	int test_num;
	cin >> test_num;
	for (int t = 0; t < test_num; t++) {
		int n;
		cin >> n;
		vector<char> a(n + 1), b(n + 1);
		for (int i = 1; i <= n; i++) { cin >> a[i]; }
		for (int i = 1; i <= n; i++) { cin >> b[i]; }

		// zero[i][j] -> whether 0 is in I(i, j)
		vector<vector<bool>> zero(n + 1, vector<bool>(n + 1));
		// I(0, 0) = {0}
		zero[0][0] = true;
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				if (!i && !j) continue;
				// I(i, j) contains 0 if:
				// 1. a[i] or b[j] = 0
				// 2. I(i - 1, j) contains 0 and a[i] isn't +x
				// 3. I(i, j - 1) contains 0 and b[j] isn't +x
				zero[i][j] = a[i] == '0' || b[j] == '0' ||
				             i && zero[i - 1][j] && a[i] != '+' ||
				             j && zero[i][j - 1] && b[j] != '+';
			}
		}

		// dp[i][j] -> number of nonzero expressions in I(i, j)
		vector<vector<ll>> dp(n + 1, vector<ll>(n + 1));
		dp[0][0] = 0;
		// |I(i, 0)| = |I(0, i)| = 1 ->
		// # of nonzero expressions = 1 - # of zero expressions
		for (int i = 1; i <= n; i++) {
			dp[0][i] = !zero[0][i];
			dp[i][0] = !zero[i][0];
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dp[i][j] = 0;
				if (a[i] != '0') { ad(dp[i][j], dp[i - 1][j]); }
				if (a[i] == '+') { ad(dp[i][j], zero[i - 1][j]); }
				if (b[j] != '0') { ad(dp[i][j], dp[i][j - 1]); }
				if (b[j] == '+') { ad(dp[i][j], zero[i][j - 1]); }
				// subtracting the intersection of A and B
				if (a[i] == '+' && b[j] == '+' || a[i] == '1' && b[j] == '+' ||
				    a[i] == '+' && b[j] == '1') {
					sb(dp[i][j], dp[i - 1][j - 1] + zero[i - 1][j - 1]);
				} else if (isdigit(a[i]) && isdigit(b[j])) {
					sb(dp[i][j], dp[i - 1][j - 1]);
				}
			}
		}

		cout << ad(dp[n][n], zero[n][n]) << '\n';
	}
}
