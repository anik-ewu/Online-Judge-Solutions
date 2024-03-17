#include<bits/stdc++.h>
using namespace std;

int main(){

    int t=1, n , k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        cout<<(k >= (n - 1) ? 1 : n)<<endl;
    }
    return 0;
}
