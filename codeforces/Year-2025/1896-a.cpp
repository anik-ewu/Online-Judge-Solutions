#include<iostream>
using namespace std;
#define Fast    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main() {

    Fast;

    int t, n, firstVal, val;

    cin>>t;
    while (t--) {
        cin>>n;
        cin>>firstVal;
        for (int i = 2; i <= n; i++) {
            cin>>val;
        }

        if (firstVal == 1) {
            cout << "YES" <<endl;
        }
        else {
            cout << "NO" <<endl;
        }
    }

    return 0;
}