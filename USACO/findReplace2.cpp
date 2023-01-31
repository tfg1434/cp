#include <iostream>
#include <map>
#include <vector>
using namespace std;
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
// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }
#define gg(...) [](const auto&...x){ char c='='; cerr<<#__VA_ARGS__; ((cerr<<exchange(c,',')<<x),...); cerr<<endl; }(__VA_ARGS__);


constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll INFF = 1e18;

int main() {
	int T;
	cin >> T;
	for(int t = 0; t < T; t++) {
		string start1, end1;
		cin >> start1 >> end1;

		vector<pair<char, char>> chars;
		
		bool notpossible = false;
		for(int i = 0; i < start1.length(); i++) {
			for(int j = i + 1; j < start1.length(); j++) {
				if(start1[i] == start1[j] && end1[i] != end1[j]) {
					notpossible = true;
					break;
				}
			}
			if(start1[i] != end1[i]) {
				chars.push_back(make_pair(start1[i], end1[i]));
			}
		}

		if(notpossible) {
			cout << -1 << endl;
			continue;
		}

		int independents = 0;
		for(int i = 0; i < chars.size(); i++) {
			bool found = false;
			for(int j = 0; j < chars.size(); j++) {
				if(i == j) continue;
				if(chars[i].first == chars[j].second) {
					found = true;
					break;
				}
			}
			if(!found) {
				independents++;
				chars.erase(chars.begin() + i);
			}
		}


		int total = independents;
		for(int i = 0; i < cycles; i++) {
			total += (cyclesizes[i] == -1) ? 0 : cyclesizes[i] + 1;
			cout << cyclesizes[i] << " ";
		}

		cout << total << "\n";
	}

	return 0;
}
