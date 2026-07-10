#include <cstdio>
#include <vector>
#include <climits>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    vector<long long> d(n);
    for(int i = 0; i < n; i++) scanf("%lld", &d[i]);
    int full = (1 << n) - 1;
    vector<long long> s(1 << n, 0);
    for(int m = 1; m <= full; m++){
        int lb = __builtin_ctz(m);
        s[m] = s[m ^ (1 << lb)] + d[lb];
    }
    vector<int> kill(n);
    for(int p = 0; p < n; p++){
        kill[p] = (1 << p) | (1 << ((p + 2) % n)) | (1 << ((p - 2 + n) % n));
    }
    const long long INF = LLONG_MAX / 4;
    vector<long long> dp(1 << n, INF);
    dp[0] = 0;
    for(int m = 1; m <= full; m++){
        long long best = INF;
        for(int p = 0; p < n; p++){
            int nm = m & ~kill[p];
            if(nm == m) continue;
            long long v = s[nm] + dp[nm];
            if(v < best) best = v;
        }
        dp[m] = best;
    }
    printf("%lld\n", dp[full] + 1);
}
