#include<bits/stdc++.h>
using namespace std;

void solve() {
    
    int n;
    cin>>n;

    vector<int>arr(n);
    for (int i = 0; i < n; i++) {
        cin>>arr[i];
    }

    sort(arr.begin(), arr.end());

    int i = n - 1;
    int j = 0;
    int k = n - 2;
    int l = 1;

    int maxSum = abs(arr[i] - arr[j]) + abs(arr[j] - arr[k]) + abs(arr[k] - arr[l]) + abs(arr[l] - arr[i]);;

    cout<<maxSum<<endl;
}

int main(){

    int t;
    cin>>t;

    while(t--){
        solve();
    }

    return 0;
}
