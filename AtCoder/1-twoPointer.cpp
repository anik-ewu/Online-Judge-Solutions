///Author : Sabbir Hasan Anik
///Algo   : Two Pointer
///Atcoder: abc257_d

#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const ll           inf = 1e9;
#define read(x)     freopen("in.txt","r",stdin);
#define write(x)    freopen("out.txt","w",stdout);
#define what_is(x)  cerr<<#x<<" is "<<x<<"\n";
#define Fast        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 2e5+5;

int arr[N];

int main(){

//    read(x);

    string s;
    int a, b, t=1, n , m;
    //cin>>t;
    while(t--){

        cin>>n>>s;

        int child = 0;
        int adult = 0;
        vector < int > ch, ad;

        for(int i = 0; i < n;  i++) {
            cin>>arr[i];
            child += s[i]=='0';
            adult += s[i]=='1';

            if(s[i]=='0') {
                ch.push_back(arr[i]);
            } else {
                ad.push_back(arr[i]);
            }
        }

//        cout<<child<<' '<<adult<<endl;

        int res = max(child, adult);

        sort(ch.begin(), ch.end());
        sort(ad.begin(), ad.end());

        int i = 0;
        int j = 0;

        for(int j = 0; j < ad.size(); j++) {
            while(i< ch.size() && ch[i] < ad[j])
                i++;
            res = max(res, i+adult-j);

        }
        cout<<res<<endl;

    }

    return 0;
}

