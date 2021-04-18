#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e9;

#define all(x)          (x).begin(), (x).end()
#define read(x)         freopen("in.txt","r",stdin);
#define write(x)        freopen("out.txt","w",stdout);
#define what_is(x)      cerr<<#x<<" is "<<x<<"\n";
#define Fast            ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define mod             1e9+7
#define sz              3000005

int n, m;
char arr[52][52];
int  vis[52][52];
int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

bool check(char ch, int x, int y){
    return (x>=1 and x<=n and y>=1 and y<=m and ch==arr[x][y]);
}

void dfs(int i, int j, int u, int v){
    vis[i][j]=1;
    for(int k=0; k<4; k++){
        int x=i+dx[k];
        int y=j+dy[k];
        if(check(arr[i][j], x, y)){
            if(vis[x][y]==0){
                dfs(x, y, i, j);
            }
        }
    }
}

void solve(){

    int a,b,  i,j;
    cin>>n>>m;
    int x=0;
    int y=0;
    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            cin>>arr[i][j];
            if(arr[i][j]=='B'){
                x=i;
                y=j;
            }
        }
    }
    if(x==0 and y==0){
        cout<<"YES"<<endl;
        return ;
    }

    ///check connected or not
    dfs(x, y, -1, -1);
    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            if(arr[i][j]=='B' and !vis[i][j]){
                cout<<"NO"<<endl;
                return ;
            }
        }
    }
    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            if(arr[i][j]=='W'){
                //col
                int l=0, r=0;
                for(int k=j; k<=m; k++)if(arr[i][k]=='B')r=1;
                for(int k=j; k>=1; k--)if(arr[i][k]=='B')l=1;

                int u=0, d=0;
                for(int k=i; k<=n; k++)if(arr[k][j]=='B')d=1;
                for(int k=i; k>=1; k--)if(arr[k][j]=='B')u=1;

                if((l+r)==2 || (u+d)==2){
                    cout<<"NO"<<endl;
                    return ;
                }    
     
            }
        }
    }
    cout<<"YES"<<endl;

}

int main(){
    Fast;///using Fast I/O
    
    read(x); write(x);

    solve();

    return 0;
}

