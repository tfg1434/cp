//  B. Game on Ranges

#include<bits/stdc++.h>

using namespace std;

int main() {
    int C;
    cin >> C;

    for (int c = 0; c < C; c++) {
        int n;
        cin >> n;

        vector mark(n+1, vector<bool>(n+1));
        vector<int> l(n), r(n);

        for (int i = 0; i < n; ++i) {
            cin >> l[i] >> r[i];
            
            mark[l[i]][r[i]] = true;
        }

        for (int i = 0; i < n; ++i) {
            for (int d = l[i]; d <= r[i]; ++d) {
                if ((d == l[i] || mark[l[i]][d-1]) && (d == r[i] || mark[d+1][r[i]])) {
                    cout << l[i] << " " << r[i] << " " << d << '\n';
                    
                    break;
                }
            }
        }
        
        
//        vector<array<int, 2>> ranges;
//        ranges.reserve(n);
//
//        for (int i = 0; i < n; ++i) {
//            int l, r;
//            cin >> l >> r;
//            //cout << "DEBUG" << l << " " << r << endl;
//            array pair = {l, r};
//
//            ranges.push_back(pair);
//        }

        
        
    }


    return 0;
}
