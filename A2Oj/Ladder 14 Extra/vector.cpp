#include<bits/stdc++.h>
using namespace std;

int arr[10];
vector< int >brr;

int main(){

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int t, a, b, n, m;

    for(int i=1; i<=10; i++){
        arr[i]=i;
        brr.push_back(i);
    }

    for(int i=1; i<10; i++){
        cout<<brr[i]<<' ';
    }
    cout<<endl;

    for(int i=0; i<9; i++){
        cout<<brr[i]<<' ';
    }




    return 0;
}