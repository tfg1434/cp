#include <bits/stdc++.h>
using namespace std;

pair<int, int> doll[200000];
pair<pair<int, int>, int> query[200000];
int ans[200000];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> doll[i].first >> doll[i].second;
		doll[i].second = -doll[i].second;
	}
	for (int i = 0; i < q; i++) {
		cin >> query[i].first.first >> query[i].first.second;
		query[i].second = i;
	}
	sort(doll, doll + n, greater<pair<int, int>>());
	sort(query, query + q, greater<pair<pair<int, int>, int>>());

	vector<int> dp;
	for (int i = 0, j = 0; i < q; i++) {
		while (j < n && doll[j].first >= query[i].first.first) {
			int lds = upper_bound(dp.begin(), dp.end(),
			                      -doll[j].second) -
			          dp.begin();
			if (lds == dp.size())
				dp.push_back(-doll[j].second);
			else dp[lds] = -doll[j].second;
			j++;
		}
		ans[query[i].second] =
		    upper_bound(dp.begin(), dp.end(),
		                query[i].first.second) -
		    dp.begin();
	}

	for (int i = 0; i < q; i++) cout << ans[i] << '\n';
	return 0;
}
