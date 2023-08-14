// Created by Qi Wang

#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORE(i, a, b) for (int i = (a); i <= (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define trav(a, x) for (auto &a : x)

typedef long long ll;

struct Cow {
	pair<int, int> coor;
	int id;
	Cow(pair<int, int> p, int i) {
		coor = p;
		id = i;
	}
};

int N;
vector<Cow> C_N;
vector<Cow> C_E;
#ifdef I_AM_NOOB
#define gg(...) [](const auto&...x){ char c='='; cerr<<#__VA_ARGS__; ((cerr<<exchange(c,',')<<x),...); cerr<<endl; }(__VA_ARGS__);
#else
#define gg(...) 777771449
#endif

// Custom sorting methods
bool cmp(const Cow &o, const Cow &t) {
	if (o.coor.first == t.coor.first) { return o.coor.second < t.coor.second; }
	return o.coor.first < t.coor.first;
}

bool cmp2(const Cow &o, const Cow &t) {
	if (o.coor.second == t.coor.second) { return o.coor.first < t.coor.first; }
	return o.coor.second < t.coor.second;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	F0R(i, N) {
		int x, y;
		char d;
		cin >> d >> x >> y;
		if (d == 'N') {
			C_N.push_back(Cow({x, y}, i));
		} else {
			C_E.push_back(Cow({x, y}, i));
		}
	}

	sort(C_N.begin(), C_N.end(), cmp);
	sort(C_E.begin(), C_E.end(), cmp2);
    gg(C_N[57].coor.first, C_E[0].coor.second);

	bool stopped[2501];
	int blame[2501];
	fill(stopped, stopped + N, false);
	fill(blame, blame + N, 0);
	trav(c1, C_E) {
		trav(c2, C_N) {
			// Checks whether they intersect
			if (!stopped[c1.id] && !stopped[c2.id] &&
			    c1.coor.second >= c2.coor.second &&
			    c1.coor.first <= c2.coor.first) {
				int xlen = c2.coor.first - c1.coor.first;
				int ylen = c1.coor.second - c2.coor.second;

				// checks which cow will block the other
				if (ylen < xlen) {
                    gg(c1.id, c2.id);
					stopped[c1.id] = true;
					blame[c2.id] += 1 + blame[c1.id];
				} else if (ylen > xlen) {
					stopped[c2.id] = true;
					blame[c1.id] += 1 + blame[c2.id];
				}
			}
		}
	}
	F0R(i, N) { cout << blame[i] << "\n"; }
}
