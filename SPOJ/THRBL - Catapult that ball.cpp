///Date     : 26-09-2020
///Approach : Sparse Table
///Notes    : Between means ( l+1  ,r-1) / care with handle when (b-a)==1

#include<bits/stdtr1c++.h>
using namespace std;

const int K=20;
const int N=50005;

int arr[N];
int logs[N];
int T[N][K];

void precal(int n){

    for(int i=2; i<=n; i++){
        logs[i]=logs[i/2]+1;
    }
    for(int i=0; i<n; i++){
        T[i][0]=arr[i];
    }
    for(int j=1; j<=K; j++){
        for(int i=0; i+(1<<j)<=n; i++){
            T[i][j]=max(T[i][j-1],T[i+(1<<(j-1))][j-1]);
        }
    }

}


int query(int L, int R){
    int j = logs[R - L + 1];
    int mx = max(T[L][j], T[R - (1 << j) + 1][j]);
    return mx;
}

int main(){

    int n , q , l , r, ans;

    scanf("%d",&n);
    scanf("%d",&q);
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }
    precal(n);

    ans=q;
    while(q--){
        scanf("%d%d",&l,&r);
        l--;r--;///making 0 based
        if(r-l==1)continue;
        int mx=query(l+1, r-1);
        if(mx>arr[l])ans--;
    }
    printf("%d\n",ans);

    return 0;
}

