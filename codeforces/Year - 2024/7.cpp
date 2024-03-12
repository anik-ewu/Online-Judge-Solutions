#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const ll           inf = 1e9;
#define read(x)     freopen("in.txt","r",stdin);
#define write(x)    freopen("out.txt","w",stdout);
#define what_is(x)  cerr<<#x<<" is "<<x<<"\n";
#define Fast        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N= 1e5+5;

int main(){

    int a, b, t=1, n , m;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int>arr(n, 0);
        
        for (int i = 0; i < n; i++) {
            cin>>arr[i];
        }

        bool possibleToMakeZero = true;

        for (int i = 1; i < n - 1; i++) {
            int left = arr[i - 1];
            int middle = arr[i];
            int right = arr[i + 1];

            if (left * 2 > arr[i] || right < left) {
                possibleToMakeZero = false;
                break;
            }
            arr[i - 1] = 0;
            arr[i] = arr[i] - (left * 2);
            arr[i + 1] = right - left;
        } 
        
        if (arr[n - 1] || arr[n - 2]) {
            possibleToMakeZero = false;
        }

        possibleToMakeZero ? cout<<"YES"<<endl : cout<<"NO"<<endl;

    }

    return 0;
}
