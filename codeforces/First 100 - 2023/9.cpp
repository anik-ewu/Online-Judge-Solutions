#include<bits/stdc++.h>
using namespace std;

const int N= 1e5+5;


int main(){

    int t, n, m, q, a, b, c;
    cin>>t;
    while (t--) {
        cin>>n>>m;
        for (int i = 0; i < m; i++) {
            for (int j = i; j >= 0; j--) {
                cout<<i <<' '<<j<<' '<<i + j<<endl;
            }
            cout<<"---------------------------"<<endl;
        }
    }

    return 0;
}