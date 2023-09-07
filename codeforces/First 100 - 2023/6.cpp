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

    int t, n, a, b, l, r;
    cin>>t;
    while (t--) {
        cin>>l>>r;
        
        for (int i = 2; i <= 3; i++) {
            int x = i;
            int y = l - i;

            if (x + y >= l && x + y <= r && y > 0) {
                int GCD = __gcd(a, b);
                if (GCD != 1) {
                    a = x;
                    b = y;
                    break;
                }
            }
        }

        for (int i = 2; i <= 3; i++) {
            a = i;
            b = l - i;

            if (a + b >= l && a + b <= r && b > 0) {
                int GCD = __gcd(a, b);
                if (GCD != 1) {
                    break;
                }
            }
        }





    }

    return 0;
}