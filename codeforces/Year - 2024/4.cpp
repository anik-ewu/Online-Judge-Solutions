#include<bits/stdc++.h>
using namespace std;

int mark[26];

int main() {

    int t, a, b, n;
    string s;
    cin>>t;
    for (int i = 0; i < t; i++) {
        cin>>n;
        cin>>s;
        int count = 0;
        memset(mark, 0, sizeof(mark));
        long long int res = (n * 1LL * (n  + 1)) / 2;

        for (int j = 0; j < n; j++) {
            if (mark[s[j] - 'a'] != 0) {
                count++;
            }
            res -= count;
            mark[s[j] - 'a'] = 1;
        }
        cout<<res<<endl;
    }

    return 0;
}