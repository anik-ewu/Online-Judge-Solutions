#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const ll           inf = 1e9;
#define read(x)     freopen("in.txt","r",stdin);
#define write(x)    freopen("out.txt","w",stdout);
#define what_is(x)  cerr<<#x<<" is "<<x<<"\n";
#define Fast        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N= 1e5+5;

int mark[38];

int digitSum(int val) {
    int sum = 0;
    while(val) {
        sum += val%10;
        val /= 10;
    }
    return sum;
}


int main(){

    int n;

    cin>>n;

    int end = 1;
    for(int i=1; i<=n/2; i++)
        end = end*10;

    for(int i=0; i<end; i++) {
        mark[digitSum(i)]++;
    }

    int cnt = 0;
    for(int i=0; i<end; i++) {
       cnt += mark[digitSum(i)];
    }

    cout<<cnt<<endl;

    return 0;
}

