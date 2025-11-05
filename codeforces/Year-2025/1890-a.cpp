// #include<bits/stdc++.h>
#include<iostream>
#include<map>
using namespace std;
#define Fast    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main() {

    Fast;

    int t, n, k, val;
    cin>>t;
    while (t--) {
        cin>>n;
        map<int, int> mp;
        for (int i = 1; i <= n; i++) {
            cin >> val;
            mp[val]++;
        }

        if (mp.size() == 1) {
            cout<<"Yes"<<endl;
        }
        else if (mp.size() == 2) {
            auto it = mp.begin();
            int firstValFreq = it->second;
            ++it;
            int secondValFreq = it->second;
            
            if (abs(firstValFreq - secondValFreq) <= 1) {
                cout<<"Yes"<<endl;
            }
            else {
                cout<<"No"<<endl;
            }

        }
        else {
            cout<<"No"<<endl;
        }
    }


    return 0;
}