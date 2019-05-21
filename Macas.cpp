#include <bits/stdc++.h>

using namespace std;

int n, m, T;
int macas[25][25][1005];
int dp[25][25][1005];

bool position(int x, int y) {
    return 1 <= x and x <= n and 1 <= y and y <= m;
}

int solv(int x, int y, int t) {
    if(t > T) {
        return 0;
    } else if(~dp[x][y][t]) {
        return dp[x][y][t];
    }
    int tot = 0; 
    for(int dx = -1; dx <= 1; ++dx) {
        for(int dy = -1; dy <= 1; ++dy) {
            if(position(x + dx, y + dy)) {
                tot = max(tot, solv(x + dx, y + dy, t + 1));
            }
        }
    }
    
    return dp[x][y][t] = tot + macas[x][y][t];
}

int main() {
    int k;
    while(cin >> n >> m >>k && (n | m | k)) {
        memset(macas, 0, sizeof macas);
        for(int i = 1; i <= k; ++i) {
            int x, y, t;
            cin >> x >> y >>t;
            macas[x][y][t] = 1;
            T = max(T, t + 1);
        }
        int x0, y0;
        cin >> x0 >> y0;
        memset(dp, -1, sizeof dp);
        cout << solv(x0, y0, 0) << endl;
    }
    return 0;
}
