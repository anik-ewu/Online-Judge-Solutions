#include<bits/stdc++.h>
using namespace std;

int main(){

        long long int ans, n, k;
        cin>>n>>k;
        ans=(k*(k+1))/2;
        if(ans<=n){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }

    return 0;
}

