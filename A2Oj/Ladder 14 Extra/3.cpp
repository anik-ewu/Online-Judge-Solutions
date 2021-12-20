#include<bits/stdc++.h>
using namespace std;


int main(){

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int n, a, d;
    vector< int > v;
    cin>>n>>d;
    for(int i=1; i<=n; i++){
        cin>>a;
        v.push_back(a);
    }

    sort(v.begin(),v.end())

    int res=0;

    for(int i=0; i<n-1; i++){
        int idx=upper_bound(v.begin()+i+1,v.end(),v[i]+d)-v.begin()-1;
        int cnt=idx-i;
        res+=cnt*2;
    }
    cout<<res<<endl;








    return 0;
}
