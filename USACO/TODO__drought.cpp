#include <bits/stdc++.h>
using namespace std;

#define ll long long

int T, N;

bool isImpossible(const vector<int>& v) {
    int firstCount = 0, secondCount = 0;
    int first = v[0], second = -1;

    for (auto item:v) {
        if (item == first) continue;
        
        if (second == -1) {
            second = item;
            continue;
        }
        
        if (second != item) {
            return false;
        }
    }
    
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    
    for (int t = 0; t < T; ++t) {
        cin >> N;

        vector<int> v(N);
        for (int i = 0; i < N; ++i) {
            cin >> v[i];
        }
        
        int bags = 0;
        while (true) {
            sort(v.begin(), v.end());
            if (isImpossible(v)) {
                cout << -1 << endl;
                break;
            }

            int diff = v[v.size() - 1] - v[0];
            v[v.size() - 1] -= diff;
            v[v.size() - 2] -= diff;
            bags += diff*2;
            
            if (!all_of(v.begin(), v.end(), [v](int x) { return x == v[0]; })) {
                cout << diff << endl;
                break;
            }
        }
        
    }

    return 0;
}


