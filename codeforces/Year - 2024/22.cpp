#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin>>n;

    vector<int>arr(n);
    vector<int>frequency(n + 1, 0);
    
    for (int i = 0; i < n; i++) {
        cin>>arr[i];
        frequency[arr[i]]++;
    }

    int MEX = 0;
    bool isSingleElementTaken = false;

    for (int i = 0; i <= n; i++) {
        if (frequency[i] >= 2) {
            continue;
        }
        else if(frequency[i] == 1 && !isSingleElementTaken) {
            isSingleElementTaken = true;
        }
        else if (frequency[i] == 1) {
            MEX = i;
            break;
        }
        else {
            MEX = i;
            break;
        }
    }

    cout<<MEX<<endl;

}

int main(){

    int t;
    cin>>t;

    while(t--){
        solve();
    }

    return 0;
}
