///Date     : 26-09-2020
///Approach : Sparse Table
///Notes    : Between means ( l+1  ,r-1) / care with handle when (b-a)==1

#include<bits/stdtr1c++.h>
using namespace std;
#define ll long long
#define lld double

const int K=20;
const int N=100005;

ll arr[N];
int logs[N];
ll Tmin[N][K];
ll Tmax[N][K];

void precal(int n){

    for(int i=2; i<=n; i++){
        logs[i]=logs[i/2]+1;
    }
    for(int i=0; i<n; i++){
        Tmin[i][0]=arr[i];
        Tmax[i][0]=arr[i];
    }
    for(int j=1; j<=K; j++){
        for(int i=0; i+(1<<j)<=n; i++){
            Tmax[i][j]=max(Tmax[i][j-1],Tmax[i+(1<<(j-1))][j-1]);
            Tmin[i][j]=min(Tmin[i][j-1],Tmin[i+(1<<(j-1))][j-1]);
        }
    }
}


double query_min(int L, int R){
    int j = logs[R - L + 1];
    ll mx = min(Tmin[L][j], Tmin[R - (1 << j) + 1][j]);
    return mx;
}

double query_max(int L, int R){
    int j = logs[R - L + 1];
    lld mx = max(Tmax[L][j], Tmax[R - (1 << j) + 1][j]);
    return mx;
}

int main(){

    int n , q , l , r, ans;

    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }
    precal(n);

    scanf("%d",&q);
    while(q--){
        scanf("%d%d",&l,&r);
        double left=0 , middle=0, right=0;

        middle=query_min(l,r);
        if(l-1>=0){
            left=query_max(0,l-1)+middle;
        }
        if(r+1<n){
            right=query_max(r+1,n-1)+middle;
        }
        lld extra=query_max(l,r);
        if(extra>middle){
            extra=(extra-middle)/2.0;
            middle+=extra;
        }

        printf("%.1f\n", max(left, max(middle, right)));
    }

    return 0;
}

