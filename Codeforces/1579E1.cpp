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
        int n; cin >> n;
        deque<int> dq;

        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            if (dq.size() == 0) {
                dq.push_back(x);
                continue;
            }

            if (x > dq.front()) {
                dq.push_back(x);
            } else {
                dq.push_front(x);
            }
        }

        for (auto& i : dq) cout << i << ' ';
        cout << '\n';
    }    
    
    return 0;
}

