#include <cstdio>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, k;
        scanf("%d %d", &n, &k);
        int mx = 0;
        for (int i = 0; i < k; i++) {
            int a;
            scanf("%d", &a);
            if (a > mx) mx = a;
        }
        long long ans = 2LL * (n - mx) - (k - 1);
        printf("%lld\n", ans);
    }
}
