#include<iostream>
using namespace std;
#define Fast    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main() {

    Fast;

    int t, n, k, val;
    cin>>t;
    while (t--) {
        cin>>n>>k;
        bool exist = false;
        for (int i = 1; i <= n; i++) {
            cin >> val;
            if (val == k) {
                exist = true;
            }
        }
        if (exist) {
            cout<<"YES"<<endl;
        }
        else {
            cout<<"NO"<<endl;
        }
    }


    return 0;
}