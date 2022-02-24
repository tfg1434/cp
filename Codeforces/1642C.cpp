#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

int T;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while (T--) {
        int n, x; cin >> n >> x;
        vector<int> a(n);
        for (auto& i : a) cin >> i;
        sort(all(a));

        multiset<int> ms;
        for (auto& i : a) {
            if (i % x == 0 && ms.find(i/x) != ms.end())
                ms.erase(ms.find(i/x));
            else ms.insert(i);
        }

        cout << ms.size() << '\n';
    }    
    
    return 0;
}

