/*
Date: 10 April 2022
Algo: BFS
Author: Sabbir Hasan Anik
*/

#include<bits/stdc++.h>
using namespace std;

const int mx = 32768;
int arr[mx+5];

int bfs(int val) {

    queue< int > q;
    bool vis[mx + 5];
    memset(vis, 0, sizeof(vis));
    int cost[mx + 5];
    memset(cost, 0, sizeof(cost));

    q.push(val);
    vis[val] = 1;
    cost[val] = 0;
    if(val == 0)
        return 0;

    while(!q.empty()) {
        int u = q.front();
        q.pop();
        if(u == 0)
            return cost[u];

        int x = (u + 1) % mx;
        int y = (u * 2) % mx;

        if(vis[x] == 0) {
            q.push(x);
            vis[x] = 1;
            cost[x] = cost[u]+1;
        }
        if(vis[y] == 0) {
            q.push(y);
            vis[y] = 1;
            cost[y] = cost[u]+1;
        }
    }
}

int main() {

    int n, a;

    cin>>n;
    for(int i = 1; i <= n; i++) {
        cin>>a;
        cout<<bfs(a)<<' ';
    }

    return 0;
}
