#include<bits/stdc++.h>
using namespace std;
#define read(x)     freopen("in.txt","r",stdin);
#define write(x)    freopen("out.txt","w",stdout);
#define what_is(x)  cerr<<#x<<" is "<<x<<"\n";
#define Fast        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve() {
    int n, k;
    cin>>n>>k;
    vector<int>arr(n, 0);
    int segment = (n - 1) / k;

    arr[0] = 1;
    arr[1] = n - segment;

    for (int i = k; i < n; i += 2) {
        arr[i] = arr[i - k] + 1;
        if (i + 1 < n) {
            arr[i + 1] = arr[i - k + 1] - 1;
        }
    }

    for (int i = 0; i < n; i++) {
        cout<<arr[i]<<' ';
    }

    cout<<endl;
}

int main(){

    Fast;
    int t;
    cin>>t;
    for (int i = 1; i <= t; i++) {
        solve();
    }

    return 0;
}


//1 10 3 8 2 9 4 7 3 8  