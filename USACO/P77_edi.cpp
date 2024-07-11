#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "algo/debug.h"
#endif

using P = pair<int, int>;
#define f first
#define s second

using ll = long long;

P operator+(P a, P b) { return {a.f + b.f, a.s + b.s}; }
P operator-(P a, P b) { return {a.f - b.f, a.s - b.s}; }
ll cross(P a, P b) { return (ll)a.f * b.s - (ll)a.s * b.f; }
ll cross(P a, P b, P c) { return cross(b - a, c - a); }
ll sq(ll x) { return x * x; }
ll norm(P p) { return sq(p.f) + sq(p.s); }
int half(P p) {
	if (p.f > 0 || (p.f == 0 && p.s > 0)) return 0;
	return 1;
}

// Graham Scan, assumes the hull has size > 1
vector<P> convex_hull(vector<P> v) {
	nth_element(begin(v), begin(v), end(v));
	const P leftmost = v[0];
	for (P &p : v) p = p - leftmost;
	sort(begin(v), end(v), [](P a, P b) { // sort points by argument
		if (cross(a, b) == 0) return norm(a) < norm(b);
		return cross(a, b) > 0;
	});
	vector<P> hull;
	for (P p : v) {
		while (hull.size() >= 2 && cross(end(hull)[-2], end(hull)[-1], p) <= 0)
			hull.pop_back();
		hull.push_back(p);
	}
	for (P &p : hull) p = p + leftmost;
	return hull;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N;
	cin >> N;
	P start{}; // lexicographically minimum reachable point
	vector<P> offsets;
	while (N--) {
		int G;
		cin >> G;
		vector<P> group(G);
		for (P &p : group) cin >> p.f >> p.s;
		vector<P> hull = convex_hull(group);
		start = start + hull[0];
		for (int i = 1; i <= hull.size(); ++i) {
			offsets.push_back(hull[i % hull.size()] - hull[i - 1]);
        }
	}
	// sort offsets by CCW angle such that (0, -1) comes last
	sort(begin(offsets), end(offsets), [](P a, P b) {
		if (half(a) != half(b)) return half(a) < half(b);
		return cross(a, b) > 0;
	});
    ps(offsets);
	ll ans = 0;
	// tour the hull in counterclockwise order
	for (int i = 0; i < offsets.size(); ++i) {
        ps(offsets[i]);
		ans = max(ans, norm(start));
		start = start + offsets[i];
	}
	cout << ans << "\n";
}
