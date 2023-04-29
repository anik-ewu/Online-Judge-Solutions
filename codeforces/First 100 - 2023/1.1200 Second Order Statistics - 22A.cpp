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

    int t, n, a;
    cin>>t;
    while (t--) {

        cin>>n;
        vector<int>arr(n);
        set<int>initial_set;

        for (int i = 0; i < n; i++) {
            cin>>a;
            initial_set.insert(a);
        }

        int res = -1;
        for (int i = 1; i < 1024;  i++) {
            set<int>modified_set;
            for (int val: initial_set) {
                int x = val ^ i;
                modified_set.insert(x);
            }
            if (modified_set == initial_set) {
                res = i;
                break;
            }
        }

        cout<<res<<endl;
    }

    return 0;
}