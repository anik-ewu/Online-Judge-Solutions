#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const ll           inf = 1e9;
#define read(x)     freopen("in.txt","r",stdin);
#define write(x)    freopen("out.txt","w",stdout);
#define what_is(x)  cerr<<#x<<" is "<<x<<"\n";
#define Fast        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N= 1e5+5;

int res = INT_MAX;
int arr[21];

void minDifference(int pos, int n, int sum, int total) {

    if(pos > n) {
        int sum2 = total - sum;
        int diff = abs(sum2-sum);
        res = min(res, diff);
        return;
    }

    minDifference(pos+1, n, sum+arr[pos], total);
    minDifference(pos+1, n, sum, total);

}

int main(){

    int a, b, t=1, n , m, total = 0;
    cin>>n;

    for(int i=1; i<=n; i++) {
        cin>>arr[i];
        total += arr[i];
    }

    minDifference(1, n, 0, total);

    cout<<res<<endl;

    return 0;
}

