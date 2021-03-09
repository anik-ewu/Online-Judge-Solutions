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

void dfs(int i, int j, int T, int u, int v){

    vis[i][j]=T;
    for(int k=0; k<4; k++){
        int x=i+dx[k];
        int y=j+dy[k];

        if(check(arr[i][j], x, y)){
            if(vis[x][y]==0){
                dfs(x, y, T, i, j);
            }
            else if(vis[x][y]==T and (x!=u || y!=v)){
                cout<<"Yes"<<endl;
                exit(0);
            }
        }
    }
}


void solve(){

    int a,b, i,j;
    cin>>n>>m;
    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            cin>>arr[i][j];
        }
    }

    int T=1;
    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            if(vis[i][j]==0){
                dfs(i, j, T, -1, -1);
                T++;
            }
        }
    }
    cout<<"No"<<endl;
}

int main(){
    Fast;///using Fast I/O
    
    read(x); write(x);

    solve();

    return 0;
}

