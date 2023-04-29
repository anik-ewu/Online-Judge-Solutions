#include<iostream>
using namespace std;

int main() {

    int t;
    string s;
    cin>>t;
    while(t--) {
        cin>>s;
        int arr[1001];
        int brr[1001];
        int n = s.size();
        int zeros = 0;
        int ones = 0;
        for(int i = 0; i < s.size(); i++) {
            zeros += (s[i] =='0');
            ones += (s[i] =='1');
            arr[i] = zeros;
            brr[i] = ones;
        }
        int res = min(n-zeros, n-ones);
        for(int i=0; i<n; i++) {
            ///000000011111111
            int x = (brr[i]+arr[n-1]-arr[i]);
            ///1111111100000000
            int y = (arr[i]+brr[n-1]-brr[i]);
            res = min(res, min(x, y));
        }
        cout<<res<<endl;
    }
    return 0;
}

