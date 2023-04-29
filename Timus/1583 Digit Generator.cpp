#include <bits/stdc++.h>

using namespace std;

#define what_is(x)  cerr<<#x<<" is "<<x<<"\n";

int sum_of_digits(int n)
{
    int sum=0;
    while(n>=1){
        sum+=n%10;
        n/=10;
    }
    return sum;
}
int main()
{
    int n,i,sum=0,cnt=0,t;
    int mx = 0;
    cin>>t;
    while(t--){
        cin>>n;
        for(i=n-60,cnt=0;i<=n;i++){
            sum=i+sum_of_digits(i);
            if(sum==n){
                mx = max(mx,n-i);
                cout<<i<<endl;

                break;
            }
            else
                cnt++;
        }
        if(cnt==61)
            cout<<"0"<<endl;

    }
    what_is(mx);
    return 0;
}
