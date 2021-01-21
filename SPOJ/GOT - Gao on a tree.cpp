///Date     : 24-09-2020
///Problem  : SPOJ GOT - Gao on a tree
///Approach : MOs on tree ( path query )

/*Steps     : Flatten the tree, Find LCA and Sort queries to apply mo( also swap u, v if st[v]<st[v] )
  Notes     : There are two cases, Case 1: u=LCA(u, v) then range st[u] to st[v],
              Case2: u!=LCA(u, v) then range ed[u] to st[v] + (st[p] to st[p]
*/

#include<bits/stdc++.h>
using namespace std;
#define mx 300002
#define pb push_back

//------For LCA--------
int L[mx]; ///লেভেল
int P[mx][25]; ///স্পার্স টেবিল
int T[mx]; ///প্যারেন্ট
//-----------------

const int len=205;
int st[mx], ed[mx];
int fre[mx], vis[mx];
int arr[mx], ans[mx];
map < int , int > mp;
vector<int>adj[mx], euler;

struct query{
    int l, r, id, lc, c;
}q[mx];

bool cmp(query &a, query &b){
    if(a.l/len!=b.l/len)
        return a.l/len<b.l/len;
    return (a.l/len & 1) ? a.r<b.r : a.r>b.r;///time optimization
}

void dfs(int from,int u,int dep){
    euler.push_back(u);
    st[u]=euler.size()-1;
    T[u]=from;
    L[u]=dep;
    for(int i=0;i<(int)adj[u].size();i++){
        int v=adj[u][i];
        if(v==from) continue;
        dfs(u,v,dep+1);
    }
    euler.push_back(u);
    ed[u]=euler.size()-1;
}

int lca_query(int p, int q){
    int tmp, log, i;
    if (L[p] < L[q])tmp = p, p = q, q = tmp;
    log=1;
    while(1){
        int next=log+1;
        if((1<<next)>L[p])
            break;
        log++;
    }
    for (i = log; i >= 0; i--)
        if (L[p] - (1 << i) >= L[q])
            p = P[p][i];
    if (p == q)
        return p;
    for (i = log; i >= 0; i--)
        if (P[p][i] != -1 && P[p][i] != P[q][i])
            p = P[p][i], q = P[q][i];
    return T[p];
}

void lca_init(int N){
      memset (P,-1,sizeof(P)); //শুরুতে সবগুলো ঘরে -১ থাকবে
      int i, j;
       for (i = 0; i < N; i++)
          P[i][0] = T[i];

      for (j = 1; 1 << j < N; j++)
         for (i = 0; i < N; i++)
             if (P[i][j - 1] != -1)
                 P[i][j] = P[P[i][j - 1]][j - 1];
}

void update(int v){
   if(vis[v])fre[arr[v]]--;
   else fre[arr[v]]++;
   vis[v]^=1;
}


int main(){

    int u,v,t, n, m;
    while(scanf("%d%d",&n,&m)==2){

        for(int i=0; i<n; i++){
            scanf("%d",&arr[i]);
        }
        for(int i=0; i<n; i++){
            adj[i].clear();
        }
        for(int i=0; i<n-1; i++){
            scanf("%d%d",&u, &v);
            u--;v--;///making a 0 based tree
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        //Compressing vertex color
        int cnt=1;
        mp.clear();
        for(int i=0; i<n; i++){
            if(mp.find(arr[i])==mp.end()){
                mp[arr[i]]=cnt++;
            }
            arr[i]=mp[arr[i]];
        }

        euler.clear();
        dfs(-1 , 0, 0);

        lca_init(n);

        for(int i=0; i<m; i++){
            scanf("%d%d%d",&u,&v, &q[i].c);
            u--;v--;
            if(st[u]>st[v])swap(u,v);
            int p=lca_query(u,v);

            q[i].lc=p;
            q[i].id=i;

            if(p==u){
                q[i].l=st[u];
                q[i].r=st[v];
            }
            else{
                q[i].l=ed[u];
                q[i].r=st[v];
            }
        }
        sort(q, q+m, cmp);///sort query

        memset(vis,0,sizeof(vis));
        memset(fre,0,sizeof(fre));

        int l=0,  r=-1;
        for(int i=0; i<m; i++){
            while(l>q[i].l)update(euler[(--l)]);
            while(r<q[i].r)update(euler[(++r)]);
            while(l<q[i].l)update(euler[(l++)]);
            while(r>q[i].r)update(euler[(r--)]);

            u=euler[l];
            v=euler[r];
            ///for case 2
            if(q[i].lc!=u && q[i].lc!=v)update(q[i].lc);
                if(mp.find(q[i].c)==mp.end())
                    ans[q[i].id]=0;
                else
                    ans[q[i].id]=fre[mp[q[i].c]];
            if(q[i].lc!=u && q[i].lc!=v)update(q[i].lc);

        }
        for(int i=0; i<m; i++){
            if(ans[i])printf("Find\n");
            if(!ans[i])printf("NotFind\n");

        }
        printf("\n");
     }

    return 0;
}
