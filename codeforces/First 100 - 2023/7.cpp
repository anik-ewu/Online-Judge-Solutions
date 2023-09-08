#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const ll           inf = 1e9;
#define read(x)     freopen("in.txt","r",stdin);
#define write(x)    freopen("out.txt","w",stdout);
#define what_is(x)  cerr<<#x<<" is "<<x<<"\n";
#define Fast        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N= 1e5+5;
int arr[N];
string s;

void solve(int q, int n) {

    int pre0[n + 1];
    int pre1[n + 1];
    memset(pre0, 0, sizeof(pre0));
    memset(pre1, 0, sizeof(pre1));
    
    for (int i = 1; i <= n; i++) {
        pre0[i] = pre0[i - 1] ^ (s[i - 1] == '0' ? arr[i] : 0);
        pre1[i] = pre1[i - 1] ^ (s[i - 1] == '1' ? arr[i] : 0);
    }

    int g, l, r, key;
    int xor0 = pre0[n];
    int xor1 = pre1[n];

    while(q--) {
        cin>>key;
        if (key == 1) {
            cin>>l>>r;
            int x = pre0[r] ^ pre0[l - 1];
            int y = pre1[r] ^ pre1[l - 1];

            xor0 ^= x;
            xor1 ^= y;
            xor0 ^= y;
            xor1 ^= x;
        }
        else {
            cin>>g;
            cout<<(g == 0 ? xor0 : xor1)<<' ';
        }
    }
    cout<<endl;
}

int main(){

    int t, n, q;
    cin>>t;
    while (t--) {

        cin>>n;
        for (int i = 1; i <= n; i++) {
            cin>>arr[i];
        }
        cin>>s;
        cin>>q;

        solve(q, n);
    }

    return 0;
}