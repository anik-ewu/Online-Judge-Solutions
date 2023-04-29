#include<bits/stdc++.h>
using namespace std;

int main() {

    int t, n;
    string s;

    cin>>t;
    while(t--) {
        cin>>n>>s;

        int zeros = 0;
        for(int i = 0; i < n; i++)
            zeros += (s[i] == '0');

        if(n%2 == 0) {
            cout<<"BOB"<<endl;
        }
        else if(s[n/2]=='0' and zeros > 1) {
            cout<<"ALICE"<<endl;
        } else {
            cout<<"BOB"<<endl;
        }
    }


    return 0;
}
