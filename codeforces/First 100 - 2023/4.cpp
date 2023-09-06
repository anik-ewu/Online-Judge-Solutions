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

    int t, n, a, b;
    cin>>t;
    while (t--) {
        
        cin>>n;
        int mul = 1;
        vector<int>res;
        while(n) {
            int rem = n % 10;
            if (rem) {
                res.push_back(rem * mul);
            }
            n /= 10;
            mul = mul * 10;
        }
        cout<<res.size()<<endl;
        for (int val: res) {
            cout<<val<<' ';
        }
        cout<<endl;
    }

    return 0;
}