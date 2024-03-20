#include<bits/stdc++.h>
using namespace std;

void solve() {
    
    int n;
    cin>>n;

    string s;
    cin>>s;
    
    string reversedStr = s;
    reverse(reversedStr.begin(), reversedStr.end());

    cout<<min(s, reversedStr + s)<<endl;

}

int main(){

    int t;
    cin>>t;

    while(t--){
        solve();
    }

    return 0;
}
