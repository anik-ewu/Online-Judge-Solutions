///Date: 26-09-2020
///Approach: Sparse Table

#include<bits/stdtr1c++.h>
using namespace std;

const int K=20;
const int N=100005;

int arr[N];
int logs[N];
int T[N][25];

void precal(int n){

    for(int i=2; i<=n; i++){
        logs[i]=logs[i/2]+1;
    }
    for(int i=0; i<n; i++){
        T[i][0]=arr[i];
    }
    for(int j=1; j<=K; j++){
        for(int i=0; i+(1<<j)<=n; i++){
            T[i][j]=min(T[i][j-1],T[i+(1<<(j-1))][j-1]);
        }
    }

}


int query(int L, int R){
    int j = logs[R - L + 1];
    int minimum = min(T[L][j], T[R - (1 << j) + 1][j]);
    return minimum;
}

int main(){

    int n , q , l , r;

    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }
    precal(n);

    scanf("%d",&q);
    while(q--){
        scanf("%d%d",&l,&r);
        printf("%d\n",query(l, r));
    }

    return 0;
}

