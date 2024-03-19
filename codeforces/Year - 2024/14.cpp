#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {

    ll firstInstall;
    ll secondInstall;
    ll m;

    cin>>firstInstall;
    cin>>secondInstall;
    cin>>m;

    cout<<(m / firstInstall) + (m / secondInstall) + 2<<endl;

}

int main(){

    int t;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
