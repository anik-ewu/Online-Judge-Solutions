///Topological sort

#include<bits/stdc++.h>
using namespace std;

#define what_is(x)      cerr<<#x<<" is "<<x<<"\n";
#define read(x)         freopen("in.txt","r",stdin);
#define write(x)        freopen("out.txt","w",stdout);
#define Fast            ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


int vis[30];
stack< int > st;
string  pre, now;
vector< int > adj[30];

void process(){

    for(int i=0; i<pre.size(); i++){
        if(i==now.size()){
            cout<<"Impossible"<<endl;
            exit(0);
        }
        if(pre[i]!=now[i]){
            int l=pre[i]-'a';
            int r=now[i]-'a';
            adj[l].push_back(r);
            return ;
        }
    }
}

void dfs(int u){
    vis[u]=1;
    for(auto x: adj[u]){
        if(vis[x]==0){
            dfs(x);
        }
        else if(vis[x]==1){
            cout<<"Impossible"<<endl;
            exit(0);
        }
    }
    vis[u]=2;
    st.push(u);
}

int main(){
    Fast;///using Fast I/O
    
    read(x); write(x);

    int n;
    cin>>n;
    cin>>pre;
    for(int i=1; i<n; i++){
        cin>>now;
        process();
        pre=now;
    }

    for(int i=0;  i<26; i++){
        if(vis[i]==0){
            dfs(i);
        }
    }

    while(!st.empty()){
        cout<<char(st.top()+'a');
        st.pop();
    }
    cout<<endl;


    

    return 0;
}

