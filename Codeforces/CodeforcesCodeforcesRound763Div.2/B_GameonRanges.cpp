//  B. Game on Ranges

#include<bits/stdc++.h>

using namespace std;

int main() {
    int C;
    cin >> C;

    for (int c = 0; c < C; c++) {
        int n;
        cin >> n;

        vector<array<int, 2>> ranges;
        ranges.reserve(n);

        for (int i = 0; i < n; ++i) {
            int l, r;
            cin >> l >> r;
            array pair = {l, r};

            ranges.push_back(pair);
        }

        for (auto range : ranges) {
            cout << range[0] << " " << range[1] << endl;
        }

    }


    return 0;
}
