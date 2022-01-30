#include <bits/stdc++.h>
using namespace std;

#define ll long long

string correct[3];
string guess[3];
map<char, int> countOf;
map<char, int> yellowOf;
map<char, int> greenOf;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 3; ++i) {
        cin >> correct[i];
    }
    for (int i = 0; i < 3; ++i) {
        cin >> guess[i];
    }
    
    int green = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            countOf[correct[i][j]]++;
            
            if (correct[i][j] == guess[i][j]) {
                green++;
                greenOf[correct[i][j]]++;
            }
        }
    }
    
    string bigstr;
    for (int i = 0; i < 3; ++i) {
        bigstr += correct[i];
    }
    int yellow = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (bigstr.find(guess[i][j]) != string::npos && yellowOf[guess[i][j]] < countOf[guess[i][j]] - greenOf[guess[i][j]] && correct[i][j] != guess[i][j]) {
                yellowOf[guess[i][j]]++;
                yellow++;
            }
        }
    }
    
    
    cout << green << '\n' << yellow << '\n';

    return 0;
}
