#include<bits/stdc++.h>
using namespace std;


int main(){

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int n, a, b;
    vector< pair< int , int > > vp;
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a>>b;
        vp.push_back({a,b});
    }

    bool flag=false;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            int x=vp[i].first+vp[i].second;
            int y=vp[j].first+vp[j].second;
            if(x==vp[j].first && y==vp[i].first){
                flag=true;
                break;
            }
        }
    }
    if(flag){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }




    return 0;
}
