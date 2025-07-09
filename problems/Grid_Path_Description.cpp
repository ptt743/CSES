#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<unordered_map>
#include<cmath>
#include<functional>
#define ll long long

using namespace std;
//*****taipt*****//
/*
*/
const int LEN = 48;                // 48 bước
const int dx[4] = {-1, +1, 0, 0};  // U D L R
const int dy[4] = { 0,  0,-1,+1};
string s;                           // chuỗi nhập
bool vis[7][7];
long long ans = 0;

inline bool in(int x, int y) { return 0 <= x && x < 7 && 0 <= y && y < 7; }

void dfs(int x, int y, int idx) {
    if (idx == LEN) {          // đi đủ 48 bước
        if (x == 6 && y == 0) ++ans;
        return;
    }
    if (x == 6 && y == 0) return;                       // đến đích quá sớm
    if (abs(x - 6) + abs(y - 0) > LEN - idx) return;    // Manhattan

    // corridor-pruning
    auto block = [&](int a, int b) { return !in(a, b) || vis[a][b]; };
    if ((block(x-1, y) && block(x+1, y) && !block(x, y-1) && !block(x, y+1)) ||
        (block(x, y-1) && block(x, y+1) && !block(x-1, y) && !block(x+1, y)))
        return;

    char c = s[idx];
    static const char dirChar[4] = {'U', 'D', 'L', 'R'};

    for (int d = 0; d < 4; ++d) {
        if (c != '?' && c != dirChar[d]) continue;
        int nx = x + dx[d], ny = y + dy[d];
        if (!in(nx, ny) || vis[nx][ny]) continue;
        vis[nx][ny] = true;
        dfs(nx, ny, idx + 1);
        vis[nx][ny] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s;                   // độ dài luôn = 48
    vis[0][0] = true;           // đánh dấu ô xuất phát
    dfs(0, 0, 0);

    cout << ans << '\n';
    return 0;
}
