// Note: Conver n/2 - i into n - (2 * i) to resolve calculation for non integer number

#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin>>n>>s;

    s.insert(s.begin(), '#');

    int totalZeros = 0;
    int totalOnes = 0;
    for (char ch: s) {
        if (ch == '0') {
            totalZeros++;
        }
        else if (ch == '1'){
            totalOnes++;
        }
    }

    int zerosInLeft = 0;
    int zerosInRight = totalZeros;
    int onesInLeft = 0;
    int onesInRight = totalOnes;
    
    int resultIndex = -1;
    
    int minDiff = n + 5;
    for (int i = 0; i <= n; i++) {
        if (s[i] == '0') {
            zerosInLeft++;
            zerosInRight--;
        }
        else if (s[i] == '1'){
            onesInLeft++;
            onesInRight--;
        }

        if (zerosInLeft >= onesInLeft && zerosInRight <= onesInRight) {
            if (resultIndex == -1) {
                resultIndex = i;
                minDiff = abs(n - (2 * i));
            }
            else if (abs(n - (2 * i)) < minDiff) {
                resultIndex = i;
                minDiff = abs(n - (2 * i));
            }
        }
    }

    cout<<resultIndex<<endl;
}

int main(){

    int t;
    cin>>t;

    while(t--){
        solve();
    }

    return 0;
}
