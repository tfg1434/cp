//  A. Robot Cleaner

#include<bits/stdc++.h>

using namespace std;

//n rows, m columns
//dirty cell at Rd, Cd
//initial pos at Rb, Cb

bool didClean(int rb, int cb, int rd, int cd) {
    return rb == rd || cb == cd;
}

int main() {
    int C;
    scanf("%d", &C);

    for (int c = 0; c < C; c++) {
        int n, m, rb, cb, rd, cd;
        scanf("%d %d %d %d %d %d", &n, &m, &rb, &cb, &rd, &cd);
        
        int dr = 1;
        int dc = 1;
        int t = 0;
        
        if (didClean(rb, cb, rd, cd)) {
            cout << t << '\n';
            continue;
        }
        
        while (rb != rd && cb != cd){
            if (rb + dr > n)
                dr = -dr;
            
            if (cb + dc > m)
                dc = -dc;
            
            rb += dr;
            cb += dc;
            t++;
        }

        cout << t << '\n';
    }
    
    
    

    return 0;
}
