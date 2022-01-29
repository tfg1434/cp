/*
ID: toronto4
TASK: concom 
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long

constexpr int max_value = 101;
int N;
int arr[max_value][max_value];
bool controlling[max_value][max_value];

void updateControl(int I, int J) {
    if (controlling[I][J]) return;
    controlling[I][J] = true;
    
    //I 's holdings to J
    for (int i = 0; i < max_value; i++) 
        arr[I][i] += arr[J][i];
    
    //controlling I == controlling J
    for (int i = 0; i < max_value; ++i) {
        if (controlling[i][I])
            updateControl(i, J);
    }
    
    //updateControl I's controls
    for (int i = 0; i < max_value; ++i) {
        if (arr[I][i] > 50)
            updateControl(I, i);
    }
}

void updatePercent(int I, int J, int p) {
    //update %
    for (int i = 0; i < max_value; ++i) {
        if (controlling[i][I])
            arr[i][J] += p;
    }

    //look for new owners
    for (int i = 0; i < max_value; ++i) {
        if (arr[i][J] > 50)
            updateControl(i, J);
    }
}

int main() {
    freopen("concom.in", "r", stdin);
    freopen("concom.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    //own yourself
    for (int i = 0; i < max_value; ++i) controlling[i][i] = true; 
        
    cin >> N;
    for (int n = 0; n < N; ++n) {
        int I, J, P;
        cin >> I >> J >> P;
        
        updatePercent(I, J, P); 
    }

    for (int i = 0; i < max_value; ++i) {
        for (int j = 0; j < max_value; ++j) {
            if (i == j) continue;
            
            if (controlling[i][j])
                cout << i << " " << j << '\n';
        }
    }

    return 0;
}
