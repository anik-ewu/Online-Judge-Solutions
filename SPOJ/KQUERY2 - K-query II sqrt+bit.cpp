///Date     : 18-09-2020
///Approach : sqrt decomposition + bit

#include<bits/stdc++.h>
using namespace std;

int len=500;
int arr[30005];
int bit[65][10005];

void update(int blk, int x, int c){
    while(x>0){
        bit[blk][x]+=c;
        x-=x&-x;
    }
}

int query(int blk, int x){
    int ret=0;
    while(x<=10000){
        ret+=bit[blk][x];
        x+=x&-x;
    }
    return ret;
}

int f(int l, int r, int k){
    int cnt=0;
    int cl=l/len;
    int cr=r/len;
    if(cl==cr){
        for(int i=l; i<=r; i++){
            if(arr[i]>k)cnt++;
        }
    }
    else{
        for(int i=l; i<(cl+1)*len; i++){
            if(arr[i]>k)cnt++;
        }
        for(int i=cl+1; i<cr; i++){
            cnt+=query(i, k+1);
        }
        for(int i=cr*len; i<=r; i++){
            if(arr[i]>k)cnt++;
        }
    }
    return cnt;
}

int main(){

    ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);

    int n, q, l, r, t, val, id, k;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        update(i/len, arr[i], 1);
    }
    cin>>q;
    while(q--){
        cin>>t;
        if(t){
           cin>>l>>r>>k;
           l--;r--;
           cout<<f(l,r,k)<<endl;
        }
        else{
            cin>>id>>val;id--;
            update(id/len, arr[id], -1);
            arr[id]=val;
            update(id/len, arr[id], 1);
        }
    }
    return 0;
}
