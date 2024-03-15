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
        if (n % 2) {
            cout<<"No"<<endl;
        }
        else {
            cout<<"Yes"<<endl;
            for (int i = 0; i < n; i+=2) {
                cout<<"AA";
                if (i + 2 < n) {
                    cout<<"BB";
                    i += 2;
                }
            }
            cout<<endl;
        }

    }

    return 0;
}
