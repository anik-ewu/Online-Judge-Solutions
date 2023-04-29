///Topic: BFS + BinarySearch
///Problem : abc257
#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const ll           inf = 1e9;
#define read(x)     freopen("in.txt","r",stdin);
#define write(x)    freopen("out.txt","w",stdout);
#define what_is(x)  cerr<<#x<<" is "<<x<<"\n";
#define Fast        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N= 1e5+5;
vector< vector<int> > vv;

bool check(int m, int n) {

    for(int i = 0; i < n; i++) {

        queue<int>q;
        bool vis[n+2];
        memset(vis, false, sizeof(vis));

        int total = 1;
        q.push(i);
        vis[i] = true;

        while(!q.empty()) {
            int u = q.front();
            q.pop();

            for(int j = 0; j < n; j++) {
                if(vis[j])
                    continue;

                int dist  = abs(vv[u][0]-vv[j][0])+abs(vv[u][1]-vv[j][1]);
                int range = m*vv[u][2];

                if(range >= dist) {
                    q.push(j);
                    vis[j] = true;
                    total++;
                }
            }
        }
        if(total == n)
            return true;
    }
    return false;
}

int main(){

    read(x);

    int a, b, p, t=1, n , m;
    cin>>n;

    for(int i = 0; i < n; i++) {
        cin>>a>>b>>p;
        vector < int > v;
        v.push_back(a);
        v.push_back(b);
        v.push_back(p);
        vv.push_back(v);
    }

    int lo = 0;
    int hi = 1e10;
    int res = 0;

    while(lo <= hi) {
        int mid = (lo+hi)/2;

        if(check(mid, n)) {
            hi = mid-1;
            res = mid;
        } else {
            lo = mid+1;
        }
    }

    cout<<res<<endl;

    return 0;
}
