#include <bits/stdc++.h>
using namespace std;
typedef long long lli;

vector<pair<int, int>> knight_related(int i, int j, int m, int n) {
    const int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
    const int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};
    bool vis[m][n];
    memset(vis, true, sizeof(vis));
    vector<pair<int, int>> res;
    queue<pair<int, int>> q;
    q.push({i, j});
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int k = 0; k < 8; ++k) {
            int newx = x + dx[k];
            int newy = y + dy[k];
            if (1 <= newx && newx <= m && 1 <= newy && newy <= n && vis[newx][newy]) {
                q.push({newx, newy});
                res.push_back({newx, newy});
            }
        }
    }
    return res;
}

int main() {

}