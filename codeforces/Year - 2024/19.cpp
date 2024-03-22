#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const ll mod = 1e9 + 7;

void solve() {
    int n, k;
    cin>>n>>k;

    vector<int>arr(n);
    for (int i = 0; i < n; i++) {
        cin>>arr[i];
    }

    ll sum = 0;
    ll mx_sum = 0;
    ll curr_sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        curr_sum += arr[i];
        curr_sum = max(curr_sum, 0LL);
        mx_sum = max(curr_sum, mx_sum);
    }

    sum = (sum % mod + mod) % mod;
    mx_sum = mx_sum % mod;
    for (int i = 0; i < k; i++) {
        sum += mx_sum;
        sum %= mod;
        mx_sum = (2 * mx_sum);
        mx_sum %= mod;
    }

    cout<<sum<<endl;
}

int main(){

    int t;
    cin>>t;

    while(t--){
        solve();
    }

    return 0;
}
