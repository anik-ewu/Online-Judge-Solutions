#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int arr[200005];
ll prefixSum[200005];

int main() {

    ll n , k;
    cin>>n>>k;
    for(int i = 1; i<=n; i++) {
        cin>>arr[i];
        prefixSum[i] = prefixSum[i-1]+arr[i];
    }

    ll total = 0;

    map<ll, ll> mp;
    mp.clear();
    mp[0]++;

    for(int i=1; i<=n; i++) {
        total += mp[prefixSum[i]-k];
        mp[prefixSum[i]]++;
    }

    cout<<total<<endl;

    return 0;
}
