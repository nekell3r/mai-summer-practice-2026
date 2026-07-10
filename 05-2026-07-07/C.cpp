#include <cstdio>
#include <algorithm>
using namespace std;
int c[105][105];
int dp[105];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++)
            for(int j=1;j<=m;j++)
                scanf("%d",&c[i][j]);
        for(int w=0;w<=m;w++) dp[w]=0;
        for(int i=0;i<n;i++)
            for(int w=m;w>=0;w--){
                int best=dp[w];
                for(int j=1;j<=w;j++)
                    best=max(best,dp[w-j]+c[i][j]);
                dp[w]=best;
            }
        printf("%d\n",dp[m]);
    }
}
