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

        cin>>a>>b;
        cout<<(a % b == 0 ? 0 : b - (a % b))<<endl;
    }

    return 0;
}