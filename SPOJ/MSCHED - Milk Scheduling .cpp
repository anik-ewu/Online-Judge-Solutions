///8-12-2020
///Greedy + DSU

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e9;

#define mod             1000000007
#define what_is(x)      cerr<<#x<<" is "<<x<<"\n";
#define read(x)         freopen("in.txt","r",stdin);
#define write(x)        freopen("out.txt","w",stdout);
#define Fast            ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define sz              10001

int par[sz],Rank[sz];

struct st{
    int gi, di;
}arr[sz];

bool cmp(st a , st b){
    if(a.gi==b.gi)return (a.di>=b.gi);
    return a.gi>b.gi;
}

void Make_Set(int n){
    for(int i=1; i<=n; i++){
        par[i]=i;
        Rank[i]=0;
    }
}
int find(int a){
    if(par[a]==a)return a;
    return par[a]=find(par[a]);
}
void Union(int a, int b){
    int x=find(a);
    int y=find(b);
    par[x]=y;
}

int main(){
    Fast;///using Fast I/O
    int a,b,c, i,j,k, t,n,m;

    cin>>n;

    for(i=1; i<=n; i++){
        cin>>arr[i].gi>>arr[i].di;
    }

    sort(arr+1, arr+n+1, cmp);

    int tot=0;
    Make_Set(10000);
    for(i=1; i<=n; i++){
       a=find(arr[i].di);
       if(a==0)continue;
       tot+=arr[i].gi;
       Union(a, a-1);
    }
    cout<<tot<<endl;



    return 0;
}


