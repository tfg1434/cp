#include <bits/stdc++.h>
using namespace std;

#define ll long long

int T, N;

void solve() {
    cin >> N;
    vector<int> a;
    set<int> s;
    for (int i = 1; i <= N; i++) s.insert(i);
    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;

        //both in perm & a
        if (s.count(x)) s.erase(x);
        else a.push_back(x);
    }
    std::sort(a.begin(), a.end());
    std::reverse(a.begin(), a.end());

    bool ok = true;
    for (const int& item:a) {
        auto iter = s.end();
        iter--;
        int n = *iter;
        if (n > (item-1) / 2) {
            ok = false;
            break;
        }
        s.erase(iter);
    }

    if (!ok) cout << -1 << endl;
    else cout << a.size() << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while (T--) {
        solve(); 
    }

    return 0;
}
