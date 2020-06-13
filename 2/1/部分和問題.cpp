#include <algorithm>
#include <bitset>
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

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int k;
    cin >> k;
    bool able = false;
    for (int i = 0; i < (1 << n); i++) {
        bitset<20> b(i);
        int sum = 0;
        for (int j = 0; j < n; j++) {
            if (b[j]) {
                sum += a[j];
            }
        }
        if (sum == k) {
            able = true;
        }
    }
    string ans = able ? "YES" : "NO";
    cout << ans << endl;
}
