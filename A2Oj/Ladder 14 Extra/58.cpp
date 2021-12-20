///Tags: Implementation


#include<bits/stdc++.h>
using namespace std;

int n, m;
int mat[1005][1005];
int dx[] = {0, 0, 1, 1};
int dy[] = {0, 1, 0, 1};

bool valid(int x, int y){
    return (x>=1 and x<=n and y>=1 and y<=m);
}

bool check(int x, int y){
    if(x>1)x--;
    if(y>1)y--;

    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            int cnt=0;
            for(int k=0; k<4; k++){
                int u=x+i+dx[k];
                int v=y+j+dy[k];
                if(valid(u, v) and mat[u][v])
                    cnt++; 
            }
            if(cnt==4)
                return true;
        }
    }
    return false;
}

int main(){

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int t, a, b , k;

    cin>>n>>m>>k;
    int res= 0;
    for(int i=1; i<=k; i++){
        cin>>a>>b;
        mat[a][b]=1;

        if(res == 0 and check(a, b)){
            res=i;
        }
    }

    cout<<res<<endl;




    return 0;
}