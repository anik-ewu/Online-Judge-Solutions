#include<bits/stdc++.h>
using namespace std;


void solve(vector<int>&freq1, vector<int>&freq2, int n, int k) {

    priority_queue<pair<int,int>>prefix;
    priority_queue<pair<int,int>>suffix;

    for (int i = 1; i <= n; i++) {
        if (freq1[i] == 1) {
            prefix.push({freq1[i], i});
        }
        else if (freq1[i] == 2) {
            prefix.push({freq1[i], i});
            prefix.push({freq1[i], i});
        }
        
        if (freq2[i] == 1) {
            suffix.push({freq2[i], i});
        }
        else if (freq2[i] == 2) {
            suffix.push({freq2[i], i});
            suffix.push({freq2[i], i});
        }
    }

    vector<int>arr;    
    vector<int>brr;

    while (k--) {
        arr.push_back(prefix.top().second);
        prefix.pop();
        arr.push_back(prefix.top().second);
        prefix.pop();

        brr.push_back(suffix.top().second);
        suffix.pop();
        brr.push_back(suffix.top().second);
        suffix.pop();
    }

    for (int val: arr) {
        cout<<val<<" ";
    }
    for (int val: brr) {
        cout<<val<<" ";
    }    
    
    cout<<endl;
}

int main(){

    int a, t=1, n , k;
    cin>>t;
    while(t--){

        cin>>n>>k;
        vector<int>freq1(n + 1, 0);
        vector<int>freq2(n + 1, 0);

        for (int i = 0; i < n; i++) {
            cin>>a;
            freq1[a]++;
        }
        for (int i = 0; i < n; i++) {
            cin>>a;
            freq2[a]++;
        }

        solve(freq1, freq2, n, k);

    }

    return 0;
}
