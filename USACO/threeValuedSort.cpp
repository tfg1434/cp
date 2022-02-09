/*
ID: toronto4
TASK: sort3
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int N;
int swaps = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    freopen("sort3.in", "r", stdin);
    freopen("sort3.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    vector<int> arr(N);
    int count[4] = { 0 };
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
        count[arr[i]]++;
    }

    int _1in2 = 0, _1in3 = 0, _2in1 = 0, _2in3 = 0, _3in1 = 0, _3in2 = 0;
    for (int i = 0; i < count[1]; ++i) {
        if (arr[i] == 2) _2in1++;
        else if (arr[i] == 3) _3in1++;
    }
    for (int i = count[1]; i < count[1] + count[2]; ++i) {
        if (arr[i] == 1) _1in2++;
        else if (arr[i] == 3) _3in2++;
    }
    for (int i = count[1] + count[2]; i < count[1] + count[2] + count[3]; ++i) {
        if (arr[i] == 1) _1in3++;
        else if (arr[i] == 2) _2in3++;
    }
    
    cout << min(_2in1, _1in2) + min(_3in1, _1in3) + min(_2in3, _3in2) + 2*(max(_2in1, _1in2) - min(_2in1, _1in2)) << endl;
    
    return 0;
}
