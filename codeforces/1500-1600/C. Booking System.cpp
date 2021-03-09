///Straight forward greedy problem
///pretty much similar to the task scheduling problem


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e9;

#define what_is(x)      cerr<<#x<<" is "<<x<<"\n";
#define read(x)         freopen("in.txt","r",stdin);
#define write(x)        freopen("out.txt","w",stdout);
#define Fast            ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define mod             1e9+7
#define sz              3000005



void solve(){

    int a,b,c, n,m,k, i,j;
    vector< pair< int , int > > vp;
    priority_queue< pair< int , pair< int, int >  > > pq;

    cin>>n;
    for(i=1; i<=n ;i ++){
        cin>>a>>b;
        pq.push({b,{a,i}});
    }

    cin>>k;
    for(i=0; i<k; i++){
        cin>>a;
        vp.push_back({a, i+1});
    }
    sort(vp.begin(), vp.end());

    int sum=0;
    int mark[1001];
    memset(mark, 0, sizeof(mark));
    vector< pair< int , int > > ans;
    while(!pq.empty()){
        b=pq.top().first;
        a=pq.top().second.first;
        c=pq.top().second.second;
        pq.pop();

        for(i=0; i<k; i++){

            if(mark[vp[i].second]==0 && a<=vp[i].first){
                mark[vp[i].second]=1;
                sum+=b;
                ans.push_back({c, vp[i].second});
                break;
            }
        }

    }

    cout<<ans.size()<<' '<<sum<<endl;
    for(i=0; i<ans.size(); i++){
        cout<<ans[i].first<<' '<<ans[i].second<<endl;
    }
}

int main(){
    Fast;///using Fast I/O
    
    read(x); write(x);

    solve();

    return 0;
}

