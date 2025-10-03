// #include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define Fast    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main() {

    Fast;

    int t, n, k, val;
    cin>>t;
    while (t--) {
        cin>>n>>k;
        int prev = 0;
        bool sorted = true;
        for (int i = 1; i <= n; i++) {
            cin >> val;
            if (val < prev) {
                sorted = false;
            }
            prev = val;
        }

        if (n == 1 || k > 1 || sorted) {
            cout<<"YES"<<endl;
        }
        else {
            cout<<"NO"<<endl;
        }
    }


    return 0;
}