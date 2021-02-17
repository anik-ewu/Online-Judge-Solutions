#include<bits/stdc++.h>
using namespace std;

vector < string > vs;
map< int, string > mp;

string get_res(int n){

    int tot=vs.size();
    for(int i=0; i<tot; i++){
        string s=vs[i];
        int len=s.size();
        int num=s[0]-'0';
        for(int j=1; j<len; j++){
            num=(num*10)+(s[j]-'0');
            num=num%n;
        }
        num=num%n;
        if(num==0)return s;
    }
    return " ";
}

void precal(){

    for(int i=1; i<=10000; i++){
        int j=i;
        string s="";
        while(j){
            if(j%2==0){
                s+='0';
            }
            else{
                s+='9';
            }
            j/=2;
        }
        reverse(s.begin(), s.end());
        vs.push_back(s);
    }
    for(int i=1; i<=500; i++){
        mp[i]=get_res(i);
    }
}

int main(){

    int n, t;
    precal();
    cin>>t;
    while(t--){
        cin>>n;
        cout<<mp[n]<<endl;
    }

    return 0;
}
