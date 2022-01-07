#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct Cow{
    bool isNorth;
    int xPos, yPos;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<Cow> cows(N);
    for (int n = 0; n < N; n++) {
        Cow cow = cows[n];
        
        char dir;
        cin >> dir;
        cow.isNorth = dir == 'N';
        cin >> cow.xPos >> cow.yPos;
    }
    
    for (Cow cow : cows){
        if (cow.isNorth) {
            for (Cow innerCow:cows) {
                if (!(!innerCow.isNorth) && )
            }
        }
    }

    return 0;
}
