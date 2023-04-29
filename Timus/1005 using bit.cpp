#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const ll           inf = 1e9;
#define read(x)     freopen("in.txt","r",stdin);
#define write(x)    freopen("out.txt","w",stdout);
#define what_is(x)  cerr<<#x<<" is "<<x<<"\n";
#define Fast        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N= 1e5+5;

int arr[21];

int minDifference(int n, int total) {

    int res = total;

    for(int i = 0; i<(1<<n); i++) {
        int sum = 0;
        for(int j = 0; j<n; j++) {
            if(i & (1<<j)) {
                sum += arr[j+1];
            }
        }
        int sum2 = total - sum;
        int diff = abs(sum2 - sum);
        res = min(res, diff);
    }


    return res;
}

int main(){

    int a, b, t=1, n , m, total = 0;
    cin>>n;

    for(int i=1; i<=n; i++) {
        cin>>arr[i];
        total += arr[i];
    }

    cout<<minDifference(n, total)<<endl;

    return 0;
}
