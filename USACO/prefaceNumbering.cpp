/*
ID: toronto4
TASK: preface
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int N;
int I = 0, V = 0, X = 0, L = 0, C = 0, D = 0, M = 0;

/*
 * No more than 3 consecutive 10^n digits
 * No more than 1 consecutive 5*10^n digits
 * 
 * I   1     L   50    M  1000
 * V   5     C  100
 * X  10     D  500
 */

void solve(int x) {
    int dI = 0, dV = 0, dX = 0, dL = 0, dC = 0, dD = 0, dM = 0;
    
    for ( ; x >= 1000; x -= 1000, dM++) {}
    for ( ; x >= 500; x -= 500, dD++) {}
    for ( ; x >= 100; x -= 100, dC++) {}
    for ( ; x >= 50; x -= 50, dL++) {}
    for ( ; x >= 10; x -= 10, dX++) {}
    for ( ; x >= 5; x -= 5, dV++) {}
    for ( ; x >= 1; x -= 1, dI++) {}
    
    //6 swaps (IV, VX, XL, LC, CD, DM)
    
    //trade one D (500) and 4 C (400) for one M (1000) - one C (100)
    while (dD > 0 && dC/4 > 0){
        dD--; dC -= 4; dM++; dC++;
    }
    
    //trade four C (400) for one D (500) - one (C)
    while (dC >= 4) {
        dC -= 4; dD++; dC++;
    }
    
    //trade one L (50) and four X (40) for one C (100) - one X (10)
    while (dL > 0 && dX/4 > 0){
        dL--; dX -= 4; dC++; dX++;
    }
    
    //trade four X (40) for one L (50) - one X (10)
    while (dX >= 4) {
        dX -= 4; dL++; dX++;
    }
    
    //trade one V (5) and four I (4) for one X (10) - one I (1)
    while (dV > 0 && dI/4 > 0){
        dV--; dI -= 4; dX++; dI++;
    }
    
    //trade four I (4) for one V (5) - one I (1)
    while (dI >= 4) {
        dI -= 4; dV++; dI++;
    }
    
    I += dI, V += dV, X += dX, L += dL, C += dC, D += dD, M += dM;
}

int main() {
    freopen("preface.in", "r", stdin);
    freopen("preface.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    
    for (int i = 1; i <= N; ++i) solve(i);
    
    if (I != 0) cout << 'I' << ' ' << I << '\n';
    
    if (V != 0) cout << 'V' << ' ' << V << '\n';
    
    if (X != 0) cout << 'X' << ' ' << X << '\n';
    
    if (L != 0) cout << 'L' << ' ' << L << '\n';
    
    if (C != 0) cout << 'C' << ' ' << C << '\n';
    
    if (D != 0) cout << 'D' << ' ' << D << '\n';
    
    if (M != 0) cout << 'M' << ' ' << M << '\n';
    
    return 0;
}
