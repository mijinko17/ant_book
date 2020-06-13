#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <vector>
typedef long long lint;
using namespace std;

int n, m;
vector<string> garden;

void dfs(int x, int y) {
    if (garden[x][y] != 'W') {
        return;
    }
    garden[x][y] = 'E';
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            int x_next = x + dx;
            int y_next = y + dy;
            bool row_valid = x_next >= 0 && x_next < n;
            bool column_valid = y_next >= 0 && y_next < m;
            if (row_valid && column_valid && garden[x_next][y_next] == 'W') {
                dfs(x_next, y_next);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    garden.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> garden[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (garden[i][j] == 'W') {
                ans++;
                dfs(i, j);
            }
        }
    }
    cout << ans << endl;
}
