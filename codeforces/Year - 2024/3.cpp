#include<bits/stdc++.h>
using namespace std;

int getMaxmumSum(vector<int>&arr, int k, int x) {

    sort(arr.begin(), arr.end());

    int sum = 0;
    int n = arr.size();
    vector<int>prefixSum(n, 0);
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        prefixSum[i] = sum;
    }

    sum = 0;
    vector<int>suffixSum;
    for (int i = n - 1; i >= 0; i--) {
        sum += arr[i];
        suffixSum.push_back(sum);
    }

    int maxSum = 0;

    for (int i = 0; i <= k; i++) {
        int idxInPrefix = n - x - 1 - i;
        int idxInSuffix = min(x - 1 + i, n - 1);
        int currentPrefixSum = 0;
        int currentSuffixSum = 0;
        if (idxInPrefix >= 0) {
            currentPrefixSum = prefixSum[idxInPrefix];
        }
        currentSuffixSum = suffixSum[idxInSuffix];
        if (i) {
            currentSuffixSum -= suffixSum[i - 1];
        }

        int tempSum = currentPrefixSum - currentSuffixSum;
        if (i == 0) {
            maxSum = tempSum;
        }
        else {
            maxSum = max(maxSum, tempSum);
        }
    }

    cout<<maxSum<<endl;

}

int main() {

    int n, t, a, k, x;
    cin>>t;
    for (int i = 0; i < t; i++) {
        cin>>n>>k>>x;
        vector<int>arr;
        for (int j = 0; j < n; j++) {
            cin>>a;
            arr.push_back(a);
        }
        if (n == 1) {
            cout<<0<<endl;
            continue;
        }
        int res = getMaxmumSum(arr, k, x);
    }

    return 0;
}