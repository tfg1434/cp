#include <bits/stdc++.h>     

using namespace std;

const int INF = int(1e9);

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	vector<int> pos;
	for(int i = 0; i < n; i++)
		if(a[i] == 1)
			pos.push_back(i);
	int k = pos.size();
	vector<vector<int>> dp(n + 1, vector<int>(k + 1, INF));
	dp[0][0] = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j <= k; j++)
		{
		 	if(dp[i][j] == INF) continue;
		 	dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
		 	if(j < k && a[i] == 0)
		 		dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + abs(pos[j] - i));
		}
	cout << dp[n][k] << endl;
}
