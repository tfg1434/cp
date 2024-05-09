#include <bits/stdc++.h>
using namespace std;

string R() {
    string s;
    getline(cin, s);
    return s;
}

vector<int> S() {
    string line = R();
    vector<int> nums;
    int num = 0;
    for (char c : line) {
        if (c == ' ') {
            nums.push_back(num);
            num = 0;
        } else {
            num = num * 10 + (c - '0');
        }
    }
    nums.push_back(num);
    return nums;
}

void solve() {
    vector<int> input = S();
    int a = input[0], b = input[1], c = input[2], d = input[3];
    string s = R();

    int A = count(s.begin(), s.end(), 'A');
    int B = s.length() - A;

    if (a + c + d != A) {
        cout << "NO" << endl;
        return;
    }
    if (b + c + d != B) {
        cout << "NO" << endl;
        return;
    }

    vector<string> blocks;
    string cur = "";
    for (char x : s) {
        if (!cur.empty() && x == cur.back()) {
            blocks.push_back(cur);
            cur = x;
        } else {
            cur += x;
        }
    }
    blocks.push_back(cur);

    int either = 0;
    vector<int> ab_blocks, ba_blocks;
    for (const string& block : blocks) {
        if (block.length() < 2) {
            continue;
        }
        if (block.length() % 2) {
            either += block.length() / 2;
            continue;
        }
        if (block.substr(0, 2) == "AB") {
            ab_blocks.push_back(block.length() / 2);
        } else {
            ba_blocks.push_back(block.length() / 2);
        }
    }
    sort(ab_blocks.begin(), ab_blocks.end());
    sort(ba_blocks.begin(), ba_blocks.end());

    if (accumulate(ab_blocks.begin(), ab_blocks.end(), 0) <= c &&
        accumulate(ba_blocks.begin(), ba_blocks.end(), 0) <= d) {
        if (either >= c - accumulate(ab_blocks.begin(), ab_blocks.end(), 0) +
                       d - accumulate(ba_blocks.begin(), ba_blocks.end(), 0)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        return;
    }

    if (accumulate(ab_blocks.begin(), ab_blocks.end(), 0) >= c) {
        swap(ab_blocks, ba_blocks);
        swap(c, d);
    }

    if (accumulate(ab_blocks.begin(), ab_blocks.end(), 0) >= c) {
        cout << "YES" << endl;
        return;
    }

    int ab_sum = accumulate(ab_blocks.begin(), ab_blocks.end(), 0);
    int ba_extra = accumulate(ba_blocks.begin(), ba_blocks.end(), 0) - d;

    while (ba_extra > 1) {
        if (ba_blocks.back() <= ba_extra) {
            ab_sum += ba_blocks.back() - 1;
            ba_extra -= ba_blocks.back();
            ba_blocks.pop_back();
        } else {
            ab_sum += ba_extra - 1;
            break;
        }
    }

    if (either >= max(0, c - ab_sum)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        solve();
    }
    return 0;
}

