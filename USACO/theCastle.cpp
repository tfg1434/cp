/*
ID: toronto4
TASK: castle
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
constexpr int nil = -1;

enum DIR {
    DIR_NORTH = 2,
    DIR_EAST = 4,
    DIR_SOUTH = 8,
    DIR_WEST = 1,
};

struct Square {
    int x, y;
    int walls;
    int component = nil;
};
int transX[9];
int transY[9];

constexpr int MAX_MN = 50;
Square castle[MAX_MN][MAX_MN];
int M, N;

void floodFill(int newComponent) {
    int nVisited;
    
    do {
        nVisited = 0;

        for (int y = 0; y < N; ++y) {
            for (int x = 0; x < M; ++x) {
                Square node = castle[y][x];
                
                if (node.component == -2) {
                    nVisited++;
                    node.component = newComponent;

                    for (int k = DIR_WEST; k <= DIR_SOUTH; k <<= 1) {
                        //remember, it's negated (we can't go through walls)
                        if (!(node.walls & k)) {
                            int nx = x + transX[k];
                            int ny = y + transY[k];
                            
                            if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
                                if (castle[ny][nx].component == nil)
                                    castle[ny][nx].component = -2;
                            }
                        }
                    }
                }
            }
        }

        cout << nVisited << endl;
        
    } while (nVisited != 0);
}

int solve() {
    int nComponents = 0;

    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < M; ++x) {
            castle[y][x].component = nil;
        }
    }
    
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < M; ++x) {
            cout << "d" << endl;
            
            if (castle[y][x].component == nil) {
                nComponents++;
                castle[y][x].component = -2;
                floodFill(nComponents);
            }
        }
    }
    
    return nComponents;
}

int main() {
//    freopen("castle.in", "r", stdin);
//    freopen("castle.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    transX[DIR_NORTH] = 0, transX[DIR_EAST] = 1, transX[DIR_SOUTH] = 0, transX[DIR_WEST] = -1;
    transY[DIR_NORTH] = -1, transY[DIR_EAST] = 0, transY[DIR_SOUTH] = 1, transY[DIR_WEST] = 0;
    
    cin >> M >> N;

    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < M; ++x) {
            castle[y][x] = {x, y};
            cin >> castle[y][x].walls;
        }
    }
    
    cout << "que?" << endl;
    
    cout << solve() << endl;

    return 0;
}
