#include <bits/stdc++.h>
using namespace std;

int ask(int i, int j) {
    assert(i < j);
    cout << "? " << i << " " << j << endl;
    int res;
    cin >> res;
    return res;
}

int main() {
    int n;
    cin >> n;
    int P = 0, pos = -1;
    vector<int> ans(n + 1, 0);

    for (int i = 2; i <= n; ++i) {
        int l = ask(1, i);

        vector<int> primes;
        for (int j = 2; j * j <= l; ++j) {
            if (l % j == 0) {
                while (l % j == 0) {
                    l /= j;
                }
                primes.push_back(j);
            }
        }
        if (l > 1) {
            primes.push_back(l);
        }

        if (*max_element(primes.begin(), primes.end()) > P) {
            P = *max_element(primes.begin(), primes.end());
            pos = i;
        }
    }

    if (ask(1, 2) % P == 0 && ask(1, 3) % P == 0) {
        pos = 1;
    }

    ans[pos] = P;
    for (int i = 1; i <= n; ++i) {
        if (i == pos) {
            continue;
        }
        ans[i] = ask(min(pos, i), max(pos, i)) / P;
    }

    cout << "!";
    for (int i = 1; i <= n; ++i) {
        cout << " " << ans[i];
    }
    cout << endl;

    return 0;
}

