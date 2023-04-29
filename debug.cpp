#include <bits/stdc++.h>
using namespace std;

pair<int, int> coin[40];
int dp[40][10010];

int coinChange(int i, int k){

	if(k==0) return 0;
	if(i<0||k<0) return 100000000;
	if(dp[i][k]!=-1) return dp[i][k];


	int r1=coinChange(i, k-coin[i].first)+1;
	int r2=coinChange(i-1, k);
	dp[i][k] =min(r1, r2);
	return dp[i][k];
}

void traceBack(int i, int k, int res){
	if(i<0|| res==0) return;

	if(dp[i][k-coin[i].first]==res-1){
		coin[i].second++;
		traceBack(i, k-coin[i].first, res-1);
	}
	else {
		traceBack(i-1, k, res);
	}
}

int main(){
	memset(dp, -1, sizeof(dp));
	int n, k; cin>>n>>k;
	for(int i=0; i<n; i++){
		cin>>coin[i].first;
		coin[i].second=0;
	}
    int res = coinChange(n-1, k);
	cout<<res<<endl;
	traceBack(n-1, k, res);
	for(int i=0; i<n; i++){
		if(coin[i].second>0){
			cout<<coin[i].first<<" "<<coin[i].second<<endl;
		}
	}
	return 0;
}
