#include <cstdio>
#include <vector>
using namespace std;

const int MAXV=1000001;
int cb[MAXV];
int cw[MAXV];

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m; long long k;
        scanf("%d %d %lld",&n,&m,&k);
        vector<int> a(n),b(m);
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        for(int i=0;i<m;i++){ scanf("%d",&b[i]); cb[b[i]]++; }
        int matched=0;
        long long ans=0;
        for(int i=0;i<m;i++){
            int x=a[i];
            if(cw[x]<cb[x]) matched++;
            cw[x]++;
        }
        if(matched>=k) ans++;
        for(int i=m;i<n;i++){
            int x=a[i];
            if(cw[x]<cb[x]) matched++;
            cw[x]++;
            int y=a[i-m];
            cw[y]--;
            if(cw[y]<cb[y]) matched--;
            if(matched>=k) ans++;
        }
        printf("%lld\n",ans);
        for(int i=0;i<m;i++) cb[b[i]]=0;
        for(int i=0;i<n;i++) cw[a[i]]=0;
    }
}
