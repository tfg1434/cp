/*
ID: toronto4
TASK: maze1
LANG: C++14
*/
#include <bits/stdc++.h>
#include <limits>
using namespace std;

#define ll long long
enum WALLS {
    NORTH = 1,
    EAST = 2,
    SOUTH = 4,
    WEST = 8,
};

struct Node {
    int walls;
};

constexpr int max_w = 38;
constexpr int max_h = 100;
int W, H;
Node maze[max_h][max_w];
string temp[max_h];
int exit_x, exit_y;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
        
    cin >> W >> H;
    int sw = W*2+1;
    int sh = H*2+1;
    
    for (int i = 0; i < sh; ++i) 
        getline(cin, temp[i]);

    int xx = 0, yy = 0;
    for (int y = 1; y < sh; y+=2) {
        for (int x = 1; x < sw-1; x+=2) {
            int walls = 0;
            if (temp[y-1][x] == '-') walls |= NORTH;
            if (temp[y+1][x] == '-') walls |= SOUTH;
            if (temp[y][x-1] == '|') walls |= EAST; 
            if (temp[y][x+1] == '|') walls |= WEST;
            
            if (yy == 0 && temp[y-1][x] == ' ') {
                exit_x = xx;
                exit_y = 0;
            } else if (yy == H-1 && temp[y+1][x] == ' ') {
                exit_x = xx;
                exit_y = H-1;
            } else if (xx == 0 && temp[y][x-1] == ' ') {
                exit_x = 0;
                exit_y = yy;
            } else if (xx == W-1 && temp[y][x+1] == ' ') {
                exit_x = W-1;
                exit_y = yy;
            }
            
            xx++;
        }
        yy++;
    } 

    return 0;
}
