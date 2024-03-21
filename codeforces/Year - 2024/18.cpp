#include<bits/stdc++.h>
using namespace std;

int memo[6][16];
vector<int>coins {1, 3, 6, 10, 15};

int dp(int i, int sum, int target) {
    if (sum > target) {
        return 116;
    }
    if (i >= coins.size()) {
        return 116;
    }
    if (sum == target) {
        return 0;
    }

    if (memo[i][sum] != -1) {
        return memo[i][sum];
    }

    int a = dp(i + 1, sum, target);
    int b = dp(i, sum + coins[i], target) + 1;

    return memo[i][sum] = min(a, b);

}

void solve() {
    
    int n;
    cin>>n;

    int minimumCoin = 0;

    if (n > 15) {
        minimumCoin =  (n - 15) / 15;
        n -= ( minimumCoin * 15);
    }

    memset(memo, -1, sizeof(memo));
    minimumCoin += dp(0, 0, n);
    cout<<minimumCoin<<endl;
}

int main(){

    int t;
    cin>>t;

    while(t--){
        solve();
    }

    return 0;
}
