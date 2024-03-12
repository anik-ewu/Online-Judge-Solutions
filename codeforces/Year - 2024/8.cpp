#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const ll           inf = 1e9;
#define read(x)     freopen("in.txt","r",stdin);
#define write(x)    freopen("out.txt","w",stdout);
#define what_is(x)  cerr<<#x<<" is "<<x<<"\n";
#define Fast        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N= 1e5+5;

int minCharNeedToRemove(int n, string& s) {
    
    int countChar = 0; 

    for (int i = 0; i < n - 2; i++) {
        int increment = 0;
        if (s[i] == 'm' && s[i + 1] == 'a' && s[i + 2] == 'p') {
            countChar++;
            increment = 2;
        }
        else if (s[i] == 'p' && s[i + 1] == 'i' && s[i + 2] == 'e') {
            countChar++;
            increment = 2;
        }
        i += increment;
    }
    return countChar;
}

int main(){

    Fast;
    string s;
    int a, b, t=1, n , m;
    cin>>t;
    while(t--){

        cin>>n>>s;
        cout<<minCharNeedToRemove(n, s)<<endl;
    }

    return 0;
}
