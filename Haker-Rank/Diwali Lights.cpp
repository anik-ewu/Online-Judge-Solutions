#include<bits/stdc++.h>
using namespace std;

#define mod 100000


int bpm(int b, int p){
    if(p==0)return 1;
    int res=bpm(b, p/2)%mod;
    res=(res*1LL*res)%mod;
    if(p%2)res=(res*1LL*b)%mod;
    return res;
}


int main(){

    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        int res=bpm(2, n)-1;
        if(res<0)res+=mod;
        cout<<res<<endl;
    }


    return 0;
}
