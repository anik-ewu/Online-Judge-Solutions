// #include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define Fast    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main() {

    Fast;

    int t, n, k, val;
    string s;

    cin>>t;
    while (t--) {
        cin>>n>>s;

        int firstOperationNeeded = 0;
        int countEmptyCell = 0;
        int countConsecutiveEmptyCell = 0;
        bool threeConsecutiveEmptyCell = false;

        for (int i = 0; i < n; i++) {
            if (s[i] == '.') {
                countEmptyCell++;
                countConsecutiveEmptyCell++;
            }
            else {
                countConsecutiveEmptyCell = 0;
            }
            if (countConsecutiveEmptyCell == 3) {
                threeConsecutiveEmptyCell = true;
            }
        }

        if (!threeConsecutiveEmptyCell) {
            cout << countEmptyCell <<endl;
        }
        else {
            cout << 2 <<endl;
        }
    }

    return 0;
}