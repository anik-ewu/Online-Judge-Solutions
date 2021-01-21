///Date: 19-9-2020
///Approach: Mo's algorithm

#include<bits/stdtr1c++.h>
using namespace std;
#define sz 30005
const int len= 180;

int cnt;
int arr[sz];
int ans[200005];
int freq[1000006];

struct query{
    int l, r, id;
}q[200005];


bool cmp(query &a, query &b){
    if(a.l/len!=b.l/len)
        return a.l/len<b.l/len;
    return (a.l/len & 1) ? a.r<b.r : a.r>b.r;
}

void add(int i){
    if(freq[arr[i]]==0)cnt++;
    freq[arr[i]]++;
}

void del(int i){
    if(freq[arr[i]]==1)cnt--;
    freq[arr[i]]--;
}

int main(){

    int n,m,i;
    scanf("%d",&n);
    for(i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }

    scanf("%d",&m);
    for(i=1; i<=m; i++){
        scanf("%d%d",&q[i].l,&q[i].r);
        q[i].id=i;
        q[i].l--;
        q[i].r--;
    }
    sort(q+1,q+m+1,cmp);///sort query

    int l=0,  r=-1;
    for(i=1; i<=m; i++){
        while(l>q[i].l)add(--l);
        while(r<q[i].r)add(++r);
        while(l<q[i].l)del(l++);
        while(r>q[i].r)del(r--);
        ans[q[i].id]=cnt;
    }
    for(i=1; i<=m; i++){
        printf("%d\n",ans[i]);
    }

    return 0;
}
