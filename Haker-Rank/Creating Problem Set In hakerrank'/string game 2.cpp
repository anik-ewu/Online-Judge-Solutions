#include<bits/stdc++.h>
using namespace std;

int cal(int x, int y){
    if(x>y){
        swap(x,y);
    }
    return min(y-x,26-(y-x));
}

int main(){

    freopen("input07.txt","r",stdin);
    string s;
    cin>>s;
    int ans=s.size()*260;
    for(char i='a'; i<='z'; i++){
        int temp=0;
        for(int j=0; j<s.size(); j++){
            if(s[j]==i){
                continue;
            }
            else{
                temp+=cal(i,s[j]);
            }
        }
        ans=min(ans,temp);
    }
    cout<<ans<<endl;

    return 0;
}

