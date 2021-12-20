#include<bits/stdc++.h>
using namespace std;


int main(){

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int a, b;
    vector< int > v(4,0);
    cin>>a>>b;
    for(int i=1; i<=6; i++){
        int x=abs(i-a);
        int y=abs(i-b);
        if(x<y)v[0]++;
        else if(x==y)v[1]++;
        else if(x>y)v[2]++;
    }

    for(int i=0; i<3; i++)
        cout<<v[i]<<' ';
    cout<<endl;



    return 0;
}
