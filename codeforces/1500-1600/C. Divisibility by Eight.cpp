///bruteforce - 3d nested loop
///9-3-2021

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e9;

#define all(x)          (x).begin(), (x).end()
#define read(x)         freopen("in.txt","r",stdin);
#define write(x)        freopen("out.txt","w",stdout);
#define what_is(x)      cerr<<#x<<" is "<<x<<"\n";
#define Fast            ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define mod             1e9+7
#define sz              3000005

bool check(int n){
    return n%8==0;
}
void print(int n){
    cout<<"YES"<<endl;
    cout<<n<<endl;
    exit(0);
}

void solve(){

    int a,b, n,m, i,j,k,num;
    string s;
    cin>>s;
    n=s.size();
    for(i=0; i<n; i++){
        num=s[i]-'0';
        if(check(num))print(num);
        for(j=i+1; j<n; j++){
            int temp=num*10 +(s[j]-'0');
            if(check(temp))print(temp);
            for(k=j+1; k<n; k++){
                int temp2=temp*10 + (s[k]-'0');
                if(check(temp2))print(temp2);
            }
        }
    }
    cout<<"NO"<<endl;

}

int main(){
    Fast;///using Fast I/O
    
    read(x); write(x);
    solve();

    return 0;
}

