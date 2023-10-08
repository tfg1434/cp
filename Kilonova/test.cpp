#include <iostream>
#include <vector>
#define EZ ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

const int NMAX = 1e5, MOD = 1e9+7;
int n, m, l, fav, tot,dp[NMAX + 2][101]; 
bool viz[NMAX + 1];
vector<int> g[NMAX + 1];
vector<int> topsorted;

long long POW(long long a, long long b)
{
	if (b == 0)
		return 1;
	if (b % 2)
		return (1LL * a * POW(a, b - 1)) % MOD;
	long long x = POW(a, b / 2);
	return (x * x) % MOD;
}

void topsort(int nod)
{
	for (auto next_nod : g[nod])
	{
		if (!viz[next_nod])
			topsort(next_nod);
	}
	viz[nod] = 1;
	topsorted.push_back(nod);
}

void dfs(int nod)
{
	for (auto next_nod : g[nod])
	{
		for (int j = 0; j < l; j++)
			dp[next_nod][j + 1] = (dp[nod][j] + dp[next_nod][j + 1]) % MOD;
	}
}

int main()
{
	EZ
	cin >> n >> m >> l;
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
	}

	for (int i = 1; i <= n; ++i) 
		if (!viz[i])
			topsort(i);

	for (int i = 1; i <= n; i++)
		dp[i][0] = 1;

	for (int i = n - 1; i >= 0; i--)
		dfs(topsorted[i]);

	for (int i = 1; i <= n; i++)
		for (int k = 0; k <= l; k++)
			fav = (fav + dp[i][k] * (i == n)) % MOD, tot = (tot + dp[i][k]) % MOD;

    cout << fav << ' ' << tot << endl;
	cout << (fav * POW(tot, MOD - 2)) % MOD;
}
