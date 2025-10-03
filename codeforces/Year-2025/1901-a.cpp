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
        int maxDifference = 0;
        for (int i = 1; i <= n; i++) {
            cin >> val;
            if (i > 1) {
                maxDifference = max(maxDifference, val - prev);
            }
            else {
                maxDifference = val;
            }
            prev = val;
        }

        int lastTrip = (k - prev) * 2;
        maxDifference = max(maxDifference, lastTrip);

        cout << maxDifference <<endl;
    }

    return 0;
}