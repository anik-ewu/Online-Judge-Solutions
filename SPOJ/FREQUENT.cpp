///Spoj : FREQUENT
///Approach : MOs Algorithm
#include <bits/stdc++.h>
#define sz 200015
using namespace std;
typedef long long ll;
int n,q,mx;
struct queries{
    int l, r, ind;
}qa[sz];
int bucket_size;
int bucket_no[sz];
int ans[sz],arr[sz];
int fre[sz],ffre[sz];
bool cmp(queries a, queries b){
    if(bucket_no[a.l]==bucket_no[b.l]){
        if(a.r==b.r) return a.l<b.l;
        if(!(bucket_no[a.l]%2)) return a.r<b.r;
        return a.r>b.r;
    }
    return bucket_no[a.l]<bucket_no[b.l];
}
void add(int pos){
    int a=arr[pos];
    fre[a]++;
    ffre[fre[a]]++;
    mx=max(mx,fre[a]);
}
void del(int  pos){
    int a=arr[pos];
    int b=fre[a];
    fre[a]--;
    ffre[b]--;
    if(ffre[b]==0)
        mx=fre[a];
}
inline void brute(int l, int r){
    for(int i=l; i<=r; i++) add(i);
}
inline void mo(){
    bucket_size=350;
    int bno=0, bcnt=0;
    for(int i=0; i<=n; i++){
        if(bcnt==bucket_size){
            bno++;
            bcnt=0;
        }
        bucket_no[i]=bno;
        bcnt++;
    }
    sort(qa, qa+q, cmp);
    mx=0;
    brute(qa[0].l, qa[0].r);///add first query manually
    ans[qa[0].ind]=mx;
    int l,r;
    for(int i=1; i<q; i++){
        l=qa[i-1].l;
        r=qa[i-1].r;
        while(l>qa[i].l)add(--l);
        while(r<qa[i].r)add(++r);
        while(l<qa[i].l)del(l++);
        while(r>qa[i].r)del(r--);
        ans[qa[i].ind]=mx;
    }
}
int main(){

    while(scanf("%d",&n) && n){
        scanf("%d",&q);
        for(int i=0; i<n; i++){
            scanf("%d", &arr[i]);
            arr[i]+=100000;///handling negative values
            fre[arr[i]]=0;ffre[i]=0;
        }
        for(int i=0; i<q; i++){
            scanf("%d %d", &qa[i].l, &qa[i].r);
            qa[i].l--;qa[i].r--;///0 base indexing
            qa[i].ind=i;
        }
        mo();
        for(int i=0; i<q; i++){
            printf("%d\n", ans[i]);
        }
    }
    return 0;
}
