#include <bits/stdc++.h>
#include <cassert>
using namespace std;

#define ll long long

int T;
array<int, 4> A, B;
int table[4][4];
vector<set<int>> seen;

double percentGreaterThan(array<int, 4> arr, int x) {
    double res = 0;

    for (int i = 0; i < 4; ++i) {
        if (x > arr[i]) res += 0.25;
    }
    
    return res;
}

//probability a will beat b
int willWin(array<int, 4> a, array<int, 4> b) {
    int aCount = 0, bCount = 0;
    
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (a[i] > b[j]) aCount++;
            else if (a[i] < b[j]) bCount++;
        }
    }
    
    if (aCount == bCount) return 0;
    if (aCount > bCount) return 1;
    /*if (aCount < bCount)*/ return -1;
//    map<int, float> chanceA;
//    map<int, float> chanceB;
//    for (int i = 0; i < 4; ++i) {
//        chanceA[a[i]] += 0.25;
//        chanceB[b[i]] += 0.25;
//    }
//
//    double ans = 0;
//    for (auto const& [key, value] : chanceA) {
//        ans += value * percentGreaterThan(b, key);
//    }
//    
//    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

//    cout << willWin({2, 2, 2, 2}, {1, 1, 2, 2}) << endl;
//    cout << willWin({1, 1, 2, 2}, {1, 1, 1, 1}) << endl;
    
//    cout << willWin({4, 5, 6, 7}, {2, 4, 5, 10}) << endl;
//    cout << willWin({2, 4, 5, 10}, {1, 4, 8, 9}) << endl;
//    cout << willWin({1, 4, 8, 9}, {4, 5, 6, 7}) << endl;

    cin >> T;
    array<int, 4> die;
    for (int t = 0; t < T; ++t) {
        DONE: ;
        
        for (int i = 0; i < 4; ++i) cin >> A[i];
        for (int i = 0; i < 4; ++i) 
            cin >> B[i];
        
        if (willWin(A, B) <= 0) {
            cout << "no" << endl;
            continue;
        }
        for (int i = 1; i <= 10; ++i) {
            for (int j = 1; j <= 10; ++j) {
                for (int k = 1; k <= 10; ++k) {
                    for (int l = 1; l <= 10; ++l) {
                        if (std::count(seen.begin(), seen.end(), set<int>{i, j, k, l})) continue;
                        seen.push_back({i, j, k, l});
                        
                        die[0] = i;die[1] = j;die[2] = k;die[3] = l;

                        if (willWin(B, die) == 1 && willWin(die, A) == 1) {
                            cout << "yes" << endl;
                            t++;
                            goto DONE;
                        }
                    }
                }
            }
        }

        cout << "no" << endl;
    }
    
    return 0;
}
