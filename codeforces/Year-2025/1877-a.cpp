#include<iostream>
using namespace std;
#define Fast    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main() {

    Fast;

    int t, n, k, val;
    cin>>t;
    while (t--) {
        cin>>n;
        int sum = 0;
        for (int i = 1; i < n; i++) {
            cin >> val;
            sum += (val * -1);
        }
        cout<<sum<<endl;
    }


    return 0;
}