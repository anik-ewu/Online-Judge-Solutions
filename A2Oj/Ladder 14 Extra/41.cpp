#include<bits/stdc++.h>
using namespace std;

int main(){

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int t, a, n, m, c;

    cin>>n>>t>>c;

    int cnt=0;
    int ans=0;
    for(int i=1; i<=n; i++){
        cin>>a;
        if(a>t){
            ans+=max(0, cnt-c+1);
            cnt=0;
        }
        else{
            cnt++;
        }
    }
    ///for last index
    ans+=max(0, cnt-c+1);

    cout<<ans<<endl;




    return 0;
}