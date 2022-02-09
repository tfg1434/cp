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
    int checked = false;
};
constexpr int MAX_MN = 50;
Square castle[MAX_MN][MAX_MN];
int roomSize[MAX_MN * MAX_MN];
int M, N;

void floodFill(int component, int x, int y) {
    int walls;
    
    if (castle[y][x].checked) {
        assert("components equal" && castle[y][x].component == component);
        return;
    }
    
    castle[y][x].checked = true;
    castle[y][x].component = component;
    roomSize[component]++;
    walls = castle[y][x].walls;
    
    if (x > 0 && !(walls & DIR_WEST)) floodFill(component, x - 1, y);
    
    if (x+1 < M && !(walls & DIR_EAST)) floodFill(component, x + 1, y);
    
    if (y > 0 && !(walls & DIR_NORTH)) floodFill(component, x, y - 1);
    
    if (y+1 < N && !(walls & DIR_SOUTH)) floodFill(component, x, y + 1);
}

int main() {
    freopen("castle.in", "r", stdin);
    freopen("castle.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> M >> N;

    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < M; ++x) {
            castle[y][x] = {x, y};
            cin >> castle[y][x].walls;
        }
    }

    int component = 0;
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < M; ++x) {
            if (!castle[y][x].checked) {
                floodFill(component++, x, y);
            }
        }
    }
    int largest = *max_element(roomSize, roomSize + sizeof(roomSize) / sizeof(roomSize[0]));

    //only check east and north walls (prob says)
    //cant just check for walls, have to check if component is different.
    int largestPossible = 0;
    int xx, yy;
    char dir;
    for(int x=0; x<M; x++) {
        for (int y = N - 1; y >= 0; y--) {
            if (y > 0 && castle[y][x].component != castle[y - 1][x].component) {
                int n = roomSize[castle[y][x].component] + roomSize[castle[y - 1][x].component];
                if (n > largestPossible) {
                    largestPossible = n;
                    xx = x;
                    yy = y;
                    dir = 'N';
                }
            }
            if (x + 1 < M && castle[y][x].component != castle[y][x + 1].component) {
                int n = roomSize[castle[y][x].component] + roomSize[castle[y][x + 1].component];
                if (n > largestPossible) {
                    largestPossible = n;
                    xx = x;
                    yy = y;
                    dir = 'E';
                }
            }
        }
    }
    
    cout << component << '\n' << largest << '\n' << largestPossible << '\n' << yy+1 << ' ' << xx+1 << ' ' << dir << endl;
    
    return 0;
}
