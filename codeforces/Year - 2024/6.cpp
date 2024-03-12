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

    Fast;

    int a, b, t=1, n , m, k;
    cin>>t;
    while(t--){1

        cin>>n>>m>>k;
        
        vector<int>arr;
        vector<int>brr;

        for (int i = 0; i < n; i++) {
            cin>>a;
            arr.push_back(a);
        }
        
        for (int i = 0; i < m; i++) {
            cin>>a;
            brr.push_back(a);
        }
        
        sort(arr.begin(), arr.end());
        sort(brr.begin(), brr.end());
        reverse(brr.begin(), brr.end());

        int total = 0;
        int j = 0;
        for (int i = 0; i < n; i++) {
            while(j < m && arr[i] + brr[j] > k) {
                j++;
            }
            total += m - j;
        }
        
        cout<<total<<endl;
    }

    return 0;
}