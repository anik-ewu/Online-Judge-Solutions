#include<bits/stdc++.h>
using namespace std;

int arr[2005];
int res[2005];

int main(){

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int n, k, m, a;
    cin>>n;
    vector< int > v(n,0);
    set<int > st;
    for(int i=0; i<n; i++){
        cin>>v[i];
        arr[v[i]]++;
        st.insert(v[i]*-1);
    }

    int sum=0;    
    for(auto i: st){
        res[i*-1]=sum+1;
        sum+=arr[i*-1];
    }

    for(int i=0; i<n; i++){
        cout<<res[v[i]]<<' ';
    }
    return 0;
}