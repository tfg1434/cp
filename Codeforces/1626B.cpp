#include <bits/stdc++.h>
using namespace std;

#define ll long long

int T;

struct Neighbour {
    string substr;
    int value;
    int idx;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while (T--) {
        string x;
        cin >> x;
        vector<int> ints(x.size());
        for (int i = 0; i < ints.size(); i++) {
            ints[i] = x[i] - '0';
        }

        bool broke = false;
        //start from end, tranformation will always make it smaller.
        for (int i = ints.size() - 2; i > 0; --i) {
            if (ints[i] + ints[i+1] >= 10) {
                ints[i+1] += ints[i] - 10;
                ints[i] = 1;
                broke = true;
                break;
            }
        } 
        //nothing sums to >= 10. choose last digit
        if (!broke) {
            ints[1] += ints[0];
            ints.pop_back(); 
        }
       
        for (auto i : ints) cout << i;
        
        cout << endl;
    }

    return 0;
}
