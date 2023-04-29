#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const ll           inf = 1e9;
#define read(x)     freopen("in.txt","r",stdin);
#define write(x)    freopen("out.txt","w",stdout);
#define what_is(x)  cerr<<#x<<" is "<<x<<"\n";
#define Fast        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N= 1e5+5;

int arr[10];

void findResult(int n) {

    if(n == 1) {
        cout<<1<<endl;
        return;
    }
    if(n == 0) {
        cout<<10<<endl;
        return;
    }

    vector<int> v;

   for(int i = 9; i>=2; i--) {
        while(n%i == 0) {
            v.push_back(i);
            n /= i;
        }
   }
   if(n != 1) {
        cout<<-1<<endl;
   } else {
        for(int i = v.size()-1; i>=0; i--) {
            cout<<v[i];
        }
        cout<<endl;
   }
}

int main(){

    int a, b, t=1, n , m;

    cin>>n;

    findResult(n);


    return 0;
}

