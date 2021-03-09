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
#define sz              100005

int arr[sz];

void solve(){

    int a,b, n,m,k, i,j;
    vector< int > v;
    cin>>n>>k;
    for(i=1; i<=n; i++){
        cin>>a;
        v.emplace_back(a);
    }

    int cnt=0;
    int l=-1, r=-1;
    for(i=0; i<n; i++){
        if(arr[v[i]]==0){
            cnt++;
        }
        arr[v[i]]++;
        if(cnt==k){
            r=i+1;
            break;
        }
    }

    if(cnt==k){
        l=0;
        while(arr[v[l]]>1){
            arr[v[l]]--;
            l++;
        }
        l++;
    }

    cout<<l<<' '<<r<<endl;
}

int main(){
    Fast;///using Fast I/O
    
    read(x); write(x);

    solve();

    return 0;
}

