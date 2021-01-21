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

int Rank[sz];

int main(){
    Fast;///using Fast I/O
    int a,b,c, i,j,k, t,n,m;

    cin>>n;
    priority_queue< pair< int , int > > pq;
    for(i=1; i<=n; i++){
        cin>>a>>b;
        pq.push({a, b});
    }

    int tot=0;
    memset(Rank, 0, sizeof(Rank));
   while(!pq.empty()){
       a=pq.top().first;
       for(j=pq.top().second; j>0; j--){
        if(Rank[j]==0){
            tot+=a;
            Rank[j]=1;
            break;
        }
       }
       pq.pop();
    }
    cout<<tot<<endl;


    return 0;
}
