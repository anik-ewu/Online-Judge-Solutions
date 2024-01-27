#include<bits/stdc++.h>
using namespace std;

int main() {

    int n, t, a, b;
    cin>>t;
    for (int i = 0; i < t; i++) {
        cin>>n;
        int minimum = INT_MIN;
        int maximum = INT_MAX;
        vector<int>arr;
        for (int j = 0; j < n; j++) {
            cin>>a>>b;

            if (a == 1) {
                minimum = max(minimum, b);
            }  
            else if (a == 2) {
                maximum = min(maximum, b);
            }
            else {
                arr.push_back(b);
            }
        }

        int res = maximum - minimum + 1;

        for (int number: arr) {
            if (number >= minimum && number <= maximum) {
                res--;
            }
        }
        res = max(res, 0);
        cout<<res<<endl;

    }

    return 0;
}