/*
Date: 9-April-2021
Tags: Classical Segment Tree / Range Query
Notes: For getting 2 max values in the range: get the first max value and its index. Then update
that index with negative value then query again and finally update the negative value with the original one.
*/

#include<bits/stdc++.h>
using namespace std;
#define Fast   ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int      N =1e5+5;

int L, R;
int arr[N];
struct st{
    int val;
    int id;
}tree[4*N];

void build(int at, int l, int r){

    if(l==r){
        tree[at]={arr[l], l};
        return;
    }
    int mid=(l+r)/2;
    build(at*2, l, mid);
    build(at*2+1, mid+1, r);
    if(tree[at*2].val>=tree[at*2+1].val)
        tree[at]=tree[at*2];
    else
        tree[at]=tree[at*2+1];
}

void update(int at, int l, int r, int idx){

    if(l==r){
        tree[at]={arr[l], l};
        return;
    }
    int mid=(l+r)/2;
    if(idx<=mid)update(at*2, l, mid, idx);
    else update(at*2+1, mid+1, r, idx);
    if(tree[at*2].val>=tree[at*2+1].val)
        tree[at]=tree[at*2];
    else
        tree[at]=tree[at*2+1];
}


struct st query(int at, int l, int r){
    if(R<l || r<L)return {-N,0};
    if(L<=l and r<=R)return tree[at];
    int mid=(l+r)/2;
    struct st x=query(at*2, l, mid);
    struct st y=query(at*2+1, mid+1, r);
    if(x.val>=y.val)return x;
    else return y;
}

int main(){

    Fast;
    //read(x);
    //write(x);
    char ch;
    int n, t, q, id;
    cin>>n;
    for(int i=1; i<=n; i++)cin>>arr[i];
    build(1, 1, n);
    cin>>q;
    while(q--){
        cin>>ch;
        if(ch=='U'){
            cin>>id;
            cin>>arr[id];
            update(1, 1, n, id);
        }
        else{
            cin>>L>>R;
            st x=query(1, 1, n);
            arr[x.id]=-N;
            update(1, 1, n, x.id);
            st y=query(1, 1, n);
            arr[x.id]=x.val;
            update(1, 1, n, x.id);

            cout<<x.val+y.val<<endl;

            }
    }
    return 0;
}
