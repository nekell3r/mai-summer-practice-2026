#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int a[105][105];
    int dp[105][105];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int best = 0;
            if (i > 0) best = max(best, dp[i - 1][j]);
            if (j > 0) best = max(best, dp[i][j - 1]);
            if (i > 0 && j > 0) best = max(best, dp[i - 1][j - 1]);
            dp[i][j] = a[i][j] + best;
        }
    }
    cout << dp[n - 1][m - 1] << '\n';
}
