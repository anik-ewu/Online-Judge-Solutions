#include<bits/stdc++.h>
using namespace std;
#define Fast        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){

    int t;
    cin>>t;
    while (t--) {
        int n, val;
        int countOddNumber = 0;
        cin>>n;
        for (int i = 0; i < n; i++) {
            cin>>val;
            countOddNumber += (val % 2 == 1);
        }

        if (countOddNumber % 2 == 1) {
            cout<<"NO"<<endl;
        }
        else {
            cout<<"YES"<<endl;
        }
    }


    return 0;
}

