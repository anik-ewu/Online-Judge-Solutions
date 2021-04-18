///Implementation
///9-3-2021

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e9;

#define all(x)          (x).begin(), (x).enkd()
#define read(x)         freopen("in.txt","r",stdin);
#define write(x)        freopen("out.txt","w",stdout);
#define what_is(x)      cerr<<#x<<" is "<<x<<"\n";
#define Fast            ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define mod             1e9+7
#define sz              3000005

void solve(){

    int a,b, n,m, i,j;
    vector< int > arr;
    cin>>n;
    for(i=0; i<n; i++){
        cin>>a;
        arr.emplace_back(a);
    }

    int l=0, r=0;
    for(i=1; i<n; i++){
        if(arr[i]<arr[i-1]){
            l=i-1;
            break;
        }
    }

    for(i=n-1; i>0; i--){
        if(arr[i]<arr[i-1]){
            r=i;
            break;
        }
    }
    while(r+1<n and arr[r+1]==arr[r])r++;
    while(l-1>=0 and arr[l-1]==arr[l])l--;
    swap(arr[l], arr[r]);



    for(i=1; i<n; i++){
        if(arr[i]<arr[i-1]){
            cout<<"NO"<<endl;
            return ;
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

