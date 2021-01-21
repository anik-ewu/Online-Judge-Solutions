#include<bits/stdc++.h>
using namespace std;

int main(){

    freopen("out.txt","w",stdout);
    srand(time(0));
    int id=0;
    int len=5000;
    for(int i=0; i<len; i++){
        id=(rand())%26;
        cout<<char('a'+id);
    }

    return 0;
}


