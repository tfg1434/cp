/*
ID: toronto4
TASK: maze1
LANG: C++14
*/
#include <bits/stdc++.h>

using Point = std::pair<int, int>;
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
char maze[210][80];
queue<Point> Q;
queue<int> D;
int exits[2];

int main() {
    freopen("maze1.in", "r", stdin);
    freopen("maze1.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
        
    cin >> W >> H;
    int sw = W*2+1;
    int sh = H*2+1;
    int d = 0;

    for (int i = 0; i < sh; ++i) {
        cin.get();
        cin.get(maze[i], 80);
        
        if (i == 0 || i == sh-1){
            for (int j = 0; j < sw; j++) {
                if (maze[i][j] == ' ') {
                    if (i == 0) exits[0] = 1;
                    else if (i == sh-1) exits[0] = sh - 2;
                    
                    exits[1] = j;
                    Q.push({exits[0], exits[1]});
                    D.push(1);
                }
            }
        } else {
            if (maze[i][0] == ' ') {
                exits[0] = i; 
                exits[1] = 1;
                Q.push({exits[0], exits[1]});
                D.push(1);
            } else if (maze[i][sw-1] == ' ') {
                exits[0] = i; 
                exits[1] = sw-2;
                Q.push({exits[0], exits[1]});
                D.push(1);
            }
        }
    }
    
    while (!Q.empty()) {
        Point p = Q.front(); 
        Q.pop();
        d = D.front();
        D.pop();
        
        if (p.first >= 3 && maze[p.first-1][p.second] == ' ' && maze[p.first-2][p.second] != 'x') {
            maze[p.first-2][p.second] = 'x';
            Q.push(make_pair(p.first-2, p.second));
            D.push(d+1);
        } 
        if (p.first <= sh - 3 - 1 && maze[p.first+1][p.second] == ' ' && maze[p.first+2][p.second] != 'x') {
            maze[p.first+2][p.second] = 'x';
            Q.push(make_pair(p.first+2, p.second));
            D.push(d+1);
        } 
        if (p.second >= 3 && maze[p.first][p.second-1] == ' ' && maze[p.first][p.second-2] != 'x') {
            maze[p.first][p.second-2] = 'x';
            Q.push(make_pair(p.first, p.second-2));
            D.push(d+1);
        } 
        if (p.second <= sw - 3 - 1 && maze[p.first][p.second+1] == ' ' && maze[p.first][p.second+2] != 'x') {
            maze[p.first][p.second+2] = 'x';
            Q.push(make_pair(p.first, p.second+2));
            D.push(d+1);
        }
    }
    
    cout << d << endl;
    
    return 0;
}
