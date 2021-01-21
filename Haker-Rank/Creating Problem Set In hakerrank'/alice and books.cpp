#include<bits/stdc++.h>
using namespace std;

int main(){

    while(1){
        long long int ans, n, k;
        cin>>n>>k;
        ans=k-((n*1LL*(n+1))/2);
        if(ans<0)ans=0;
        cout<<ans<<endl;
    }

    return 0;
}
