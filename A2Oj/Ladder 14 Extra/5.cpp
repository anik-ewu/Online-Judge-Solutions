#include<bits/stdc++.h>
using namespace std;


int main(){

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int n, k, m, a;
    cin>>n;
    vector< int > v(n,0);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    int res=INT_MAX;
    for(int i=0; i<n; i++){
        int sum=0;
        for(int j=0; j<v[i]; j++){
            cin>>a;
            sum+=a;
        }
        int need=sum*5+v[i]*15;
        res=min(res, need);
    }
    cout<<res<<endl;


    return 0;
}
